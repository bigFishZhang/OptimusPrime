//
//  ZBURLParameters.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/8.
//  Copyright © 2019 zzb. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZBKeyedSubscript.h"
#import "ZBHTTPServiceConstant.h"

/// 请求Method
/// GET 请求
#define MH_HTTTP_METHOD_GET @"GET"
/// HEAD
#define MH_HTTTP_METHOD_HEAD @"HEAD"
/// POST
#define MH_HTTTP_METHOD_POST @"POST"
/// PUT
#define MH_HTTTP_METHOD_PUT @"PUT"
/// POST
#define MH_HTTTP_METHOD_PATCH @"PATCH"
/// DELETE
#define MH_HTTTP_METHOD_DELETE @"DELETE"


/// 项目额外的配置参数拓展 (PS)开发人员无需考虑
@interface ZBURLExtendsParameters : NSObject

/// 类方法
+ (instancetype)extendsParameters;

/// 用户token，默认空字符串
@property (nonatomic, readonly, copy) NSString *token;

/// 设备编号，自行生成
@property (nonatomic, readonly, copy) NSString *deviceid;

/// app版本号
@property (nonatomic, readonly, copy) NSString *ver;

/// 平台 pc,wap,android,iOS
@property (nonatomic, readonly, copy) NSString *platform;

/// 渠道 AppStore
@property (nonatomic, readonly, copy) NSString *channel;

/// 时间戳
@property (nonatomic, readonly, copy) NSString *t;

@end

@interface ZBURLParameters : NSObject

/// 路径
@property (nonatomic, readwrite, strong) NSString *path;
/// 参数列表
@property (nonatomic, readwrite, strong) NSDictionary *parameters;
/// 方法 （POST/GET）
@property (nonatomic, readwrite, strong) NSString *method;
/// 拓展的参数属性 (开发人员不必关心)
@property (nonatomic, readwrite, strong) ZBURLExtendsParameters *extendsParameters;

/**
 参数配置（统一用这个方法配置参数）
 @param method 方法名 （GET/POST/...）
 @param path 文件路径 （user/info）
 @param parameters 具体参数 @{user_id:10013}
 @return 返回一个参数实例
 */
+(instancetype)urlParametersWithMethod:(NSString *)method
                                  path:(NSString *)path
                            parameters:(NSDictionary *)parameters;

@end


