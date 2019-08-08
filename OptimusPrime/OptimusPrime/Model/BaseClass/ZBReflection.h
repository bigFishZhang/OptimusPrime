//
//  ZBReflection.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/8.
//  Copyright © 2019 zzb. All rights reserved.
//

#import <Foundation/Foundation.h>

// Creates a selector from a key and a constant string.
//
// key    - The key to insert into the generated selector. This key should be in
//          its natural case.
// suffix - A string to append to the key as part of the selector.
//
// Returns a selector, or NULL if the input strings cannot form a valid
// selector.
SEL ZBSelectorWithKeyPattern(NSString *key, const char *suffix) __attribute__((pure, nonnull(1, 2)));

// Creates a selector from a key and a constant prefix and suffix.
//
// prefix - A string to prepend to the key as part of the selector.
// key    - The key to insert into the generated selector. This key should be in
//          its natural case, and will have its first letter capitalized when
//          inserted.
// suffix - A string to append to the key as part of the selector.
//
// Returns a selector, or NULL if the input strings cannot form a valid
// selector.
SEL ZBSelectorWithCapitalizedKeyPattern(const char *prefix, NSString *key, const char *suffix) __attribute__((pure, nonnull(1, 2, 3)));
