//
//  FBKVOController+ZBExtension.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/10.
//  Copyright © 2019 zzb. All rights reserved.
//

#import <KVOController/KVOController.h>


@interface FBKVOController (ZBExtension)

- (void)zb_observe:(nullable id)object
           keyPath:(NSString *_Nullable)keyPath
             block:(FBKVONotificationBlock _Nullable )block;

- (void)zb_observe:(nullable id)object
           keyPath:(NSString *_Nullable)keyPath
            action:(SEL _Nullable )action;

@end


