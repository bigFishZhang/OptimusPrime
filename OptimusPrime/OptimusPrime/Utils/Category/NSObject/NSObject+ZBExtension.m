//
//  NSObject+ZBExtension.m
//  OptimusPrime
//
//  Created by bigfish on 2019/8/9.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "NSObject+ZBExtension.h"

@implementation NSObject (ZBExtension)

+ (NSInteger) zb_randomNumberWithFrom:(NSInteger)from to:(NSInteger)to{
    return (NSInteger)(from + (arc4random() % (to - from + 1)));
}


- (void)zb_convertNotification:(NSNotification *)notification completion:(void (^ _Nullable)(CGFloat, UIViewAnimationOptions, CGFloat))completion
{
    // 按钮
    NSDictionary *userInfo = notification.userInfo;
    // 最终尺寸
    CGRect endFrame = [userInfo[UIKeyboardFrameEndUserInfoKey] CGRectValue];
    // 开始尺寸
    CGRect beginFrame = [userInfo[UIKeyboardFrameBeginUserInfoKey] CGRectValue];
    // 动画时间
    CGFloat duration = [userInfo[UIKeyboardAnimationDurationUserInfoKey] doubleValue];
    /// options
    UIViewAnimationOptions options = ([userInfo[UIKeyboardAnimationCurveUserInfoKey] integerValue] << 16 ) | UIViewAnimationOptionBeginFromCurrentState;
    
    /// keyboard height
    CGFloat keyboardH = 0;
    if (beginFrame.origin.y == [[UIScreen mainScreen] bounds].size.height){
        // up
        keyboardH = endFrame.size.height;
    }else if (endFrame.origin.y == [[UIScreen mainScreen] bounds].size.height) {
        // down
        keyboardH = 0;
    }else{
        // up
        keyboardH = endFrame.size.height;
    }
    /// 回调
    !completion?:completion(duration,options,keyboardH);
}



/// Get class
- (BOOL)zb_isStringClass { return [self isKindOfClass:[NSString class]]; }
- (BOOL)zb_isNumberClass { return [self isKindOfClass:[NSNumber class]]; }
- (BOOL)zb_isArrayClass { return [self isKindOfClass:[NSArray class]]; }
- (BOOL)zb_isDictionaryClass { return [self isKindOfClass:[NSDictionary class]]; }
- (BOOL)zb_isStringOrNumberClass { return [self zb_isStringClass] || [self zb_isNumberClass]; }
- (BOOL)zb_isNullOrNil { return !self || [self isKindOfClass:[NSNull class]]; }
- (BOOL)zb_isExist {
    if (self.zb_isNullOrNil) return NO;
    if (self.zb_isStringClass) return (self.zb_stringValueExtension.length>0);
    return YES;
}

/// Get value
- (NSString *)zb_stringValueExtension{
    if ([self zb_isStringClass]) return [(NSString *)self length]? (NSString *)self: @"";
    if ([self zb_isNumberClass]) return [NSString stringWithFormat:@"%@", self];
    return @"";
}

@end
