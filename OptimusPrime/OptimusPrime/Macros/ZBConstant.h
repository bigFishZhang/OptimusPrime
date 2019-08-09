//
//  ZBConstant.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/9.
//  Copyright © 2019 zzb. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/// Block
///------
typedef void (^VoidBlock)(void);
typedef BOOL (^BoolBlock)(void);
typedef int  (^IntBlock) (void);
typedef id   (^IDBlock)  (void);

typedef void (^VoidBlock_int)(int);
typedef BOOL (^BoolBlock_int)(int);
typedef int  (^IntBlock_int) (int);
typedef id   (^IDBlock_int)  (int);

typedef void (^VoidBlock_string)(NSString *);
typedef BOOL (^BoolBlock_string)(NSString *);
typedef int  (^IntBlock_string) (NSString *);
typedef id   (^IDBlock_string)  (NSString *);

typedef void (^VoidBlock_id)(id);
typedef BOOL (^BoolBlock_id)(id);
typedef int  (^IntBlock_id) (id);
typedef id   (^IDBlock_id)  (id);


#pragma mark - 应用相关的
/// 切换根控制器的通知 新特性
FOUNDATION_EXTERN NSString * const ZBSwitchRootViewControllerNotification;
/// 切换根控制器的通知 UserInfo key
FOUNDATION_EXTERN NSString * const ZBSwitchRootViewControllerUserInfoKey;

/// 插件Switch按钮值改变
FOUNDATION_EXTERN NSString * const ZBPlugSwitchValueDidChangedNotification;




/// 全局分割线高度 .5
FOUNDATION_EXTERN CGFloat const ZBGlobalBottomLineHeight;

/// 个性签名的最大字数为30
FOUNDATION_EXTERN NSUInteger const ZBFeatureSignatureMaxWords;

/// 用户昵称的最大字数为20
FOUNDATION_EXTERN NSUInteger const ZBNicknameMaxWords;

/// 简书首页地址
FOUNDATION_EXTERN NSString * const ZBMyBlogHomepageUrl ;

/// 国家区号
FOUNDATION_EXTERN NSString * const ZBMobileLoginZoneCodeKey ;
/// 手机号码
FOUNDATION_EXTERN NSString * const ZBMobileLoginPhoneKey ;

/// 验证码时间
FOUNDATION_EXTERN NSUInteger const ZBCaptchaFetchMaxWords;






/// 朋友圈
/// 类型
typedef NS_ENUM(NSUInteger, ZBMomentContentType) {
    ZBMomentContentTypeAttitude = 0,   /// 点赞
    ZBMomentContentTypeComment ,       /// 评论
};

typedef NS_ENUM(NSUInteger, ZBDefaultAvatarType) {
    ZBDefaultAvatarTypeSmall = 0,  /// 小图 34x34
    ZBDefaultAvatarTypeDefualt,    /// 默认 50x50
    ZBDefaultAvatarTypeBig,        /// 大图 85x85
};
/// 占位头像
static inline UIImage *ZBDefaultAvatar(ZBDefaultAvatarType type)
{
    switch (type) {
        case ZBDefaultAvatarTypeSmall:
            return [UIImage imageNamed:@"wx_avatar_default_small"];
            break;
        case ZBDefaultAvatarTypeBig:
            return [UIImage imageNamed:@"wx_avatar_default_big"];
            break;
        default:
            return [UIImage imageNamed:@"wx_avatar_default"];
            break;
    }
}

/// 配图的占位图片
static inline UIImage *ZBPicturePlaceholder()
{
    return [UIImage imageNamed:@"wx_timeline_image_placeholder"];
}



/// 全局细下滑线颜色 以及分割线颜色
#define WXGlobalBottomLineColor     [UIColor colorFromHexString:@"#D9D8D9"]
/// 全局黑色字体
#define WXGlobalBlackTextColor      [UIColor colorFromHexString:@"#000000"]
/// 全局灰色背景
#define WXGlobalGrayBackgroundColor [UIColor colorFromHexString:@"#EFEFF4"]
/// 全局分割线高度
FOUNDATION_EXTERN CGFloat const WXGlobalBottomLineHeight;



