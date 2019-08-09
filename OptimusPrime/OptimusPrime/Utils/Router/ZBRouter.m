
//
//  ZBRouter.m
//  OptimusPrime
//
//  Created by bigfish on 2019/8/8.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "ZBRouter.h"


@interface ZBRouter ()

/// viewModel到viewController的映射
@property (nonatomic, copy) NSDictionary *viewModelViewMappings;

@end

@implementation ZBRouter

static ZBRouter *sharedInstance_ = nil;

+ (id)allocWithZone:(struct _NSZone *)zone
{
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance_ = [super allocWithZone:zone];
    });
    return sharedInstance_;
}

- (id)copyWithZone:(NSZone *)zone
{
    return sharedInstance_;
}

+ (instancetype)sharedInstance {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance_ = [[self alloc] init];
    });
    return sharedInstance_;
}

- (ZBViewController *)viewControllerForViewModel:(ZBViewModel *)viewModel {
    NSString *viewController = self.viewModelViewMappings[NSStringFromClass(viewModel.class)];
    
    NSParameterAssert([NSClassFromString(viewController) isSubclassOfClass:[ZBViewController class]]);
    NSParameterAssert([NSClassFromString(viewController) instancesRespondToSelector:@selector(initWithViewModel:)]);
    
    return [[NSClassFromString(viewController) alloc] initWithViewModel:viewModel];
}

/// 这里是viewModel -> ViewController的映射
/// If You Use Push 、 Present 、 ResetRootViewController ,You Must Config This Dict
- (NSDictionary *)viewModelViewMappings {
    return @{@"MHNewFeatureViewModel":@"MHNewFeatureViewController",
             @"MHHomePageViewModel":@"MHHomePageViewController",
             @"MHUserInfoViewModel":@"MHUserInfoViewController",
             @"MHMoreInfoViewModel":@"MHMoreInfoViewController",
             @"MHFeatureSignatureViewModel":@"MHFeatureSignatureViewController",
             @"MHAddFriendsViewModel":@"MHAddFriendsViewController",
             @"MHSearchFriendsViewModel":@"MHSearchFriendsViewController",
             @"MHAccountLoginViewModel":@"MHAccountLoginViewController",
             @"MHBootLoginViewModel":@"MHBootLoginViewController",
             @"MHLoginViewModel":@"MHLoginViewController",
             @"MHMobileLoginViewModel":@"MHMobileLoginViewController",
             @"MHZoneCodeViewModel":@"MHZoneCodeViewController",
             @"MHSettingViewModel":@"MHSettingViewController",
             @"MHWebViewModel":@"MHWebViewController",
             @"MHRegisterViewModel":@"MHRegisterViewController",
             @"MHCommitViewModel":@"MHCommitViewController",
             @"MHLanguageViewModel":@"MHLanguageViewController",
             @"MHModifyNicknameViewModel":@"MHModifyNicknameViewController",
             @"MHLocationViewModel":@"MHLocationViewController",
             @"MHGenderViewModel":@"MHGenderViewController",
             @"MHPlugViewModel":@"MHPlugViewController",
             @"MHPlugDetailViewModel":@"MHPlugDetailViewController",
             @"MHAccountSecurityViewModel":@"MHAccountSecurityViewController",
             @"MHTestViewModel":@"MHTestViewController",
             @"MHNotificationViewModel":@"MHNotificationViewController",
             @"MHFreeInterruptionViewModel":@"MHFreeInterruptionViewController",
             @"MHAboutUsViewModel":@"MHAboutUsViewController",
             @"MHPrivacyViewModel":@"MHPrivacyViewController",
             @"MHGeneralViewModel":@"MHGeneralViewController",
             @"MHEmotionViewModel":@"MHEmotionViewController",
             @"MHMomentViewModel":@"MHMomentViewController",
             @"MHProfileInfoViewModel":@"MHProfileInfoViewController"
             };
}


@end
