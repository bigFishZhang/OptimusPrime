//
//  RACSignal+ZBHTTPServiceAdditions.m
//  OptimusPrime
//
//  Created by bigfish on 2019/8/8.
//  Copyright © 2019 zzb. All rights reserved.
//

#import "RACSignal+ZBHTTPServiceAdditions.h"
#import "ZBHTTPResponse.h"
@implementation RACSignal (ZBHTTPServiceAdditions)

- (RACSignal *)zb_parsedResults {
    return [self map:^(ZBHTTPResponse *response) {
        NSAssert([response isKindOfClass:ZBHTTPResponse.class], @"Expected %@ to be an ZBHTTPResponse.", response);
        return response.parsedResult;
    }];
}

@end
