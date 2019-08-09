//
//  ZBControllerHelper.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/9.
//  Copyright © 2019 zzb. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ZBViewController.h"


@interface ZBControllerHelper : NSObject
/// 获取当前正在显示控制器
+ (UIViewController *)currentViewController;

/// 获取ZBNavigationControllerStack管理的栈顶导航栏控制器
+ (UINavigationController *)topNavigationController;

/// 获取ZBNavigationControllerStack管理的栈顶导航栏控制器的 顶部控制器，理论上这个应该是 ZBViewController的子类，但是他不一定是当前正在显示的视图控制器
+ (ZBViewController *)topViewController;
@end


