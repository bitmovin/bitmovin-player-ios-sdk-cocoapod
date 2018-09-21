//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPAdItem.h>
#import <BitmovinPlayer/BMPConfiguration.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Contains configuration values regarding the ads which should be played back by the player.
 */
NS_SWIFT_NAME(AdvertisingConfiguration)
__TVOS_PROHIBITED
@interface BMPAdvertisingConfiguration : BMPConfiguration

/**
 * Contains one or more AdItem(s). Each AdItem defines when the specified ad shall be played.
 *
 * @see BMPAdItem
 */
@property (nonatomic, readonly, copy) NSArray<BMPAdItem *> *schedule;

/**
 * Creates a new AdvertisingConfiguration with the given ad schedule.
 *
 * @param schedule The ad schedule which will be used within this AdvertisingConfiguration.
 * @return The newly created AdvertisingConfiguration.
 */
- (instancetype)initWithSchedule:(NSArray<BMPAdItem *> *)schedule;

@end

NS_ASSUME_NONNULL_END

