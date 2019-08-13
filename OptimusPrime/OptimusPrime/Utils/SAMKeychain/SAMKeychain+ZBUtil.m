//
//  SAMKeychain+ZBUtil.m
//  OptimusPrime
//
//  Created by bigfish on 2019/8/13.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "SAMKeychain+ZBUtil.h"

/// 登录账号的key
static NSString *const ZB_RAW_LOGIN = @"ZBRawLogin";
static NSString *const ZB_SERVICE_NAME_IN_KEYCHAIN = @"zzb.com.OptimusPrime";
static NSString *const ZB_DEVICEID_ACCOUNT         = @"DeviceID";

@implementation SAMKeychain (ZBUtil)

+ (NSString *)rawLogin {
    return [[NSUserDefaults standardUserDefaults] objectForKey:ZB_RAW_LOGIN];
}
+ (BOOL)setRawLogin:(NSString *)rawLogin {
    if (rawLogin == nil) NSLog(@"+setRawLogin: %@", rawLogin);
    
    [[NSUserDefaults standardUserDefaults] setObject:rawLogin forKey:ZB_RAW_LOGIN];
    [[NSUserDefaults standardUserDefaults] synchronize];
    
    return YES;
}
+ (BOOL)deleteRawLogin {
    [[NSUserDefaults standardUserDefaults] removeObjectForKey:ZB_RAW_LOGIN];
    [[NSUserDefaults standardUserDefaults] synchronize];
    return YES;
}


+ (NSString *)deviceId{
    NSString * deviceidStr = [SAMKeychain passwordForService:ZB_SERVICE_NAME_IN_KEYCHAIN account:ZB_DEVICEID_ACCOUNT];
    if (deviceidStr == nil) {
        deviceidStr = [UIDevice currentDevice].identifierForVendor.UUIDString;
        [SAMKeychain setPassword:deviceidStr forService:ZB_SERVICE_NAME_IN_KEYCHAIN account:ZB_DEVICEID_ACCOUNT];
    }
    return deviceidStr;
}

@end
