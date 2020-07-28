//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
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
NS_SWIFT_NAME(CastTimeUpdatedEvent)
@interface BMPCastTimeUpdatedEvent : BMPPlayerEvent
@property (nonatomic, readonly) NSTimeInterval currentTime;
@property (nonatomic, readonly) NSTimeInterval duration;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithCurrentTime:(NSTimeInterval)currentTime duration:(NSTimeInterval)duration NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
