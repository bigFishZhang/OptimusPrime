//
//  HomePageViewModel.m
//  OptimusPrime
//
//  Created by bigfish on 2019/8/13.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "HomePageViewModel.h"

@interface HomePageViewModel ()
/** <#property desc#>*/
@property (nonatomic,strong,readwrite) MainFrameViewModel *mainFrameViewModel;

/** property desc*/
@property (nonatomic,strong,readwrite) ContactsViewModel *contactsViewModel;

/** <#property desc#>*/
@property (nonatomic,strong,readwrite) DiscoverViewModel *discoverViewModel;

/** <#property desc#>*/
@property (nonatomic,strong,readwrite) ProfileViewModel *profileViewModel;

@end

@implementation HomePageViewModel

- (void)initialize {
    [super initialize];
    
    self.mainFrameViewModel  = [[MainFrameViewModel alloc]
                                initWithServices:self.services params:nil];
    self.contactsViewModel   = [[ContactsViewModel alloc]
                                initWithServices:self.services params:nil];
    self.discoverViewModel   = [[DiscoverViewModel alloc]
                                initWithServices:self.services params:nil];
    self.profileViewModel    = [[ProfileViewModel alloc]
                                initWithServices:self.services params:nil];
}

@end
