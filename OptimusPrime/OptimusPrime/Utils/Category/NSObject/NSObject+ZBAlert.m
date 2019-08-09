//
//  NSObject+ZBAlert.m
//  OptimusPrime
//
//  Created by bigfish on 2019/8/9.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "NSObject+ZBAlert.h"

@implementation NSObject (ZBAlert)
//+ (void)zb_showAlertViewWithTitle:(NSString *)title message:(NSString *)message confirmTitle:(NSString *)confirmTitle {
//
//    [self zb_showAlertViewWithTitle:title message:message confirmTitle:confirmTitle confirmAction:NULL];
//}
//
//+ (void)zb_showAlertViewWithTitle:(NSString *)title message:(NSString *)message confirmTitle:(NSString *)confirmTitle confirmAction:(void(^)())confirmAction {
//
//    [self zb_showAlertViewWithTitle:title message:message confirmTitle:confirmTitle cancelTitle:nil confirmAction:confirmAction cancelAction:NULL];
//}
//
//+ (void)zb_showAlertViewWithTitle:(NSString *)title message:(NSString *)message confirmTitle:(NSString *)confirmTitle cancelTitle:(NSString *)cancelTitle confirmAction:(void(^)())confirmAction cancelAction:(void(^)())cancelAction {

//    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:title message:message preferredStyle:UIAlertControllerStyleAlert];
//    /// 配置alertController
//    alertController.titleColor = ZBColorFromHexString(@"#3C3E44");
//    alertController.messageColor = ZBColorFromHexString(@"#9A9A9C");
//    
//    /// 左边按钮
//    if(cancelTitle.length>0){
//        UIAlertAction *cancel= [UIAlertAction actionWithTitle:cancelTitle?cancelTitle:@"取消" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) { !cancelAction?:cancelAction(); }];
//        cancel.textColor = ZBColorFromHexString(@"#8E929D");
//        [alertController addAction:cancel];
//    }
//    
//    
//    if (confirmTitle.length>0) {
//        UIAlertAction *confirm = [UIAlertAction actionWithTitle:confirmTitle?confirmTitle:@"确定" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) { !confirmAction?:confirmAction();}];
//        confirm.textColor = ZB_MAIN_TINTCOLOR;
//        [alertController addAction:confirm];
//    }
//    
//    dispatch_async(dispatch_get_main_queue(), ^{
//        [[ZBControllerHelper currentViewController] presentViewController:alertController animated:YES completion:NULL];
//    });
//}

@end
