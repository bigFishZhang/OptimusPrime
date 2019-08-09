//
//  NSAttributedString+ZBSize.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/9.
//  Copyright © 2019 zzb. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSAttributedString (ZBSize)

/**
 *  动态计算文字的宽高（多行）
 *  @param limitSize 限制的范围
 *
 *  @return 计算的宽高
 */
- (CGSize)zb_sizeWithLimitSize:(CGSize)limitSize;

/**
 *  动态计算文字的宽高（多行）
 *  @param limitWidth 限制宽度 ，高度不限制
 *
 *  @return 计算的宽高
 */
- (CGSize)zb_sizeWithLimitWidth:(CGFloat)limitWidth;

@end


