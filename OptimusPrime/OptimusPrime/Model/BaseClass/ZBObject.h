//
//  ZBObject.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/8.
//  Copyright © 2019 zzb. All rights reserved.
//  所有新建Model类的基类

#import <Foundation/Foundation.h>
#import <YYModel/YYModel.h>

@interface ZBObject : NSObject <YYModel,NSCopying,NSCoding>



// 所有propertyKeys存放到NSDictionarys中 with any nil values represented by NSNull，This property must never be nil.
@property (nonatomic, copy, readonly) NSDictionary *dictionaryValue;

// 将 Json (NSData，NSString，NSDictionary) 转换为 Model
+ (instancetype)modelWithJSON:(id)json;

// 字典转模型
+ (instancetype)modelWithDictionary:(NSDictionary *)dictionary;

// json数组 转换为 模型数组
+ (NSArray *)modelArrayWithJSON:(id)json;

// 返回所有@property声明的属性（除了只读属性），不包括ZBObject属性列表、成员变量
+ (NSSet *)propertyKeys;

// 将 Model 转换为 JSON 对象
- (id)toJSONObject;

// 将 Model 转换为 NSData
- (NSData *)toJSONData;

// 将 Model 转换为 JSONString
- (NSString *)toJSONString;

/**
 属性合并

 @param key 想要覆盖的key
 @param model 取值的model
 */
- (void)mergeValueForKey:(NSString *)key fromModel:(ZBObject *)model;

/**
 合并所有属性

 @param model 取值的model
 */
- (void)mergeValuesForKeysFromModel:(ZBObject *)model;


@end

// Model 校验
@interface ZBObject (Validation)


/**
 验证模型
 默认实现只调用-validateValue:forKey:error: with
 all +propertyKeys及其当前值。如果-validateValue: forKey:错误:返回一个新值，属性被设置为该新值。
 
 @param error -如果不为空，则可以将其设置为期间发生的任何错误
 @return 如果模型有效，返回YES;如果验证失败，返回NO。
 */
- (BOOL)validate:(NSError **)error;
@end


