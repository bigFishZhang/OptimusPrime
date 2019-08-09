//
//  ZBHTTPRequest.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/8.
//  Copyright © 2019 zzb. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZBURLParameters.h"
#import "RACSignal+ZBHTTPServiceAdditions.h"
@interface ZBHTTPRequest : NSObject
/// 请求参数
@property (nonatomic, readonly, strong) ZBURLParameters *urlParameters;
/**
 获取请求类
 @param parameters  参数模型
 @return 请求类
 */
+(instancetype)requestWithParameters:(ZBURLParameters *)parameters;



@end

/// ZBHTTPRequest的分类
@interface ZBHTTPRequest (ZBHTTPService)
/// 入队
- (RACSignal *) enqueueResultClass:(Class /*subclass of MHObject*/) resultClass;

@end

