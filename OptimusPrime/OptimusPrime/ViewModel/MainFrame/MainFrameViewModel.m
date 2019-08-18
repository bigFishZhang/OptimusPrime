//
//  MainFrameViewModel.m
//  OptimusPrime
//
//  Created by bigfish on 2019/8/13.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "MainFrameViewModel.h"

@implementation MainFrameViewModel
- (instancetype)initWithServices:(id<ZBViewModelServices>)services params:(NSDictionary *)params {
    if (self = [super initWithServices:services params:params]) {
        NSLog(@"%s",__func__);
        
    }
    return self;
}

- (void)initialize {
    [super initialize];
    //    @weakify(self);
    self.title = @"Home";
    //获取网络数据
}
@end
