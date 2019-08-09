//
//  NSString+ZBExtension.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/9.
//  Copyright © 2019 zzb. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (ZBExtension)

/// 消除收尾空格
- (NSString *)zb_removeBothEndsWhitespace;
/// 消除收尾空格+换行符
- (NSString *)zb_removeBothEndsWhitespaceAndNewline;
// 消除收尾空格
- (NSString *)zb_trimWhitespace;
/// 编码
- (NSString *)zb_URLEncoding;
// 消除所有空格
- (NSString *)zb_trimAllWhitespace;

@end

