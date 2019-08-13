//
//  UIFont+ZBExtension.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/9.
//  Copyright © 2019 zzb. All rights reserved.
//

#import <UIKit/UIKit.h>

// IOS版本
#define ZBIOSVersion ([[[UIDevice currentDevice] systemVersion] floatValue])


/// 设置系统的字体大小（YES：粗体 NO：常规）
#define ZBFont(__size__,__bold__) ((__bold__)?([UIFont boldSystemFontOfSize:__size__]):([UIFont systemFontOfSize:__size__]))

/// 极细体
#define ZBUltralightFont(__size__) ((ZBIOSVersion<9.0)?ZBFont(__size__ , YES):[UIFont zb_fontForPingFangSC_UltralightFontOfSize:__size__])

/// 纤细体
#define ZBThinFont(__size__)       ((ZBIOSVersion<9.0)?ZBFont(__size__ , YES):[UIFont zb_fontForPingFangSC_ThinFontOfSize:__size__])

/// 细体
#define ZBLightFont(__size__)      ((ZBIOSVersion<9.0)?ZBFont(__size__ , YES):[UIFont zb_fontForPingFangSC_LightFontOfSize:__size__])

// 中等
#define ZBMediumFont(__size__)     ((ZBIOSVersion<9.0)?ZBFont(__size__ , YES):[UIFont zb_fontForPingFangSC_MediumFontOfSize:__size__])

// 常规
#define ZBRegularFont(__size__)    ((ZBIOSVersion<9.0)?ZBFont(__size__ , NO):[UIFont zb_fontForPingFangSC_RegularFontOfSize:__size__])

/** 中粗体 */
#define ZBSemiboldFont(__size__)   ((ZBIOSVersion<9.0)?ZBFont(__size__ , YES):[UIFont zb_fontForPingFangSC_SemiboldFontOfSize:__size__])


/// 苹方常规字体 10
#define ZBRegularFont_10 ZBRegularFont(10.0f)
/// 苹方常规字体 11
#define ZBRegularFont_11 ZBRegularFont(11.0f)
/// 苹方常规字体 12
#define ZBRegularFont_12 ZBRegularFont(12.0f)
/// 苹方常规字体 13
#define ZBRegularFont_13 ZBRegularFont(13.0f)
/** 苹方常规字体 14 */
#define ZBRegularFont_14 ZBRegularFont(14.0f)
/// 苹方常规字体 15
#define ZBRegularFont_15 ZBRegularFont(15.0f)
/// 苹方常规字体 16
#define ZBRegularFont_16 ZBRegularFont(16.0f)
/// 苹方常规字体 17
#define ZBRegularFont_17 ZBRegularFont(17.0f)
/// 苹方常规字体 18
#define ZBRegularFont_18 ZBRegularFont(18.0f)
/// 苹方常规字体 19
#define ZBRegularFont_19 ZBRegularFont(19.0f)
/// 苹方常规字体 20
#define ZBRegularFont_20 ZBRegularFont(20.0f)

@interface UIFont (ZBExtension)

/**
 *  苹方极细体
 *
 *  @param fontSize 字体大小
 *
 */
+(instancetype) zb_fontForPingFangSC_UltralightFontOfSize:(CGFloat)fontSize;

/**
 *  苹方常规体
 *
 *  @param fontSize 字体大小
 *
 */
+(instancetype) zb_fontForPingFangSC_RegularFontOfSize:(CGFloat)fontSize;

/**
 *  苹方中粗体
 *
 *  @param fontSize 字体大小
 *
 */
+(instancetype) zb_fontForPingFangSC_SemiboldFontOfSize:(CGFloat)fontSize;

/**
 *  苹方纤细体
 *
 *  @param fontSize 字体大小
 *
 */
+(instancetype) zb_fontForPingFangSC_ThinFontOfSize:(CGFloat)fontSize;

/**
 *  苹方细体
 *
 *  @param fontSize 字体大小
 *
 */
+(instancetype) zb_fontForPingFangSC_LightFontOfSize:(CGFloat)fontSize;

/**
 *  苹方中黑体
 *
 *  @param fontSize 字体大小
 *
 */
+(instancetype) zb_fontForPingFangSC_MediumFontOfSize:(CGFloat)fontSize;



@end


