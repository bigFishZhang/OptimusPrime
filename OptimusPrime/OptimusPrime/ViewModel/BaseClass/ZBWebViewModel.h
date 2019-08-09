//
//  ZBWebViewModel.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/9.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "ZBViewModel.h"

@interface ZBWebViewModel : ZBViewModel

/// web url quest
@property (nonatomic, readwrite, copy) NSURLRequest *request;

/// 下拉刷新 defalut is NO
@property (nonatomic, readwrite, assign) BOOL shouldPullDownToRefresh;

/// 是否取消导航栏的title等于webView的title。默认是不取消，default is NO
@property (nonatomic, readwrite, assign) BOOL shouldDisableWebViewTitle;

/// 是否取消关闭按钮。默认是不取消，default is NO
@property (nonatomic, readwrite, assign) BOOL shouldDisableWebViewClose;

@end

