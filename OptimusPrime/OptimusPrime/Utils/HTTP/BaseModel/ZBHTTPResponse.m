//
//  ZBHTTPResponse.m
//  OptimusPrime
//
//  Created by bigfish on 2019/8/8.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "ZBHTTPResponse.h"
#import "ZBHTTPServiceConstant.h"
@interface ZBHTTPResponse ()
/**
 解析后的与API response 对应的 ZBObject对象
 */
@property (nonatomic, readwrite, strong) id parsedResult;

/**
 服务器返回的状态码
 */
@property (nonatomic, readwrite, assign) ZBHTTPResponseCode code;

/**
 服务器返回的信息
 */
@property (nonatomic, readwrite, copy) NSString *msg;

@end

@implementation ZBHTTPResponse
- (instancetype)initWithResponseObject:(id)responseObject parsedResult:(id)parsedResult
{
    self = [super init];
    if (self) {
        self.parsedResult = parsedResult ?:NSNull.null;
        self.code = [responseObject[ZBHTTPServiceResponseCodeKey] integerValue];
        self.msg = responseObject[ZBHTTPServiceResponseMsgKey];
    }
    return self;
}


@end
