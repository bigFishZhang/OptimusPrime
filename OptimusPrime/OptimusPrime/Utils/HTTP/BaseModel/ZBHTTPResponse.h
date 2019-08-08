//
//  ZBHTTPResponse.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/8.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "ZBObject.h"

/// 请求数据返回的状态码
typedef NS_ENUM(NSUInteger, ZBHTTPResponseCode) {
    ZBHTTPResponseCodeSuccess = 100 ,                     /// 请求成功
    ZBHTTPResponseCodeNotLogin = 666,                     /// 用户尚未登录
    ZBHTTPResponseCodeParametersVerifyFailure = 105,      /// 参数验证失败
};


@interface ZBHTTPResponse : ZBObject

/// The parsed ZBObject object corresponding to the API response.
/// 若没有数据是NSNull 而不是nil .对应于服务器json数据的 data
@property (nonatomic, readonly, strong) id parsedResult;
/// 自己服务器返回的状态码 对应于服务器json数据的 code
@property (nonatomic, readonly, assign) ZBHTTPResponseCode code;
/// 自己服务器返回的信息 对应于服务器json数据的 code
@property (nonatomic, readonly, copy) NSString *msg;

// Initializes the receiver with the headers from the given response, and given the origin data and the
// given parsed model object(s).


/**
 初始化ResponseObject

 @param responseObject afnetworking返回的responseObject
 @param parsedResult 给定的已解析模型对象
 @return <#return value description#>
 */
- (instancetype)initWithResponseObject:(id)responseObject parsedResult:(id)parsedResult;

@end

