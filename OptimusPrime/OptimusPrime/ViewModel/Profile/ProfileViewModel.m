//
//  ProfileViewModel.m
//  OptimusPrime
//
//  Created by zhang zhengbin on 2019/8/18.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "ProfileViewModel.h"

@implementation ProfileViewModel
- (instancetype)initWithServices:(id<ZBViewModelServices>)services params:(NSDictionary *)params {
    if (self = [super initWithServices:services params:params]) {
        NSLog(@"%s",__func__);
    }
    return self;
}

- (void)initialize {
    [super initialize];
//    @weakify(self);
    self.title = @"Profile";
    
    //获取网络数据
}

@end
