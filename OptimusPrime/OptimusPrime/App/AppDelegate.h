//
//  AppDelegate.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/8.
//  Copyright © 2019 zzb. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ZBNavigationControllerStack.h"
#import "ZBViewModelServicesImpl.h"
@interface AppDelegate : UIResponder <UIApplicationDelegate>

/**
 窗口
 */
@property (strong, nonatomic) UIWindow *window;

/**
 App管理的导航栏的堆栈
 */
@property (nonatomic,readonly,strong) ZBNavigationControllerStack *navigationControllerStack;

/**
 获取AppDelegate

 @return AppDelegate
 */
+ (AppDelegate *)sharedDelegate;

/**
 是否已经弹出键盘
 */
@property (nonatomic, readwrite, assign , getter = isShowKeyboard) BOOL showKeyboard;



@end

