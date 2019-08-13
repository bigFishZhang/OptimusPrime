//
//  ZBTabBar.m
//  OptimusPrime
//
//  Created by bigfish on 2019/8/10.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "ZBTabBar.h"

@interface ZBTabBar ()

/// divider
@property (nonatomic, readwrite, weak) UIView *divider ;

@end

@implementation ZBTabBar
- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        /// 去掉tabBar的分割线,以及背景图片
        [self setShadowImage:[UIImage new]];
        [self setBackgroundImage:[UIImage zb_resizableImage:@"tabbarBkg_5x49"]];
        
        /// 添加细线,
        UIView *divider = [[UIView alloc] init];
        divider.backgroundColor = ZBColor(167.0f, 167.0f, 170.0f);
        [self addSubview:divider];
        self.divider = divider;
    }
    return self;
}


#pragma mark - 布局
- (void)layoutSubviews
{
    [super layoutSubviews];
    
    [self bringSubviewToFront:self.divider];
    self.divider.zb_height = ZBGlobalBottomLineHeight;
    self.divider.zb_width = ZB_SCREEN_WIDTH;
}


@end
