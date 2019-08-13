//
//  ZBCommonGroupViewModel.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/13.
//  Copyright © 2019 zzb. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZBCommonGroupViewModel : NSObject
/// 组头
@property (nonatomic, copy) NSString *header;
/// headerHeight defalult is .001
@property (nonatomic, readwrite, assign) CGFloat headerHeight;
/// 组尾
@property (nonatomic, copy) NSString *footer;
/// footerHeight defalult is 21
@property (nonatomic, readwrite, assign) CGFloat footerHeight;
/// 里面装着都是 MHCommonItemViewModel 以及其子类
@property (nonatomic, strong) NSArray *itemViewModels;

+ (instancetype)groupViewModel;
@end


