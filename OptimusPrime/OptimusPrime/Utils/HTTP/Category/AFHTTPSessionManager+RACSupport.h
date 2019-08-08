//
//  AFHTTPSessionManager+RACSupport.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/8.
//  Copyright © 2019 zzb. All rights reserved.
//

#import <AFNetworking/AFNetworking.h>
#import <ReactiveObjC/ReactiveObjC.h>

#if (defined(__IPHONE_OS_VERSION_MAX_ALLOWED) && __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_7_0) || (defined(__MAC_OS_X_VERSION_MAX_ALLOWED) && __MAC_OS_X_VERSION_MAX_ALLOWED >= __MAC_10_9)

@interface AFHTTPSessionManager (RACSupport)

/// A convenience around -GET:parameters:success:failure: that returns a cold signal of the
/// resulting JSON object and response headers or error.
- (RACSignal *)rac_GET:(NSString *)path parameters:(id)parameters;

/// A convenience around -HEAD:parameters:success:failure: that returns a cold signal of the
/// resulting JSON object and response headers or error.
- (RACSignal *)rac_HEAD:(NSString *)path parameters:(id)parameters;

/// A convenience around -POST:parameters:success:failure: that returns a cold signal of the
/// result.
- (RACSignal *)rac_POST:(NSString *)path parameters:(id)parameters;

/// A convenience around -POST:parameters:constructingBodyWithBlock:success:failure: that returns a
/// cold signal of the resulting JSON object and response headers or error.
- (RACSignal *)rac_POST:(NSString *)path parameters:(id)parameters constructingBodyWithBlock:(void (^)(id <AFMultipartFormData> formData))block;

/// A convenience around -PUT:parameters:success:failure: that returns a cold signal of the
/// resulting JSON object and response headers or error.
- (RACSignal *)rac_PUT:(NSString *)path parameters:(id)parameters;

/// A convenience around -PATCH:parameters:success:failure: that returns a cold signal of the
/// resulting JSON object and response headers or error.
- (RACSignal *)rac_PATCH:(NSString *)path parameters:(id)parameters;

/// A convenience around -DELETE:parameters:success:failure: that returns a cold signal of the
/// resulting JSON object and response headers or error.
- (RACSignal *)rac_DELETE:(NSString *)path parameters:(id)parameters;

@end

#endif
