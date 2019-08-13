//
//  ZBMacros.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/9.
//  Copyright © 2019 zzb. All rights reserved.
//

#ifndef ZBMacros_h
#define ZBMacros_h

/// 存储应用版本的key
#define ZBApplicationVersionKey   @"SBApplicationVersionKey"
/// 应用名称
#define ZB_APP_NAME    ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleName"])
/// 应用版本号
#define ZB_APP_VERSION ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"])
/// 应用build
#define ZB_APP_BUILD   ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"])

// 输出日志 (格式: [时间] [哪个方法] [哪行] [输出内容])
#ifdef DEBUG
#define NSLog(format, ...)  printf("\n[%s] %s [第%d行] 💕 %s\n", __TIME__, __FUNCTION__, __LINE__, [[NSString stringWithFormat:format, ##__VA_ARGS__] UTF8String]);
#else

#define NSLog(format, ...)

#endif
// 打印方法
#define ZBLogFunc NSLog(@"%s", __func__)
// 打印请求错误信息
#define ZBLogError(error) NSLog(@"Error: %@", error)
// 销毁打印
#define ZBDealloc NSLog(@"\n =========+++ %@  销毁了 +++======== \n",[self class])

#define ZBLogLastError(db) NSLog(@"lastError: %@, lastErrorCode: %d, lastErrorMessage: %@", [db lastError], [db lastErrorCode], [db lastErrorMessage]);

/// 类型相关
#define ZB_IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define ZB_IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define ZB_IS_RETINA ([[UIScreen mainScreen] scale] >= 2.0)

/// 屏幕尺寸相关
#define ZB_SCREEN_WIDTH  ([[UIScreen mainScreen] bounds].size.width)
#define ZB_SCREEN_HEIGHT ([[UIScreen mainScreen] bounds].size.height)
#define ZB_SCREEN_BOUNDS ([[UIScreen mainScreen] bounds])
#define ZB_SCREEN_MAX_LENGTH (MAX(ZB_SCREEN_WIDTH, ZB_SCREEN_HEIGHT))
#define ZB_SCREEN_MIN_LENGTH (MIN(ZB_SCREEN_WIDTH, ZB_SCREEN_HEIGHT))

/// 手机类型相关
#define ZB_IS_IPHONE_4_OR_LESS  (ZB_IS_IPHONE && ZB_SCREEN_MAX_LENGTH  < 568.0)
#define ZB_IS_IPHONE_5          (ZB_IS_IPHONE && ZB_SCREEN_MAX_LENGTH == 568.0)
#define ZB_IS_IPHONE_6          (ZB_IS_IPHONE && ZB_SCREEN_MAX_LENGTH == 667.0)
#define ZB_IS_IPHONE_6P         (ZB_IS_IPHONE && ZB_SCREEN_MAX_LENGTH == 736.0)
#define ZB_IS_IPHONE_X          (ZB_IS_IPHONE && ZB_SCREEN_MAX_LENGTH == 812.0)


/// 导航条高度
#define ZB_APPLICATION_TOP_BAR_HEIGHT (ZB_IS_IPHONE_X?88.0f:64.0f)
/// tabBar高度
#define ZB_APPLICATION_TAB_BAR_HEIGHT (ZB_IS_IPHONE_X?83.0f:49.0f)
/// 工具条高度 (常见的高度)
#define ZB_APPLICATION_TOOL_BAR_HEIGHT_44  44.0f
#define ZB_APPLICATION_TOOL_BAR_HEIGHT_49  49.0f
/// 状态栏高度
#define ZB_APPLICATION_STATUS_BAR_HEIGHT (ZB_IS_IPHONE_X?44:20.0f)

///------
/// iOS Version
///------
#define ZBIOSVersion ([[[UIDevice currentDevice] systemVersion] floatValue])

#define ZB_iOS7_VERSTION_LATER ([UIDevice currentDevice].systemVersion.floatValue >= 7.0)
#define ZB_iOS8_VERSTION_LATER ([UIDevice currentDevice].systemVersion.floatValue >= 8.0)
#define ZB_iOS9_VERSTION_LATER ([UIDevice currentDevice].systemVersion.floatValue >= 9.0)
#define ZB_iOS10_VERSTION_LATER ([UIDevice currentDevice].systemVersion.floatValue >= 10.0)

#define ZB_SYSTEM_VERSION_EQUAL_TO(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define ZB_SYSTEM_VERSION_GREATER_THAN(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define ZB_SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define ZB_SYSTEM_VERSION_LESS_THAN(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define ZB_SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)


// KVO获取监听对象的属性 有自动提示
// 宏里面的#，会自动把后面的参数变成c语言的字符串
#define ZBKeyPath(objc,keyPath) @(((void)objc.keyPath ,#keyPath))

// 颜色
#define ZBColor(r, g, b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
// 颜色+透明度
#define ZBColorAlpha(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:a]
// 随机色
#define ZBRandomColor ZBColor(arc4random_uniform(256), arc4random_uniform(256), arc4random_uniform(256))
// 根据rgbValue获取对应的颜色
#define ZBColorFromRGB(__rgbValue) [UIColor colorWithRed:((float)((__rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((__rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(__rgbValue & 0xFF))/255.0 alpha:1.0]

#define ZBColorFromRGBAlpha(rgbValue, a) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:(a)]

