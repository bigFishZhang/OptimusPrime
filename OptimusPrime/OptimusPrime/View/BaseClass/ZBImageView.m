//
//  ZBImageView.m
//  OptimusPrime
//
//  Created by bigfish on 2019/8/8.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "ZBImageView.h"

@implementation ZBImageView

- (void)awakeFromNib{
    [super awakeFromNib];
    self.userInteractionEnabled = YES;
}

- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        self.userInteractionEnabled = YES;
    }
    return self;
}

@end