/// 微信朋友圈常量定义区
/// 头像宽高 15
FOUNDATION_EXTERN CGFloat const ZBMomentProfileViewAvatarViewWH;
/// 消息tips宽高 40
FOUNDATION_EXTERN CGFloat const ZBMomentProfileViewTipsViewHeight ;
/// 消息tips宽高 181
FOUNDATION_EXTERN CGFloat const ZBMomentProfileViewTipsViewWidth ;
/// 消息tipsView内部的头像宽高 30
FOUNDATION_EXTERN CGFloat const ZBMomentProfileViewTipsViewAvatarWH ;
/// 消息tipsView内部的头像距离tipsView边距 5
FOUNDATION_EXTERN CGFloat const ZBMomentProfileViewTipsViewInnerInset ;
/// 消息tipsView内部的右箭头距离tipsView边距 11
FOUNDATION_EXTERN CGFloat const ZBMomentProfileViewTipsViewRightInset ;
/// 消息tipsView内部的右箭头宽高 15
FOUNDATION_EXTERN CGFloat const ZBMomentProfileViewTipsViewRightArrowWH ;


//// 朋友圈说说
/// 说说内容距离顶部的间距 16
FOUNDATION_EXTERN CGFloat const ZBMomentContentTopInset;
/// 说说内容距离左右屏幕的间距 20
FOUNDATION_EXTERN CGFloat const ZBMomentContentLeftOrRightInset;
/// 内容（控件）之间的的间距 10
FOUNDATION_EXTERN CGFloat const ZBMomentContentInnerMargin;
/// 用户头像的大小 44x44
FOUNDATION_EXTERN CGFloat const ZBMomentAvatarWH;

/// 向上箭头W
FOUNDATION_EXTERN CGFloat const ZBMomentUpArrowViewWidth ;
/// 向上箭头H
FOUNDATION_EXTERN CGFloat const ZBMomentUpArrowViewHeight ;

/// 全文、收起W
FOUNDATION_EXTERN CGFloat const ZBMomentExpandButtonWidth ;
/// 全文、收起H
FOUNDATION_EXTERN CGFloat const ZBMomentExpandButtonHeight ;

/// pictureView中图片之间的的间距 6
FOUNDATION_EXTERN CGFloat const ZBMomentPhotosViewItemInnerMargin;
/// pictureView中图片的大小 86x86 (屏幕尺寸>320)
FOUNDATION_EXTERN CGFloat const ZBMomentPhotosViewItemWH1;
/// pictureView中图片的大小 70x70 (屏幕尺寸<=320)
FOUNDATION_EXTERN CGFloat const ZBMomentPhotosViewItemWH2;

/// 分享内容高度
FOUNDATION_EXTERN CGFloat const ZBMomentShareInfoViewHeight;

/// videoView高度
FOUNDATION_EXTERN CGFloat const ZBMomentVideoViewHeight ;
/// videoView宽度
FOUNDATION_EXTERN CGFloat const ZBMomentVideoViewWidth ;


/// 微信正文内容的显示最大行数（PS：如果超过最大值，那么正文内容就单行显示，可以点击正文内容查看全部内容）
FOUNDATION_EXTERN NSUInteger const ZBMomentContentTextMaxCriticalRow ;
/// 微信正文内容显示（全文/收起）的临界行
FOUNDATION_EXTERN NSUInteger const ZBMomentContentTextExpandCriticalRow ;

/// pictureView最多显示的图片数
FOUNDATION_EXTERN NSUInteger const ZBMomentPhotosMaxCount ;
/// pictureView显示图片的最大列数
#define ZBMomentMaxCols(__photosCount) ((__photosCount==4)?2:3)


/// 微信昵称字体大小
#define ZBMomentScreenNameFont ZBMediumFont(16.0f)
/// 微信正文字体大小
#define ZBMomentContentFont ZBRegularFont_15
/// 微信地址+时间+来源的字体大小
#define ZBMomentCreatedAtFont ZBRegularFont_12
/// 微信（全文/收起）字体大小
#define ZBMomentExpandTextFont ZBRegularFont_16

/// 微信评论正文字体大小
#define ZBMomentCommentContentFont ZBRegularFont_14
/// 微信评论的昵称的字体大小
#define ZBMomentCommentScreenNameFont  ZBMediumFont(14.0f)