// AppCaches 文件夹路径
#define ZBCachesDirectory [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) lastObject]
// App DocumentDirectory 文件夹路径
#define ZBDocumentDirectory [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask, YES) lastObject]

// 系统放大倍数
#define ZBScale [[UIScreen mainScreen] scale]

// 设置图片
#define ZBImageNamed(__imageName) [UIImage imageNamed:__imageName]

/// 根据hex 获取颜色
#define ZBColorFromHexString(__hexString__) ([UIColor colorFromHexString:__hexString__])

//  通知中心
#define ZBNotificationCenter [NSNotificationCenter defaultCenter]


/// 全局细下滑线颜色 以及分割线颜色
#define ZBGlobalBottomLineColor     [UIColor colorFromHexString:@"#D9D9D9"]

// 是否为空对象
#define ZBObjectIsNil(__object)  ((nil == __object) || [__object isKindOfClass:[NSNull class]])

// 字符串为空
#define ZBStringIsEmpty(__string) ((__string.length == 0) || ZBObjectIsNil(__string))

// 字符串不为空
#define ZBStringIsNotEmpty(__string)  (!ZBStringIsEmpty(__string))

// 数组为空
#define ZBArrayIsEmpty(__array) ((ZBObjectIsNil(__array)) || (__array.count==0))



/// 适配iPhone X + iOS 11
#define  ZBAdjustsScrollViewInsets_Never(__scrollView)\
do {\
_Pragma("clang diagnostic push")\
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"")\
if ([__scrollView respondsToSelector:NSSelectorFromString(@"setContentInsetAdjustmentBehavior:")]) {\
NSMethodSignature *signature = [UIScrollView instanceMethodSignatureForSelector:@selector(setContentInsetAdjustmentBehavior:)];\
NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:signature];\
NSInteger argument = 2;\
invocation.target = __scrollView;\
invocation.selector = @selector(setContentInsetAdjustmentBehavior:);\
[invocation setArgument:&argument atIndex:2];\
[invocation retainArguments];\
[invocation invoke];\
}\
_Pragma("clang diagnostic pop")\
} while (0)


//// --------------------  下面是公共配置  --------------------

/// 微信项目重要数据备份的文件夹名称（Documents/WeChatDoc）利用NSFileManager来访问
#define ZB_PROJECT_DOC_NAME  @"WeChatDoc"

/// 微信项目轻量数据数据备份的文件夹（Library/Caches/WeChatCache）利用NSFileManager来访问
#define ZB_PROJECT_CACHE_NAME  @"WeChatCache"


/// AppDelegate
#define ZBSharedAppDelegate ((AppDelegate *)[UIApplication sharedApplication].delegate)

////  整个应用的主题配置（颜色+字体）MAIN 代表全局都可以修改 使用前须知
#define ZB_MAIN_NAVIGATIONBAR_BACKGROUNDCOLOR_1 [UIColor colorWithRed:.1 green:.1 blue:.1 alpha:0.65]
#define ZB_MAIN_NAVIGATIONBAR_BACKGROUNDCOLOR_2 [UIColor colorFromHexString:@"#EFEFF4"]
#define ZB_MAIN_NAVIGATIONBAR_BACKGROUNDCOLOR_3 [UIColor colorFromHexString:@"#F3F3F3"]
#define ZB_MAIN_NAVIGATIONBAR_BACKGROUNDCOLOR_4 [UIColor colorFromHexString:@"#E6A863"]
/// 全局青色 tintColor
#define ZB_MAIN_TINTCOLOR [UIColor colorWithRed:(10 / 255.0) green:(193 / 255.0) blue:(42 / 255.0) alpha:1]

/// 整个应用的视图的背景色 BackgroundColor
#define ZB_MAIN_BACKGROUNDCOLOR [UIColor colorFromHexString:@"#EFEFF4"]
/// 整个应用的分割线颜色
#define ZB_MAIN_LINE_COLOR_1 [UIColor colorFromHexString:@"#D9D8D9"]

/// 文字颜色
/// #56585f
#define ZB_MAIN_TEXT_COLOR_1 [UIColor colorFromHexString:@"#B2B2B2"]
/// #9CA1B2
#define ZB_MAIN_TEXT_COLOR_2 [UIColor colorFromHexString:@"#20DB1F"]
/// #FE583E
#define ZB_MAIN_TEXT_COLOR_3 [UIColor colorFromHexString:@"#FE583E"]
/// #0ECCCA
#define ZB_MAIN_TEXT_COLOR_4 [UIColor colorFromHexString:@"#0ECCCA"]
/// #3C3E44
#define ZB_MAIN_TEXT_COLOR_5 [UIColor colorFromHexString:@"#3C3E44"]


/// ---- YYWebImage Option
/// 手动设置image
#define ZBWebImageOptionManually (YYWebImageOptionAllowInvalidSSLCertificates|YYWebImageOptionAllowBackgroundTask|YYWebImageOptionSetImageWithFadeAnimation|YYWebImageOptionAvoidSetImage)


/// 自动设置Image
#define ZBWebImageOptionAutomatic (YYWebImageOptionAllowInvalidSSLCertificates|YYWebImageOptionAllowBackgroundTask|YYWebImageOptionSetImageWithFadeAnimation)



#import "ZBConstInline.h"
#import "ZBConstant.h"
#import "ZBConstEnum.h"
#endif /* ZBMacros_h */
