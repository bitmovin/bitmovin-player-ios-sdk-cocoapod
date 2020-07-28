//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <BitmovinPlayer/BMPPlayerEvent.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * See BMPPlayerListener.h for more information on this event.
 */
NS_SWIFT_NAME(PlayingEvent)
@interface BMPPlayingEvent : BMPPlayerEvent
@property (nonatomic, readonly) NSTimeInterval time;

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithTime:(NSTimeInterval)time NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
