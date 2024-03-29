//
//  NSString+ZBValid.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/9.
//  Copyright © 2019 zzb. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSString (ZBValid)
/// 检测字符串是否包含中文
+( BOOL)zb_isContainChinese:(NSString *)str;

/// 整形
+ (BOOL)zb_isPureInt:(NSString *)string;

/// 浮点型
+ (BOOL)zb_isPureFloat:(NSString *)string;

/// 有效的手机号码
+ (BOOL)zb_isValidMobile:(NSString *)str;

/// 纯数字
+ (BOOL)zb_isPureDigitCharacters:(NSString *)string;

/// 字符串为字母或者数字
+ (BOOL)zb_isValidCharacterOrNumber:(NSString *)str;

/// 判断字符串全是空格or空
+ (BOOL) zb_isEmpty:(NSString *) str;

/// 是否是正确的邮箱
+ (BOOL) zb_isValidEmail:(NSString *)email;

/// 是否是正确的QQ
+ (BOOL) zb_isValidQQ:(NSString *)QQ;

@end


