//
//  ZBViewModel.m
//  OptimusPrime
//
//  Created by bigfish on 2019/8/8.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "ZBViewModel.h"

/// MVVM View
/// The base map of 'params'
/// The `params` parameter in `-initWithParams:` method.
/// Key-Values's key
/// 传递唯一ID的key：例如：商品id 用户id...
NSString *const ZBViewModelIDKey = @"ZBViewModelIDKey";
/// 传递导航栏title的key：例如 导航栏的title...
NSString *const ZBViewModelTitleKey = @"ZBViewModelTitleKey";
/// 传递数据模型的key：例如 商品模型的传递 用户模型的传递...
NSString *const ZBViewModelUtilKey = @"ZBViewModelUtilKey";
/// 传递webView Request的key：例如 webView request...
NSString *const ZBViewModelRequestKey = @"ZBViewModelRequestKey";

@interface ZBViewModel ()

/// 整个应用的服务层 The `services` parameter in `-initWithServices:params` method.
@property (nonatomic, strong, readwrite) id<ZBViewModelServices> services;
/// The `params` parameter in `-initWithServices:params` method.
@property (nonatomic, readwrite, copy) NSDictionary *params;
/// A RACSubject object, which representing all errors occurred in view model.
@property (nonatomic, readwrite, strong) RACSubject *errors;
/// The `View` willDisappearSignal
@property (nonatomic, readwrite, strong) RACSubject *willDisappearSignal;

@end

@implementation ZBViewModel

/// when `BaseViewModel` created and call `initWithParams` method , so we can ` initialize `
+ (instancetype)allocWithZone:(struct _NSZone *)zone {
    ZBViewModel *viewModel = [super allocWithZone:zone];
    @weakify(viewModel)
    [[viewModel
      rac_signalForSelector:@selector(initWithServices:params:)]
              subscribeNext:^(id x) {
         @strongify(viewModel)
         [viewModel initialize];
     }];
    return viewModel;
}

/// create `viewModel` instance
- (instancetype)initWithServices:(id<ZBViewModelServices>)services params:(NSDictionary *)params {
    self = [super init];
    if (self) {
        /// 默认在viewDidLoad里面加载本地和服务器的数据
        self.shouldFetchLocalDataOnViewModelInitialize = YES;
        self.shouldRequestRemoteDataOnViewDidLoad = YES;
        /// 允许IQKeyboardMananger接管键盘弹出事件
        self.keyboardEnable = YES;
        self.shouldResignOnTouchOutside = YES;
        self.keyboardDistanceFromTextField = 10.0f;
        
        self.title = params[ZBViewModelTitleKey];
        /// 赋值
        self.services = services;
        self.params   = params;
    }
    return self;
}


- (RACSubject *)errors {
    if (!_errors) _errors = [RACSubject subject];
    return _errors;
}

- (RACSubject *)willDisappearSignal {
    if (!_willDisappearSignal) _willDisappearSignal = [RACSubject subject];
    return _willDisappearSignal;
}

/// sub class can override
- (void)initialize {}

@end
