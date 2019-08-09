//
//  ZBHTTPRequest.m
//  OptimusPrime
//
//  Created by bigfish on 2019/8/8.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "ZBHTTPRequest.h"
#import "ZBHTTPService.h"

@interface ZBHTTPRequest ()
/// 请求参数
@property (nonatomic, readwrite, strong) ZBURLParameters *urlParameters;
@end

@implementation ZBHTTPRequest


+(instancetype)requestWithParameters:(ZBURLParameters *)parameters{
    return [[self alloc] initRequestWithParameters:parameters];
}

-(instancetype)initRequestWithParameters:(ZBURLParameters *)parameters{
    
    self = [super init];
    if (self) {
        self.urlParameters = parameters;
    }
    return self;
}

@end


/// 网络服务层分类 方便ZBHTTPRequest 主动发起请求
@implementation ZBHTTPRequest (ZBHTTPService)
/// 请求数据
-(RACSignal *) enqueueResultClass:(Class /*subclass of MHObject*/) resultClass {
    return [[ZBHTTPService sharedInstance] enqueueRequest:self resultClass:resultClass];
}
@end
