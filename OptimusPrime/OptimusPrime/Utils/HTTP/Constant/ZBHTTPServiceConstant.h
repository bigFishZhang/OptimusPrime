//
//  ZBHTTPServiceConstant.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/8.
//  Copyright © 2019 zzb. All rights reserved.
//  (需要与后端开发协商)

#ifndef ZBHTTPServiceConstant_h
#define ZBHTTPServiceConstant_h

/// 服务器相关
#define ZBHTTPRequestTokenKey @"token"

/// 私钥key
#define ZBHTTPServiceKey  @"privatekey"
/// 私钥Value
#define ZBHTTPServiceKeyValue @"/** 你的私钥 **/"

/// 签名key
#define ZBHTTPServiceSignKey @"sign"

/// 服务器返回的三个固定字段
/// 状态码key
#define ZBHTTPServiceResponseCodeKey @"code"
/// 消息key
#define ZBHTTPServiceResponseMsgKey    @"msg"
/// 数据data
#define ZBHTTPServiceResponseDataKey   @"data"
/// 数据data{"list":[]}
#define ZBHTTPServiceResponseDataListKey   @"list"

#endif /* ZBHTTPServiceConstant_h */
