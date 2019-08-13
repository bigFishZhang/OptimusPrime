//
//  FBKVOController+ZBExtension.m
//  OptimusPrime
//
//  Created by bigfish on 2019/8/10.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "FBKVOController+ZBExtension.h"

@implementation FBKVOController (ZBExtension)

- (void)zb_observe:(id)object
           keyPath:(NSString *)keyPath
             block:(FBKVONotificationBlock)block
{
    [self observe:object
          keyPath:keyPath
          options:NSKeyValueObservingOptionInitial|NSKeyValueObservingOptionNew block:block];
}

- (void)zb_observe:(id)object
           keyPath:(NSString *)keyPath
            action:(SEL)action
{
    [self observe:object
          keyPath:keyPath
          options:NSKeyValueObservingOptionInitial|NSKeyValueObservingOptionNew action:action];
}

@end
