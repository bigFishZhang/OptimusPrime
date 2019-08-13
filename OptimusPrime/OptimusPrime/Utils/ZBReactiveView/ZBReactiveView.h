//
//  ZBReactiveView.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/13.
//  Copyright © 2019 zzb. All rights reserved.
//

#import <Foundation/Foundation.h>

/// A protocol which is adopted by views which are backed by view models.
@protocol ZBReactiveView <NSObject>

/// Binds the given view model to the view.
///
/// viewModel - The view model
- (void)bindViewModel:(id)viewModel;

@end
