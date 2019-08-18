//
//  ZBNavigationControllerStack.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/9.
//  Copyright © 2019 zzb. All rights reserved.
//  `view` 层维护一个 `ZBNavigationController` 的堆栈 ZBNavigationControllerStack ，不管是 push/pop 还是 present/dismiss ，都使用栈顶的 ZBNavigationController 来执行导航操作，且并且保证 present 出来的是一个 ZBNavigationController 。

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

