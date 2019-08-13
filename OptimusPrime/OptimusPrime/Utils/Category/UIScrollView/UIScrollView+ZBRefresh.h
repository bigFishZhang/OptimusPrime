//
//  UIScrollView+ZBRefresh.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/10.
//  Copyright © 2019 zzb. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MJRefresh/MJRefresh.h>

@interface UIScrollView (ZBRefresh)
/// 添加下拉刷新控件
- (MJRefreshNormalHeader *)zb_addHeaderRefresh:(void(^)(MJRefreshNormalHeader *header))refreshingBlock;
/// 添加上拉加载控件
- (MJRefreshAutoNormalFooter *)zb_addFooterRefresh:(void(^)(MJRefreshAutoNormalFooter *footer))refreshingBlock;
@end


