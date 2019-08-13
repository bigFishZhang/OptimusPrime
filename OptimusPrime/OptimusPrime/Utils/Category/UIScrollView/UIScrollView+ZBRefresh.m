//
//  UIScrollView+ZBRefresh.m
//  OptimusPrime
//
//  Created by bigfish on 2019/8/10.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "UIScrollView+ZBRefresh.h"

@implementation UIScrollView (ZBRefresh)
/// 添加下拉刷新控件
- (MJRefreshNormalHeader *)zb_addHeaderRefresh:(void(^)(MJRefreshNormalHeader *header))refreshingBlock {
    
    __weak __typeof(&*self) weakSelf = self;
    MJRefreshNormalHeader *mj_header = [MJRefreshNormalHeader headerWithRefreshingBlock:^{
        __weak __typeof(&*weakSelf) strongSelf = weakSelf;
        !refreshingBlock?:refreshingBlock((MJRefreshNormalHeader *)strongSelf.mj_header);
    }];
    mj_header.lastUpdatedTimeLabel.hidden = YES;
    // Configure normal mj_header
    self.mj_header = mj_header;
    return mj_header;
}

/// 添加上拉加载控件
- (MJRefreshAutoNormalFooter *)zb_addFooterRefresh:(void(^)(MJRefreshAutoNormalFooter *footer))refreshingBlock {
    __weak __typeof(&*self) weakSelf = self;
    MJRefreshAutoNormalFooter *mj_footer = [MJRefreshAutoNormalFooter footerWithRefreshingBlock:^{
        __weak __typeof(&*weakSelf) strongSelf = weakSelf;
        !refreshingBlock?:refreshingBlock((MJRefreshAutoNormalFooter *)strongSelf.mj_footer);
    }];
    // Configure normal mj_footer
    [mj_footer setTitle:@"别拉了，已经到底了..." forState:MJRefreshStateNoMoreData];
    self.mj_footer = mj_footer;
    return mj_footer;
}

@end
