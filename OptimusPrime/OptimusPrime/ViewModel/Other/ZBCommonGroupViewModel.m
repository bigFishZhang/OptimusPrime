//
//  ZBCommonGroupViewModel.m
//  OptimusPrime
//
//  Created by bigfish on 2019/8/13.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "ZBCommonGroupViewModel.h"

@implementation ZBCommonGroupViewModel

+ (instancetype)groupViewModel{
    return [[self alloc] init];
}

- (instancetype)init
{
    self = [super init];
    if (self) {
        _footerHeight = 21;
        _headerHeight = CGFLOAT_MIN;
    }
    return self;
}

@end
