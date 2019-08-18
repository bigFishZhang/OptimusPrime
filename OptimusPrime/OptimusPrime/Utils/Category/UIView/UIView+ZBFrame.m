//
//  UIView+ZBFrame.m
//  OptimusPrime
//
//  Created by bigfish on 2019/8/9.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "UIView+ZBFrame.h"

@implementation UIView (ZBFrame)

- (void)setZb_x:(CGFloat)zb_x
{
    CGRect frame = self.frame;
    frame.origin.x = zb_x;
    self.frame = frame;
}
- (CGFloat)zb_x
{
    return self.frame.origin.x;
}

- (void)setZb_y:(CGFloat)zb_y
{
    CGRect frame = self.frame;
    frame.origin.y = zb_y;
    self.frame = frame;
}
- (CGFloat)zb_y
{
    return self.frame.origin.y;
}

- (void)setZb_centerX:(CGFloat)zb_centerX
{
    CGPoint center = self.center;
    center.x = zb_centerX;
    self.center = center;
}
- (CGFloat)zb_centerX
{
    return self.center.x;
}

- (void)setZb_centerY:(CGFloat)zb_centerY
{
    CGPoint center = self.center;
    center.y = zb_centerY;
    self.center = center;
}
- (CGFloat)zb_centerY
{
    return self.center.y;
}

- (void)setZb_width:(CGFloat)zb_width
{
    CGRect frame = self.frame;
    frame.size.width = zb_width;
    self.frame = frame;
}
- (CGFloat)zb_width
{
    return self.frame.size.width;
}


- (void)setZb_height:(CGFloat)zb_height
{
    CGRect frame = self.frame;
    frame.size.height = zb_height;
    self.frame = frame;
}
- (CGFloat)zb_height
{
    return self.frame.size.height;
}

- (void)setZb_size:(CGSize)zb_size
{
    CGRect frame = self.frame;
    frame.size = zb_size;
    self.frame = frame;
}
- (CGSize)zb_size
{
    return self.frame.size;
}

- (void)setZb_origin:(CGPoint)zb_origin
{
    CGRect frame = self.frame;
    frame.origin = zb_origin;
    self.frame = frame;
}
- (CGPoint)zb_origin
{
    return self.frame.origin;
}

- (void)setZb_top:(CGFloat)zb_top
{
    CGRect frame = self.frame;
    frame.origin.y = zb_top;
    self.frame = frame;
}
- (CGFloat)zb_top
{
    return self.frame.origin.y;
}


- (void)setZb_left:(CGFloat)zb_left
{
    CGRect frame = self.frame;
    frame.origin.x = zb_left;
    self.frame = frame;
}
- (CGFloat)zb_left
{
    return self.frame.origin.x;
}


- (void)setZb_bottom:(CGFloat)zb_bottom
{
    CGRect frame = self.frame;
    frame.origin.y = zb_bottom - frame.size.height;
    self.frame = frame;
}
- (CGFloat)zb_bottom{
    return self.frame.origin.y + self.frame.size.height;
}


- (void)setZb_right:(CGFloat)zb_right
{
    CGRect frame = self.frame;
    frame.origin.x = zb_right - frame.size.width;
    self.frame = frame;
}
- (CGFloat)zb_right{
    return self.frame.origin.x + self.frame.size.width;
}


@end
