//
//  ZBWebViewModel.m
//  OptimusPrime
//
//  Created by bigfish on 2019/8/9.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "ZBWebViewModel.h"

@implementation ZBWebViewModel

- (instancetype)initWithServices:(id<ZBViewModelServices>)services params:(NSDictionary *)params {
    self = [super initWithServices:services params:params];
    if (self) {
        self.request = params[ZBViewModelRequestKey];
    }
    return self;
}
@end
