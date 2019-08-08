//
//  NSError+ZBModelException.m
//  OptimusPrime
//
//  Created by bigfish on 2019/8/8.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "NSError+ZBModelException.h"

// ZBModel的错误域.
static NSString * const ZBModelErrorDomain = @"ZBModelErrorDomain";

// 抛出并捕获异常.
static const NSInteger ZBModelErrorExceptionThrown = 1;

// 与被捕获的NSException关联key.
static NSString * const ZBModelThrownExceptionErrorKey = @"ZBModelThrownException";

@implementation NSError (ZBModelException)

+ (instancetype)zb_modelErrorWithException:(NSException *)exception {
    NSParameterAssert(exception != nil);//exception不为空
    NSDictionary *userInfo = @{
                               NSLocalizedDescriptionKey:exception.description,
                               NSLocalizedFailureReasonErrorKey:exception.reason,
                               ZBModelThrownExceptionErrorKey:exception
                               };
    return [NSError errorWithDomain:ZBModelErrorDomain code:ZBModelErrorExceptionThrown userInfo:userInfo];
    
}



@end
