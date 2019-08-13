//
//  UIImage+ZBExtension.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/10.
//  Copyright © 2019 zzb. All rights reserved.
//

#import <UIKit/UIKit.h>



@interface UIImage (ZBExtension)
/**
 *  根据图片名返回一张能够自由拉伸的图片 (从中间拉伸)
 */
+ (UIImage *)zb_resizableImage:(NSString *)imgName;
+ (UIImage *)zb_resizableImage:(NSString *)imgName capInsets:(UIEdgeInsets)capInsets;


/// 返回一张未被渲染的图片
+ (UIImage *)zb_imageAlwaysShowOriginalImageWithImageName:(NSString *)imageName;
/// 获取视频某个时间的帧图片
+ (UIImage *)zb_thumbnailImageForVideo:(NSURL *)videoURL atTime:(NSTimeInterval)time;

/// /// 获取屏幕截图
///
/// @return 屏幕截图图像
+ (UIImage *)zb_screenShot;

- (UIImage *)zb_fixOrientation;
@end


