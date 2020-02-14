//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPPlayerEvent.h>
#import <BitmovinPlayer/BMPAdQuartile.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * See BMPPlayerListener.h for more information on this event.
 */
NS_SWIFT_NAME(AdQuartileEvent)
@interface BMPAdQuartileEvent : BMPPlayerEvent
@property (nonatomic, readonly) BMPAdQuartile adQuartile;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithQuartile:(BMPAdQuartile)adQuartile NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
