//
//  UIView+ZBExtension.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/9.
//  Copyright © 2019 zzb. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface UIView (ZBExtension)

/**
 * 判断一个控件是否真正显示在主窗口
 */
- (BOOL)zb_isShowingOnKeyWindow;

/**
 * xib创建的view
 */
+ (instancetype)zb_viewFromXib;

/**
 * xib创建的view
 */
+ (instancetype)zb_viewFromXibWithFrame:(CGRect)frame;

/**
 * xib中显示的属性
 */
@property (nonatomic) IBInspectable UIColor *borderColor;
@property (nonatomic) IBInspectable CGFloat borderWidth;
@property (nonatomic) IBInspectable CGFloat cornerRadius;
@property (nonatomic) IBInspectable BOOL masksToBounds;

@end

