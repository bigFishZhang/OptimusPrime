//
//  ZBCommonItemViewModel.m
//  OptimusPrime
//
//  Created by bigfish on 2019/8/13.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "ZBCommonItemViewModel.h"

@implementation ZBCommonItemViewModel
+ (instancetype)itemViewModelWithTitle:(NSString *)title icon:(NSString *)icon{
    ZBCommonItemViewModel *item = [[self alloc] init];
    item.title = title;
    item.icon = icon;
    return item;
}

+ (instancetype)itemViewModelWithTitle:(NSString *)title{
    return [self itemViewModelWithTitle:title icon:nil];
}

- (instancetype)init
{
    self = [super init];
    if (self) {
        _selectionStyle = UITableViewCellSelectionStyleGray;
        _rowHeight = 44.0f;
    }
    return self;
}
@end
