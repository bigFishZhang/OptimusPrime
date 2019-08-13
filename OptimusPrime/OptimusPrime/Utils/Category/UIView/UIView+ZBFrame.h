//
//  UIView+ZBFrame.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/9.
//  Copyright © 2019 zzb. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface UIView (ZBFrame)

/// < Shortcut for frame.origin.x.
@property (nonatomic, readwrite, assign) CGFloat zb_left;
/// < Shortcut for frame.origin.y
@property (nonatomic, readwrite, assign) CGFloat zb_top;
/// < Shortcut for frame.origin.x + frame.size.width
@property (nonatomic, readwrite, assign) CGFloat zb_right;
/// < Shortcut for frame.origin.y + frame.size.height
@property (nonatomic, readwrite, assign) CGFloat zb_bottom;

/// < Shortcut for frame.origin.x.
@property (nonatomic, readwrite, assign) CGFloat zb_x;
/// < Shortcut for frame.origin.y
@property (nonatomic, readwrite, assign) CGFloat zb_y;
/// < Shortcut for frame.size.width
@property (nonatomic, readwrite, assign) CGFloat zb_width;
/// < Shortcut for frame.size.height
@property (nonatomic, readwrite, assign) CGFloat zb_height;

/// < Shortcut for center.x
@property (nonatomic, readwrite, assign) CGFloat zb_centerX;
///< Shortcut for center.y
@property (nonatomic, readwrite, assign) CGFloat zb_centerY;

/// < Shortcut for frame.size.
@property (nonatomic, readwrite, assign) CGSize zb_size;
/// < Shortcut for frame.origin.
@property (nonatomic, readwrite, assign) CGPoint zb_origin;

@end


