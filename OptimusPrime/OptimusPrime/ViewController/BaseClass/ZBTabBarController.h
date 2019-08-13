//
//  ZBTabBarController.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/9.
//  Copyright © 2019 zzb. All rights reserved.
//  自定义`TabBarController` ,这里将`UITabBarController`作为自己的子控制器，
//其目的就是为了保证的继承的连续性，否则像平常我们自定义`UITabBarController`都是继承`UITabBarController`.

#import "ZBViewController.h"

@interface ZBTabBarController : ZBViewController <UITabBarControllerDelegate>

/// The `tabBarController` instance
@property (nonatomic, readonly, strong) UITabBarController *tabBarController;

@end


