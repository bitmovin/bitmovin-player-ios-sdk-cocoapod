//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPPlayerEvent.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * See BMPPlayerListener.h for more information on this event.
 */
NS_SWIFT_NAME(AirPlayChangedEvent)
@interface BMPAirPlayChangedEvent : BMPPlayerEvent
/** Indicates whether AirPlay is active */
@property (nonatomic, readonly, getter=isAirPlayActive) BOOL airPlayActive;
/** Current playback time in seconds. */
@property (nonatomic, readonly) NSTimeInterval time;

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithAirPlayActive:(BOOL)airPlayActive time:(NSTimeInterval)time NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
