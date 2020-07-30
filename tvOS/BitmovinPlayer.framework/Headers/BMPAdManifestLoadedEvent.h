//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPAdBreakEvent.h>
#import <BitmovinPlayer/BMPAdConfig.h>
#import <BitmovinPlayer/BMPAdBreak.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * See BMPPlayerListener.h for more information on this event.
 */
NS_SWIFT_NAME(AdManifestLoadedEvent)
@interface BMPAdManifestLoadedEvent : BMPPlayerEvent
@property (nonatomic, readonly) NSTimeInterval downloadTime;
@property (nonatomic, readonly, copy, nullable) id<BMPAdConfig> adConfig;
/**
 * Returns the `AdBreak` this event is related to.
 *
 * @return The `AdBreak` this event is related to.
 */
@property (nonatomic, readonly, nullable) id<BMPAdBreak> adBreak;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithDownloadTime:(NSTimeInterval)downloadTime
                             adBreak:(nullable id<BMPAdBreak>)adBreak
                            adConfig:(nullable id<BMPAdConfig>)adConfig NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