/// 微信昵称字体颜色
#define ZBMomentScreenNameTextColor [UIColor colorFromHexString:@"#5B6A92"]
/// 微信正文（链接、电话）的颜色
#define ZBMomentContentUrlTextColor [UIColor colorFromHexString:@"#4380D1"]
/// 微信正文字体颜色
#define ZBMomentContentTextColor WXGlobalBlackTextColor
/// 微信时间颜色
#define ZBMomentCreatedAtTextColor [UIColor colorFromHexString:@"#737373"]



/// 点击文字高亮的颜色
#define ZBMomentTextHighlightBackgroundColor [UIColor colorFromHexString:@"#C7C7C7"]



/// 单张图片的最大高度（等比例）180 (ps：别问我为什么，我量出来的)
FOUNDATION_EXTERN CGFloat const ZBMomentPhotosViewSingleItemMaxHeight;


/// 更多按钮宽高 (实际：25x25)
FOUNDATION_EXTERN CGFloat const ZBMomentOperationMoreBtnWH ;


/// footerViewHeight
FOUNDATION_EXTERN CGFloat const ZBMomentFooterViewHeight ;




//// 评论和点赞view 常量
/// 评论内容距离顶部的间距 5
FOUNDATION_EXTERN CGFloat const ZBMomentCommentViewContentTopOrBottomInset;
/// 评论内容距离评论View左右屏幕的间距 9
FOUNDATION_EXTERN CGFloat const ZBMomentCommentViewContentLeftOrRightInset;
/// 点赞内容距离顶部的间距 7
FOUNDATION_EXTERN CGFloat const ZBMomentCommentViewAttitudesTopOrBottomInset;

/// 评论or点赞 view的背景色
#define ZBMomentCommentViewBackgroundColor [UIColor colorFromHexString:@"#F3F3F5"]
/// 评论or点赞 view的选中的背景色
#define ZBMomentCommentViewSelectedBackgroundColor [UIColor colorFromHexString:@"#CED2DE"]


/// 更多操作View的Size 181x39
/// 更多操作View的Size 181x39
FOUNDATION_EXTERN CGFloat const ZBMomentOperationMoreViewWidth ;
FOUNDATION_EXTERN CGFloat const ZBMomentOperationMoreViewHeight ;

/// 微信动画时间 .25f
FOUNDATION_EXTERN NSTimeInterval const ZBMommentAnimatedDuration;


/**
 YYTextHighlight *highlight = [YYTextHighlight new];
 highlight.userInfo = @{kWBLinkHrefName : href};
 */
//// 这里是点击文本链接（or其他）跳转，通过该key从userInfo中取出对应的数据
/// 点击链接
FOUNDATION_EXTERN NSString * const ZBMomentLinkUrlKey ;
/// 电话号码key
FOUNDATION_EXTERN NSString * const ZBMomentPhoneNumberKey ;
/// 点击位置
FOUNDATION_EXTERN NSString * const ZBMomentLocationNameKey;
/// 点击用户昵称
FOUNDATION_EXTERN NSString * const ZBMomentUserInfoKey;


/// 评论View
/** 弹出评论框View最小高度 */
FOUNDATION_EXTERN CGFloat const ZBMomentCommentToolViewMinHeight;
/** 弹出评论框View最大高度 */
FOUNDATION_EXTERN CGFloat const ZBMomentCommentToolViewMaxHeight ;
/** 弹出评论框View的除了编辑框的高度 */
FOUNDATION_EXTERN CGFloat const ZBMomentCommentToolViewWithNoTextViewHeight;



//// ---------------- inline ----------------

/// 图片的宽度 （九宫格）
static inline CGFloat ZBMomentPhotosViewItemWidth(){
    CGFloat itemW = ([UIScreen mainScreen].bounds.size.width<=320)? ZBMomentPhotosViewItemWH2:ZBMomentPhotosViewItemWH1;
    return itemW;
}


/// 单张图片的最大宽度（方形or等比例）
static inline CGFloat ZBMomentPhotosViewSingleItemMaxWidth(){
    CGFloat itemW = ZBMomentPhotosViewItemWidth();
    return ZBMomentPhotosViewItemInnerMargin + itemW*2;
}

/// 计算微信说说正文的limitWidth或者评论View的宽度
static inline CGFloat ZBMomentCommentViewWidth() {
    return ([UIScreen mainScreen].bounds.size.width - ZBMomentContentLeftOrRightInset*2 -ZBMomentAvatarWH - ZBMomentContentInnerMargin);
}



