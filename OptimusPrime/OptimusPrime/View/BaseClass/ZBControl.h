//
//  ZBControl.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/8.
//  Copyright © 2019 zzb. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YYGestureRecognizer.h"

@interface ZBControl : UIView

/// 图片
@property (nonatomic, strong) UIImage *image;

/// 点击回调
@property (nonatomic, copy) void (^touchBlock)(ZBControl *view,
                                            YYGestureRecognizerState state,
                                            NSSet *touches,
                                            UIEvent *event);
/// 长按回调
@property (nonatomic, copy) void (^longPressBlock)(ZBControl *view, CGPoint point);

@end


