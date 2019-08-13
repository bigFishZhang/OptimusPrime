//
//  ZBCommonViewModel.m
//  OptimusPrime
//
//  Created by bigfish on 2019/8/9.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "ZBCommonViewModel.h"

@implementation ZBCommonViewModel
- (void)initialize{
    [super initialize];
    
    @weakify(self);
    /// 选中cell的命令
    /// UI Test
    self.didSelectCommand = [[RACCommand alloc] initWithSignalBlock:^RACSignal *(NSIndexPath *indexPath) {
        @strongify(self);
        ZBCommonGroupViewModel *groupViewModel = self.dataSource[indexPath.section] ;
        ZBCommonItemViewModel *itemViewModel = groupViewModel.itemViewModels[indexPath.row];
        
        if (itemViewModel.operation) {
            /// 有操作执行操作
            itemViewModel.operation();
        }else if(itemViewModel.destViewModelClass){
            /// 没有操作就跳转VC
            Class viewModelClass = itemViewModel.destViewModelClass;
            ZBViewModel *viewModel = [[viewModelClass alloc] initWithServices:self.services params:@{ZBViewModelTitleKey:itemViewModel.title}];
            [self.services pushViewModel:viewModel animated:YES];
        }
        return [RACSignal empty];
    }];
}

@end
