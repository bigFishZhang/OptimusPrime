//
//  ZBConstEnum.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/13.
//  Copyright © 2019 zzb. All rights reserved.
//

#ifndef ZBConstEnum_h
#define ZBConstEnum_h

/// tababr item tag
typedef NS_ENUM(NSUInteger, ZBTabBarItemTagType) {
    ZBTabBarItemTagTypeMainFrame = 0,    /// 消息回话
    ZBTabBarItemTagTypeContacts,         /// 通讯录
    ZBTabBarItemTagTypeDiscover,         /// 发现
    ZBTabBarItemTagTypeProfile,          /// 我的
};


/// 切换根控制器类型
typedef NS_ENUM(NSUInteger, ZBSwitchRootViewControllerFromType) {
    ZBSwitchRootViewControllerFromTypeNewFeature = 0,  /// 新特性
    ZBSwitchRootViewControllerFromTypeLogin,           /// 登录
    ZBSwitchRootViewControllerFromTypeLogout,          /// 登出
};

/// 用户登录的渠道
typedef NS_ENUM(NSUInteger, ZBUserLoginChannelType) {
    ZBUserLoginChannelTypeQQ = 0,           /// qq登录
    ZBUserLoginChannelTypeEmail,            /// 邮箱登录
    ZBUserLoginChannelTypeWeChatId,         /// 微信号登录
    ZBUserLoginChannelTypePhone,            /// 手机号登录
};

/// 用户性别
typedef NS_ENUM(NSUInteger, ZBUserGenderType) {
    ZBUserGenderTypeMale =0,            /// 男
    ZBUserGenderTypeFemale,             /// nv
};

/// 插件详情说明
typedef NS_ENUM(NSUInteger, ZBPlugDetailType) {
    ZBPlugDetailTypeLook = 0,     /// 看一看
    ZBPlugDetailTypeSearch,       /// 搜一搜
};


/// 微信朋友圈类型 （0 配图  1 video 2 share）
typedef NS_ENUM(NSUInteger, ZBMomentExtendType) {
    ZBMomentExtendTypePicture = 0, /// 配图
    ZBMomentExtendTypeVideo,       /// 视频
    ZBMomentExtendTypeShare,       /// 分享
};


/// 微信朋友圈分享内容的类型
typedef NS_ENUM(NSUInteger, ZBMomentShareInfoType) {
    ZBMomentShareInfoTypeWebPage = 0, /// 网页
    ZBMomentShareInfoTypeMusic,       /// 音乐
};
















#endif /* ZBConstEnum_h */
