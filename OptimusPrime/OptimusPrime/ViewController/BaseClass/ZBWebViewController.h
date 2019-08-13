//
//  ZBWebViewController.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/9.
//  Copyright © 2019 zzb. All rights reserved.
//  所有需要显示WKWebView的自定义视图控制器的基类

#import "ZBViewController.h"
#import "ZBWebViewModel.h"
#import <WebKit/WebKit.h>

@interface ZBWebViewController : ZBViewController<WKNavigationDelegate,WKUIDelegate,WKScriptMessageHandler>

/// webView
@property (nonatomic, weak, readonly) WKWebView *webView;
/// 内容缩进 (64,0,0,0)
@property (nonatomic, readonly, assign) UIEdgeInsets contentInset;

@end


