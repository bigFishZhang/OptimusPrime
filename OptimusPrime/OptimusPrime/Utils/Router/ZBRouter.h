//
//  ZBRouter.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/8.
//  Copyright © 2019 zzb. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZBViewController.h"

@interface ZBRouter : NSObject

/// Retrieves the shared router instance.
///
/// Returns the shared router instance.
+ (instancetype)sharedInstance;

/// Retrieves the view corresponding to the given view model.
///
/// viewModel - The view model
///
/// Returns the view corresponding to the given view model.
- (ZBViewController *)viewControllerForViewModel:(ZBViewModel *)viewModel;

@end


