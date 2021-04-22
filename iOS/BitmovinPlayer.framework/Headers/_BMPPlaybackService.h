//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import "_BMPService.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_PlaybackService)
@protocol _BMPPlaybackService <_BMPService>
@property (nonatomic) NSInteger volume;
@property (nonatomic) float playbackSpeed;
@property (nonatomic) NSUInteger maxSelectableBitrate;
@property (nonatomic, readonly) float currentVideoFrameRate;
@property (nonatomic, readonly, getter=isSeeking) BOOL seeking;
@property (nonatomic, readonly) BOOL isWaiting;

- (void)play;
- (void)pause;
- (void)seek:(NSTimeInterval)time;
- (BOOL)isMuted;
- (BOOL)isPaused;
- (BOOL)isPlaying;
- (BOOL)isStalled;
- (void)mute;
- (void)unmute;
- (BOOL)isLive;
- (void)timeShift:(NSTimeInterval)offset;
- (BOOL)isAirPlayActive;
- (BOOL)isAirPlayAvailable;
@end

NS_ASSUME_NONNULL_END
