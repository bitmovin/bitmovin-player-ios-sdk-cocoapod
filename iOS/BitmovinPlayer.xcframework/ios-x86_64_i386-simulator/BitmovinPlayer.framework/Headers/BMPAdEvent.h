//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPPlayerEvent.h>
#import "BMPAd.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Base class for ad related event classes.
 */
NS_SWIFT_NAME(AdEvent)
@interface BMPAdEvent : BMPPlayerEvent
@property (nonatomic, readonly) id<BMPAd> ad;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithAd:(id<BMPAd>)ad;
@end

NS_ASSUME_NONNULL_END
