//
//  AppDelegate.m
//  OptimusPrime
//
//  Created by bigfish on 2019/8/8.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "AppDelegate.h"
#import "HomePageViewController.h"
#import "AccountLoginViewModel.h"
#import "NewFeatureViewModel.h"
#import "BootLoginViewModel.h"

// 测试模式下开放的功能
#if defined(DEBUG)||defined(_DEBUG)
//#import <JPFPSStatus/JPFPSStatus.h>
//#import "MHDebugTouchView.h"
//#import <FBMemoryProfiler/FBMemoryProfiler.h>
//#import <FBRetainCycleDetector/FBRetainCycleDetector.h>
//#import "CacheCleanerPlugin.h"
//#import "RetainCycleLoggerPlugin.h"
#endif

@interface AppDelegate ()
/**
 APP管理的导航栏的堆栈
 */
@property (nonatomic,readwrite,strong) ZBNavigationControllerStack *navigationControllerStack;
/**
 APP的服务层
 */
@property (nonatomic,readwrite,strong) ZBViewModelServicesImpl *services;

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // 初始化UI之前配置(键盘 缓存路径 FMDB等)
    [self configureApplication:application initialParamsBeforeInitUI:launchOptions];
    // Config Service
    self.services = [[ZBViewModelServicesImpl alloc] init];
    // Config Nav Stack
    self.navigationControllerStack = [[ZBNavigationControllerStack alloc] initWithServices:self.services];
    // Configure Window
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window.backgroundColor = [UIColor whiteColor];
    // 设置 rootViewController
    [self.services resetRootViewModel:[self createInitialViewModel]];
    // 让窗口可见
    [self.window makeKeyAndVisible];
    
    // 初始化UI后配置
    [self configureApplication:application initialParamsAfterInitUI:launchOptions];
    
#if defined(DEBUG)||defined(_DEBUG)
    /// 调试模式
    [self configDebugModelTools];
#endif
    
    //保存App版本信息,用于判断是否显示新特性
    [[NSUserDefaults standardUserDefaults] setValue:ZB_APP_VERSION forKey:ZBApplicationVersionKey];
    [[NSUserDefaults standardUserDefaults] synchronize];
    
    return YES;
}



- (void)configureApplication:(UIApplication *)application initialParamsBeforeInitUI:(NSDictionary *)launchOptions{
    
    /// 显示状态栏
    //[application setStatusBarHidden:NO withAnimation:UIStatusBarAnimationFade];
    
    /// 配置键盘
    [self configureKeyboardManager];
    
    /// 配置文件夹
    [self configureApplicationDirectory];
    
    /// 配置FMDB
    [self configureFMDB];
    
}


/// 配置文件夹
- (void)configureApplicationDirectory
{
    /// 创建doc
    [ZBFileManager createDirectoryAtPath:ZBProjectDocDirPath()]; //ZBProjectDocDirPath
    /// 创建cache
    [ZBFileManager createDirectoryAtPath:ZBProjectCacheDirPath()];
    
    NSLog(@"ZBWeChatDocDirPath is [ %@ ] \n ZBWeChatCacheDirPath is [ %@ ]" , ZBProjectDocDirPath() , ZBProjectCacheDirPath());
}

/// 配置键盘管理器
- (void)configureKeyboardManager {
    IQKeyboardManager.sharedManager.enable = YES;
    IQKeyboardManager.sharedManager.enableAutoToolbar = NO;
    IQKeyboardManager.sharedManager.shouldResignOnTouchOutside = YES;
}

/// 配置FMDB
- (void) configureFMDB
{
    //    [[FMDatabaseQueue sharedInstance] inDatabase:^(FMDatabase *db) {
    //        NSString *version = [[NSUserDefaults standardUserDefaults] valueForKey:SBApplicationVersionKey];
    //        if (![version isEqualToString:SB_APP_VERSION]) {
    //            NSString *path = [[NSBundle mainBundle] pathForResource:@"senba_empty_1.0.0" ofType:@"sql"];
    //            NSString *sql  = [[NSString alloc] initWithContentsOfFile:path encoding:NSUTF8StringEncoding error:nil];
    //            /// 执行文件
    //            if (![db executeStatements:sql]) {
    //                SBLogLastError(db);
    //            }
    //        }
    //    }];
}

#pragma mark - 在初始化UI之后配置

- (void)configureApplication:(UIApplication *)application initialParamsAfterInitUI:(NSDictionary *)launchOptions {
    
    /// 配置ActionSheet
//    [LCActionSheet mh_configureActionSheet];
    
    /// 预先配置平台信息
    //    [SBUMengService configureUMengPreDefinePlatforms];
    
    @weakify(self);
    /// 监听切换根控制器的通知
    [[ZBNotificationCenter rac_addObserverForName:ZBSwitchRootViewControllerNotification object:nil] subscribeNext:^(NSNotification * note) {
        /// 这里切换根控制器
        @strongify(self);
        // 重置rootViewController
        ZBSwitchRootViewControllerFromType fromType = [note.userInfo[ZBSwitchRootViewControllerUserInfoKey] integerValue];
        NSLog(@"fromType is  %zd" , fromType);
        /// 切换根控制器
        [self.services resetRootViewModel:[self createInitialViewModel]];
        
        /// 切换了根控制器，切记需要将指示器 移到window的最前面
#if defined(DEBUG)||defined(_DEBUG)
//        [self.window bringSubviewToFront:[ZBDebugTouchView sharedInstance]];
#endif
    }];
    
    /// 配置H5
    //    [SBConfigureManager configure];
}

#pragma mark - 调试(DEBUG)模式下的工具条
- (void)configDebugModelTools
{
    /// 显示FPS
//    [[JPFPSStatus sharedInstance] open];
    
    /// 打开调试按钮
//    [MHDebugTouchView sharedInstance];
    /// CoderMikeHe Fixed: 切换了根控制器，切记需要将指示器 移到window的最前面
//    [self.window bringSubviewToFront:[MHDebugTouchView sharedInstance]];
}

#pragma mark - 创建根控制器
- (ZBViewModel *)createInitialViewModel {
    // The user has logged-in.
//    NSString *version = [[NSUserDefaults standardUserDefaults] valueForKey:ZBApplicationVersionKey];
    
     return [[HomePageViewModel alloc] initWithServices:self.services params:nil];
    /// 版本不一样就先走 新特性界面
//    if (![version isEqualToString:ZB_APP_VERSION]){
//        return [[NewFeatureViewModel alloc] initWithServices:self.services params:nil];
//    }else{
        /// 这里判断一下
        
//        if ([SAMKeychain rawLogin] && self.services.client.currentUser) {
//            /// 有账号+有用户数据
//            /// 已经登录，跳转到主页
//            return [[HomePageViewModel alloc] initWithServices:self.services params:nil];
//        }else if(self.services.client.currentUser){ /// 没账号+有用户数据
//            /// 跳转到账户登录页面
//            return [[AccountLoginViewModel alloc] initWithServices:self.services params:nil];
//        }else{
//            /// 第一次使用微信
//            return [[LoginBaseViewModel alloc] initWithServices:self.services params:nil];
//        }
//    }
}

#pragma mark- 获取appDelegate
+ (AppDelegate *)sharedDelegate{
    return (AppDelegate *)[[UIApplication sharedApplication] delegate];
}




























- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}


@end
