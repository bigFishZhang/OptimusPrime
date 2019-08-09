//
//  NSAttributedString+ZBSize.m
//  OptimusPrime
//
//  Created by bigfish on 2019/8/9.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "NSAttributedString+ZBSize.h"

@implementation NSAttributedString (ZBSize)
- (CGSize)zb_sizeWithLimitSize:(CGSize)limitSize
{
    CGSize theSize;
    CGRect rect = [self boundingRectWithSize:limitSize options:NSStringDrawingUsesLineFragmentOrigin | NSStringDrawingUsesFontLeading context:nil];
    theSize.width = ceil(rect.size.width);
    theSize.height = ceil(rect.size.height);
    return theSize;
}

- (CGSize)zb_sizeWithLimitWidth:(CGFloat)limitWidth
{
    return [self zb_sizeWithLimitSize:CGSizeMake(limitWidth, MAXFLOAT)];
}
@end
