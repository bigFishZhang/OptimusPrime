//
//  NSObject+ZBExtension.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/9.
//  Copyright © 2019 zzb. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSObject (ZBExtension)
/// 获取 [from to] 之间的数据
+ (NSInteger) zb_randomNumberWithFrom:(NSInteger)from to:(NSInteger)to;

/// 根据获取到的
- (void)zb_convertNotification:(NSNotification *_Nullable)notification
                    completion:(void (^ __nullable)(CGFloat duration,
                                                    UIViewAnimationOptions options,
                                                    CGFloat keyboardH))completion;

#pragma mark - Get..
/// Get class
- (BOOL)zb_isStringClass;
- (BOOL)zb_isNumberClass;
- (BOOL)zb_isArrayClass;
- (BOOL)zb_isDictionaryClass;
- (BOOL)zb_isStringOrNumberClass;
- (BOOL)zb_isNullOrNil;
- (BOOL)zb_isExist;

/// Get value
- (NSString *_Nullable)zb_stringValueExtension;

@end

