//
//  ZBObject.m
//  OptimusPrime
//
//  Created by bigfish on 2019/8/8.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "ZBObject.h"
#import "ZBReflection.h"
#import "ZBEXTRuntimeExtensions.h"
#import "NSError+ZBModelException.h"

// 用于缓存在+propertyKeys中执行的反射.
static void *ZBObjectCachedPropertyKeysKey = &ZBObjectCachedPropertyKeysKey;


/**
 验证对象的值，并在必要时设置它

 @param obj 正在验证值的对象。这个值不能为空
 @param key  obj属性的名称。这个值不能是空。
 @param value key标识的属性的新值
 @param forceUpdate 如果设置为“YES”，即使验证值没有更改，值也会被更新
 @param error 如果不为空，则可以将其设置为验证期间发生的任何错误
 @return 如果可以验证和设置“value”，返回YES;如果发生错误，返回NO
 */
static BOOL ZBValidateAndSetValue(id obj, NSString *key, id value, BOOL forceUpdate, NSError **error) {
    // 标记为自动释放，因为validateValue可能会返回
    // 在这个变量中存储一个新对象(我们不希望ARC这样做)
    // double-free or leak the old or new values).
    __autoreleasing id validatedValue = value;
    
    @try {
        if (![obj validateValue:&validatedValue forKey:key error:error]) return NO;
        
        if (forceUpdate || value != validatedValue) {
            [obj setValue:validatedValue forKey:key];
        }
        
        return YES;
    } @catch (NSException *ex) {
        NSLog(@"*** Caught exception setting key \"%@\" : %@", key, ex);
        
        // Fail fast in Debug builds.
#if DEBUG
        @throw ex;
#else
        if (error != NULL) {
            *error = [NSError zb_modelErrorWithException:ex];
        }
        
        return NO;
#endif
    }
}

@implementation ZBObject

/// 将 JSON (NSData,NSString,NSDictionary) 转换为 Model
+ (instancetype)modelWithJSON:(id)json { return [self yy_modelWithJSON:json]; }

/// json-array 转 模型-数组
+ (NSArray *)modelArrayWithJSON:(id)json {
    return [NSArray yy_modelArrayWithClass:[self class] json:json];
}

/// 字典转模型
+ (instancetype)modelWithDictionary:(NSDictionary *)dictionary{
    return [self yy_modelWithDictionary:dictionary];
}

- (id)toJSONObject { return [self yy_modelToJSONObject]; }
- (NSData *)toJSONData { return [self yy_modelToJSONData]; }
- (NSString *)toJSONString { return [self yy_modelToJSONString]; }

/// Coding/Copying/hash/equal
- (void)encodeWithCoder:(NSCoder *)aCoder { [self yy_modelEncodeWithCoder:aCoder]; }
- (id)initWithCoder:(NSCoder *)aDecoder { return [self yy_modelInitWithCoder:aDecoder]; }
- (id)copyWithZone:(NSZone *)zone { return [self yy_modelCopy]; }
- (NSUInteger)hash { return [self yy_modelHash]; }
- (BOOL)isEqual:(id)object { return [self yy_modelIsEqual:object]; }

/// Properties optional
- (void)setValue:(id)value forUndefinedKey:(NSString *)key { }

/// desc
- (NSString *)description { return [self yy_modelDescription]; }





+ (NSSet *)propertyKeys {
    NSSet *cachedKeys = objc_getAssociatedObject(self, ZBObjectCachedPropertyKeysKey);
    if (cachedKeys != nil) return cachedKeys;
    
    NSMutableSet *keys = [NSMutableSet set];
    
    [self enumeratePropertiesUsingBlock:^(objc_property_t property, BOOL *stop) {
        zb_propertyAttributes *attributes = zb_copyPropertyAttributes(property);
        @onExit {
            free(attributes);
        };
        
        if (attributes->readonly && attributes->ivar == NULL) return;
        
        NSString *key = @(property_getName(property));
        [keys addObject:key];
    }];
    
    // It doesn't really matter if we replace another thread's work, since we do
    // it atomically and the result should be the same.
    objc_setAssociatedObject(self, ZBObjectCachedPropertyKeysKey, keys, OBJC_ASSOCIATION_COPY);
    
    return keys;
}

- (NSDictionary *)dictionaryValue {
    return [self dictionaryWithValuesForKeys:self.class.propertyKeys.allObjects];
}


#pragma mark Reflection
+ (void)enumeratePropertiesUsingBlock:(void (^)(objc_property_t property, BOOL *stop))block {
    Class cls = self;
    BOOL stop = NO;
    
    while (!stop && ![cls isEqual:ZBObject.class]) {
        unsigned count = 0;
        objc_property_t *properties = class_copyPropertyList(cls, &count);
        
        cls = cls.superclass;
        if (properties == NULL) continue;
        
        @onExit {
            free(properties);
        };
        
        for (unsigned i = 0; i < count; i++) {
            block(properties[i], &stop);
            if (stop) break;
        }
    }
}

#pragma mark Merging
- (void)mergeValueForKey:(NSString *)key fromModel:(ZBObject *)model {
    NSParameterAssert(key != nil);
    
    SEL selector = ZBSelectorWithCapitalizedKeyPattern("merge", key, "FromModel:");
    if (![self respondsToSelector:selector]) {
        if (model != nil) {
            [self setValue:[model valueForKey:key] forKey:key];
        }
        return;
    }
    
    NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:[self methodSignatureForSelector:selector]];
    invocation.target = self;
    invocation.selector = selector;
    
    [invocation setArgument:&model atIndex:2];
    [invocation invoke];
}

- (void)mergeValuesForKeysFromModel:(ZBObject *)model {
    NSSet *propertyKeys = model.class.propertyKeys;
    for (NSString *key in self.class.propertyKeys) {
        if (![propertyKeys containsObject:key]) continue;
        
        [self mergeValueForKey:key fromModel:model];
    }
}


#pragma mark Validation

- (BOOL)validate:(NSError **)error {
    for (NSString *key in self.class.propertyKeys) {
        id value = [self valueForKey:key];
        BOOL success = ZBValidateAndSetValue(self, key, value, NO, error);
        if (!success) return NO;
    }
    return YES;
}

@end
