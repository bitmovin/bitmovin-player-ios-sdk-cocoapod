//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import "_BMPServiceType.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_Service)
@protocol _BMPService <NSObject>
@property (nonatomic, readonly, getter=isRunning) BOOL running;
@property (nonatomic, readonly) _BMPServiceType type;

- (void)start;
- (void)stop;
@end

NS_ASSUME_NONNULL_END
