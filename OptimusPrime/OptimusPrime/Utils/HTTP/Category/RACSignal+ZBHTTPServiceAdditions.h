//
//  RACSignal+ZBHTTPServiceAdditions.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/8.
//  Copyright © 2019 zzb. All rights reserved.
//  Convenience category to retreive parsedResults from ZBHTTPResponse.

#import <ReactiveObjC/ReactiveObjC.h>

@interface RACSignal (ZBHTTPServiceAdditions)

// This method assumes that the receiver is a signal of ZBHTTPResponses.
//
// Returns a signal that maps the receiver to become a signal of
// ZBHTTPResponses.parsedResult.
- (RACSignal *)zb_parsedResults;

@end


