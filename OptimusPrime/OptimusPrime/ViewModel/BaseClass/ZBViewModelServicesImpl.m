//
//  ZBViewModelServicesImpl.m
//  OptimusPrime
//
//  Created by bigfish on 2019/8/9.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "ZBViewModelServicesImpl.h"

@implementation ZBViewModelServicesImpl
@synthesize client = _client;

- (instancetype)init
{
    self = [super init];
    if (self) {
        _client = [ZBHTTPService sharedInstance];
    }
    return self;
}

#pragma mark - SBNavigationProtocol empty operation
- (void)pushViewModel:(ZBViewModel *)viewModel animated:(BOOL)animated {}

- (void)popViewModelAnimated:(BOOL)animated {}

- (void)popToRootViewModelAnimated:(BOOL)animated {}

- (void)presentViewModel:(ZBViewModel *)viewModel animated:(BOOL)animated completion:(VoidBlock)completion {}

- (void)dismissViewModelAnimated:(BOOL)animated completion:(VoidBlock)completion {}

- (void)resetRootViewModel:(ZBViewModel *)viewModel {}

@end
