
//
//  ZBTableViewModel.m
//  OptimusPrime
//
//  Created by bigfish on 2019/8/9.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "ZBTableViewModel.h"


@interface ZBTableViewModel()
/// request remote data cmd
@property (nonatomic, readwrite, strong) RACCommand *requestRemoteDataCommand;
@end

@implementation ZBTableViewModel

- (void)initialize {
    [super initialize];
    
    self.page = 1;
    self.perPage = 20;
    
    /// request remote data
    @weakify(self)
    self.requestRemoteDataCommand = [[RACCommand alloc] initWithSignalBlock:^(NSNumber *page) {
        @strongify(self)
        return [[self requestRemoteDataSignalWithPage:page.unsignedIntegerValue] takeUntil:self.rac_willDeallocSignal];
    }];
    
    /// 过滤错误信息
    [[self.requestRemoteDataCommand.errors
      filter:[self requestRemoteDataErrorsFilter]]
     subscribe:self.errors];
}

/// sub class can ovrride it
- (BOOL (^)(NSError *error))requestRemoteDataErrorsFilter {
    return ^(NSError *error) {
        return YES;
    };
}

- (id)fetchLocalData {
    return nil;
}

- (NSUInteger)offsetForPage:(NSUInteger)page {
    return (page - 1) * self.perPage;
}


- (RACSignal *)requestRemoteDataSignalWithPage:(NSUInteger)page {
    return [RACSignal empty];
}

@end
