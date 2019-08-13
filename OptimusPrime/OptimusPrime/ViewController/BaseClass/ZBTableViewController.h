//
//  ZBTableViewController.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/9.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "ZBViewController.h"
#import "ZBTableViewModel.h"
#import "ZBTableView.h"

@interface ZBTableViewController : ZBViewController<UITableViewDelegate,UITableViewDataSource>

/// The table view for tableView controller.
/// tableView
@property (nonatomic, readonly, weak) ZBTableView *tableView;

/// `tableView` 的内容缩进，default is UIEdgeInsetsMake(64,0,0,0)，you can override it
@property (nonatomic, readonly, assign) UIEdgeInsets contentInset;

/// reload tableView data , sub class can override
- (void)reloadData;

/// dequeueReusableCell
- (UITableViewCell *)tableView:(UITableView *)tableView
                    dequeueReusableCellWithIdentifier:(NSString *)identifier
                    forIndexPath:(NSIndexPath *)indexPath;

/// configure cell data
- (void)configureCell:(UITableViewCell *)cell atIndexPath:(NSIndexPath *)indexPath withObject:(id)object;



@end


