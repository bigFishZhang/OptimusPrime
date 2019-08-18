//
//  HomePageViewModel.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/13.
//  Copyright © 2019 zzb. All rights reserved.
//  主界面的视图的视图模型

#import "ZBTabBarViewModel.h"
#import "MainFrameViewModel.h"
#import "ContactsViewModel.h"
#import "DiscoverViewModel.h"
#import "ProfileViewModel.h"

@interface HomePageViewModel : ZBTabBarViewModel

/** <#property desc#>*/
@property (nonatomic,strong,readonly) MainFrameViewModel *mainFrameViewModel;

/** property desc*/
@property (nonatomic,strong,readonly) ContactsViewModel *contactsViewModel;

/** <#property desc#>*/
@property (nonatomic,strong,readonly) DiscoverViewModel *discoverViewModel;

/** <#property desc#>*/
@property (nonatomic,strong,readonly) ProfileViewModel *profileViewModel;

@end

