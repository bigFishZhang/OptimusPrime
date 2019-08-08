//
//  NSError+ZBModelException.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/8.
//  Copyright © 2019 zzb. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSError (ZBModelException)

/**
 为更新ZBModel过程中发生的异常创建一个新错误

 @param exception 更新模型时抛出的异常 nonull
 @return 返回一个错误，该错误接受其本地化描述和失败原因
 */
+ (instancetype)zb_modelErrorWithException:(NSException *)exception;

@end


