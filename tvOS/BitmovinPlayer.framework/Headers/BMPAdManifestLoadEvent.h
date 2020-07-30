//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPAdBreakEvent.h>
#import <BitmovinPlayer/BMPAdConfig.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * See BMPPlayerListener.h for more information on this event.
 */
NS_SWIFT_NAME(AdManifestLoadEvent)
@interface BMPAdManifestLoadEvent : BMPPlayerEvent
/**
 * Returns the `AdConfig` this event is related to.
 *
 * @return The `AdConfig` this event is related to.
 */
@property(nonatomic, readonly, copy, nullable) id <BMPAdConfig> adConfig;
/**
 * Returns the `AdBreak` this event is related to.
 *
 * @return The `AdBreak` this event is related to.
 */
@property (nonatomic, readonly, nullable) id <BMPAdBreak> adBreak;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithAdConfig:(nullable id <BMPAdConfig>)adConfig
                         adBreak:(nullable id <BMPAdBreak>)adBreak NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
