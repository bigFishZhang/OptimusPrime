//
//  ZBCommonItemViewModel.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/13.
//  Copyright © 2019 zzb. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZBCommonItemViewModel : NSObject
/// 图标
@property (nonatomic, readwrite, copy) NSString *icon;
/// 标题
@property (nonatomic, readwrite, copy) NSString *title;
/// 子标题
@property (nonatomic, readwrite, copy) NSString *subtitle;

/// rowHeight , default is 44.0f
@property (nonatomic, readwrite, assign) CGFloat rowHeight;
// default is UITableViewCellSelectionStyleGray.
@property (nonatomic, readwrite, assign) UITableViewCellSelectionStyle selectionStyle;

/// 右边显示的数字标记
@property (nonatomic, readwrite, copy) NSString *badgeValue;

/// 中间偏左icon的图片名字
@property (nonatomic, readwrite, copy) NSString *centerLeftViewName;
/// 中间偏右icon的图片名字
@property (nonatomic, readwrite, copy) NSString *centerRightViewName;
/// 点击这行cell，需要调转到哪个控制器的视图模型 destViewModelClass：必须是SBViewModel的子类
@property (nonatomic, readwrite, assign) Class destViewModelClass;
/// 封装点击这行cell想做的事情
@property (nonatomic, readwrite, copy) void (^operation)(void);

/// init title or icon
+ (instancetype)itemViewModelWithTitle:(NSString *)title icon:(NSString *)icon;
/// init title
+ (instancetype)itemViewModelWithTitle:(NSString *)title;


@end


