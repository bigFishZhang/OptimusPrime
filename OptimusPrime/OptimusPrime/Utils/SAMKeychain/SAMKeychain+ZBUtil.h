//
//  SAMKeychain+ZBUtil.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/13.
//  Copyright © 2019 zzb. All rights reserved.
//

#import <SAMKeychain/SAMKeychain.h>

@interface SAMKeychain (ZBUtil)

+ (NSString *)rawLogin ;

+ (BOOL)setRawLogin:(NSString *)rawLogin ;

+ (BOOL)deleteRawLogin;

/// 设备ID or UUID
+ (NSString *)deviceId;

@end


