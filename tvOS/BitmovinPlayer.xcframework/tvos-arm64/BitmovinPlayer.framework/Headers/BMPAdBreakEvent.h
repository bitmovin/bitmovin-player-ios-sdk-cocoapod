//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//


#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPPlayerEvent.h>
#import <BitmovinPlayer/BMPAdBreak.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Base class for ad break related event classes.
 */
NS_SWIFT_NAME(AdBreakEvent)
@interface BMPAdBreakEvent : BMPPlayerEvent

/**
 * Returns the `AdBreak` this event is related to.
 *
 * @return The `AdBreak` this event is related to.
 */
@property (nonatomic, readonly) id<BMPAdBreak> adBreak;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithAdBreak:(id<BMPAdBreak>)adBreak;
@end

NS_ASSUME_NONNULL_END
