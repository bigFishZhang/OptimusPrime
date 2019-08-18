//
//  HomePageViewController.m
//  OptimusPrime
//
//  Created by bigfish on 2019/8/12.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "HomePageViewController.h"
#import "ZBNavigationController.h"
//child controller
#import "MainFrameViewController.h"
#import "ContactsViewController.h"
#import "DiscoverViewController.h"
#import "ProfileViewController.h"
#import "AppDelegate.h"
@interface HomePageViewController ()
/** viewModel*/
@property (nonatomic,strong,readonly) HomePageViewModel *viewModel;

@end

@implementation HomePageViewController
@dynamic viewModel;
#pragma mark ---life cycle---

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor redColor];
    
    // 初始化所有的子控制器
    [self setupAllChildViewControllers];
    
    //set tabBarController delegate
    self.tabBarController.delegate = self;
    
    // Do any additional setup after loading the view.
}

#pragma mark ---private---

/**
 初始化所有子控制器
 */
- (void)setupAllChildViewControllers {
    NSArray *titlesArray = @[@"Home",@"Contacts",@"Discover",@"Profile"];
    NSArray *imageNamesArray = @[@"tabbar_mainframe_25x23",
                                 @"tabbar_contacts_27x23",
                                 @"tabbar_discover_23x23",
                                 @"tabbar_me_23x23"];
    NSArray *selectedImageNamesArray = @[@"tabbar_mainframeHL_25x23",
                                         @"tabbar_contactsHL_27x23",
                                         @"tabbar_discoverHL_23x23",
                                         @"tabbar_meHL_23x23"];
    //Home
    UINavigationController *mainFrameNavigationController = ({
        MainFrameViewController *mainFrameViewController = [[MainFrameViewController alloc] initWithViewModel:self.viewModel.mainFrameViewModel];
        ZBTabBarItemTagType tagType = ZBTabBarItemTagTypeMainFrame;
        /// 配置
        [self configViewController:mainFrameViewController
                         imageName:imageNamesArray[tagType]
                 selectedImageName:selectedImageNamesArray[tagType]
                             title:titlesArray[tagType]
                           itemTag:tagType];
        /// 添加到导航栏的栈底控制器
        [[ZBNavigationController alloc] initWithRootViewController:mainFrameViewController];
    });
    
    
    /// 通讯录
    UINavigationController *contactsNavigationController = ({
        ContactsViewController *contactsViewController = [[ContactsViewController alloc] initWithViewModel:self.viewModel.contactsViewModel];
        
        ZBTabBarItemTagType tagType = ZBTabBarItemTagTypeContacts;
        /// 配置
        [self configViewController:contactsViewController
                         imageName:imageNamesArray[tagType]
                 selectedImageName:selectedImageNamesArray[tagType]
                             title:titlesArray[tagType]
                           itemTag:tagType];
        
        [[ZBNavigationController alloc] initWithRootViewController:contactsViewController];
    });
    
    /// 发现
    UINavigationController *discoverNavigationController = ({
        DiscoverViewController *discoverViewController = [[DiscoverViewController alloc] initWithViewModel:self.viewModel.discoverViewModel];
        
        ZBTabBarItemTagType tagType = ZBTabBarItemTagTypeDiscover;
        /// 配置
        [self configViewController:discoverViewController
                         imageName:imageNamesArray[tagType]
                 selectedImageName:selectedImageNamesArray[tagType]
                             title:titlesArray[tagType]
                           itemTag:tagType];
        
        [[ZBNavigationController alloc] initWithRootViewController:discoverViewController];
    });
    
    /// 我的
    UINavigationController *profileNavigationController = ({
        ProfileViewController *profileViewController = [[ProfileViewController alloc] initWithViewModel:self.viewModel.profileViewModel];
        
        ZBTabBarItemTagType tagType = ZBTabBarItemTagTypeProfile;
        /// 配置
        [self configViewController:profileViewController
                         imageName:imageNamesArray[tagType]
                 selectedImageName:selectedImageNamesArray[tagType]
                             title:titlesArray[tagType]
                           itemTag:tagType];
        
        [[ZBNavigationController alloc] initWithRootViewController:profileViewController];
    });
    /// 添加到tabBarController的子视图
    self.tabBarController.viewControllers = @[ mainFrameNavigationController,
                                               contactsNavigationController,
                                               discoverNavigationController,
                                               profileNavigationController ];
    
    
    /// 配置栈底
    
    AppDelegate *app =  (AppDelegate *)ZBSharedAppDelegate;
    [app.navigationControllerStack pushNavigationController:mainFrameNavigationController];
    
}
- (void)configViewController:(UIViewController *)viewController
                   imageName:(NSString *)imageName
           selectedImageName:(NSString *)selectedImageName
                       title:(NSString *)title
                     itemTag:(ZBTabBarItemTagType)tagType {
    
    UIImage *image = [UIImage imageNamed:imageName];
    image = [image imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
    viewController.tabBarItem.image = image;
    viewController.tabBarItem.tag = tagType;
    
    UIImage *selectedImage = [UIImage imageNamed:selectedImageName];
    selectedImage = [selectedImage imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
    viewController.tabBarItem.selectedImage = selectedImage;
    viewController.tabBarItem.title = title;
    
    NSDictionary *normalAttr = @{NSForegroundColorAttributeName:ZBColorFromHexString(@"#929292"),
                                 NSFontAttributeName:ZBRegularFont_10};
    NSDictionary *selectedAttr = @{NSForegroundColorAttributeName:ZBColorFromHexString(@"#09AA07"),
                                   NSFontAttributeName:ZBRegularFont_10};
    [viewController.tabBarItem setTitleTextAttributes:normalAttr forState:UIControlStateNormal];
    [viewController.tabBarItem setTitleTextAttributes:selectedAttr forState:UIControlStateSelected];
    
    [viewController.tabBarItem setTitlePositionAdjustment:UIOffsetMake(0, 0)];
    [viewController.tabBarItem setImageInsets:UIEdgeInsetsMake(0, 0, 0, 0)];
    
}



- (void)tabBarController:(UITabBarController *)tabBarController didSelectViewController:(UIViewController *)viewController
{
    NSLog(@"viewController   %@  %zd",viewController,viewController.tabBarItem.tag);
  
    AppDelegate *app =  (AppDelegate *)ZBSharedAppDelegate;
    [app.navigationControllerStack popNavigationController];
    [app.navigationControllerStack pushNavigationController:(UINavigationController *)viewController];
}

@end
