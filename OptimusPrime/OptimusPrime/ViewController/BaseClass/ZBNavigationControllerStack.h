//
//  ZBNavigationControllerStack.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/9.
//  Copyright © 2019 zzb. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ZBViewModelServices;

@interface ZBNavigationControllerStack : NSObject
/// Initialization method. This is the preferred way to create a new navigation controller stack.
///
/// services - The service bus of the `Model` layer.
///
/// Returns a new navigation controller stack.
- (instancetype)initWithServices:(id<ZBViewModelServices>)services;

/// Pushes the navigation controller.
///
/// navigationController - the navigation controller
- (void)pushNavigationController:(UINavigationController *)navigationController;

/// Pops the top navigation controller in the stack.
///
/// Returns the popped navigation controller.
- (UINavigationController *)popNavigationController;

/// Retrieves the top navigation controller in the stack.
///
/// Returns the top navigation controller in the stack.
- (UINavigationController *)topNavigationController;
@end

