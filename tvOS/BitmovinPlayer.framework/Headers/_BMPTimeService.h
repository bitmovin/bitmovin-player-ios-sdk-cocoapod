//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import "_BMPService.h"
#import <BitmovinPlayer/BMPTimeMode.h>

NS_ASSUME_NONNULL_BEGIN

/// :nodoc:
NS_SWIFT_NAME(_TimeService)
@protocol _BMPTimeService <_BMPService>
/**
 * Returns the current playback time of the asset. It never returns NAN as a value.
 * In case of invalid time values 0 is returned.
 * For VoD streams the returned time ranges between 0 and the duration of the asset.
 * For live streams it can be specified if a Unix timestamp denoting the current playback position or an relative to the playback start value is returned.
 *
 * @param timeMode to specify if an absolute unix timestamp or an relative time should be returned.
 * @return the current playback time.
 */
- (NSTimeInterval)currentTime:(BMPTimeMode)timeMode;
/**
 * Returns the current playback time in seconds.
 * For VoD streams the returned time ranges between 0 and the duration of the asset.
 * For live streams the playback time is a positive value denoting the offset from the the beginning of the live window
 * (oldest data). The time of the beginning of the live window starts at 0 when playback is initiated and increases in
 * real time as playback continues.
 *
 * @return the current playback time in seconds
 */
- (NSTimeInterval)currentPlaybackTime;
- (NSTimeInterval)duration;
- (NSTimeInterval)maxTimeShift;
- (NSTimeInterval)timeShift;
- (NSTimeInterval)liveEdge;
@end

NS_ASSUME_NONNULL_END
