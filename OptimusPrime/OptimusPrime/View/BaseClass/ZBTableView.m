//
//  ZBTableView.m
//  OptimusPrime
//
//  Created by bigfish on 2019/8/8.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "ZBTableView.h"

@implementation ZBTableView

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event{
    
    /// 处理popView
    #pragma TODO 处理popView
   // [MHMomentHelper hideAllPopViewWithAnimated:YES];
    
    /// 全局
    [super touchesBegan:touches withEvent:event];
}

- (UIView *)hitTest:(CGPoint)point withEvent:(UIEvent *)event{
    UIView * hitView = [super hitTest:point withEvent:event];
    return hitView;
}

@end
