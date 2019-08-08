//
//  ZBKeyedSubscript.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/8.
//  Copyright © 2019 zzb. All rights reserved.
//  参数

#import <Foundation/Foundation.h>

@interface ZBKeyedSubscript : NSObject

/// 类方法
+ (instancetype) subscript;
/// 拼接一个字典
+ (instancetype)subscriptWithDictionary:(NSDictionary *) dict;

-(instancetype)initWithDictionary:(NSDictionary *) dict;

- (id)objectForKeyedSubscript:(id)key;

- (void)setObject:(id)obj forKeyedSubscript:(id <NSCopying>)key;

/// 转换为字典
- (NSDictionary *)dictionary;

@end


