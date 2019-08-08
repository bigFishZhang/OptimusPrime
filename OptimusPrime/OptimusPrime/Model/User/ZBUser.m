//
//  ZBUser.m
//  OptimusPrime
//
//  Created by bigfish on 2019/8/8.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "ZBUser.h"

@implementation ZBUser

+ (NSDictionary *)modelCustomPropertyMapper {
    return @{@"screenName"         : @"screen_name",
             @"profileImageUrl"    : @"profile_image_url",
             @"avatarLarge"        : @"avatar_large"
             };
}


/// 实现
- (BOOL)isEqual:(ZBUser *)object
{
    /// 重写比对规则
    if([object isKindOfClass:[self class]])
    {
        return [self.idstr isEqualToString:object.idstr];
    }
    return [super isEqual:object];
}


- (instancetype)init
{
    self = [super init];
    if (self) {
        
        //TODO
//        _coverImage = MHImageNamed(@"Kris");
    }
    return self;
}

@end
