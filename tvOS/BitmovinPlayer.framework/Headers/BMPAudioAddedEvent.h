//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPPlayerEvent.h>
#import <BitmovinPlayer/BMPAudioTrack.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * See BMPPlayerListener.h for more information on this event.
 */
NS_SWIFT_NAME(AudioAddedEvent)
@interface BMPAudioAddedEvent : BMPPlayerEvent
/** The added BMPAudioTrack */
@property (nonatomic, strong, readonly) BMPAudioTrack *audioTrack;
/** The current playback time (in seconds) */
@property (nonatomic, readonly) NSTimeInterval time;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithAudioTrack:(BMPAudioTrack *)audioTrack time:(NSTimeInterval)time NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
