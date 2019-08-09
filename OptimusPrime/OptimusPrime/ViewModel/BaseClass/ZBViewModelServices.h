//
//  ZBViewModelServices.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/9.
//  Copyright © 2019 zzb. All rights reserved.
//  视图模型服务层测协议 （导航栏操作的服务层 + 网络的服务层 ）

#import <Foundation/Foundation.h>
#import "ZBNavigationProtocol.h"
#import "ZBHTTPService.h"

@protocol ZBViewModelServices <NSObject,ZBNavigationProtocol>

/// A reference to ZBHTTPService instance.
/// 全局通过这个Client来请求数据，处理用户信息
@property (nonatomic, readonly, strong) ZBHTTPService *client;

@end
