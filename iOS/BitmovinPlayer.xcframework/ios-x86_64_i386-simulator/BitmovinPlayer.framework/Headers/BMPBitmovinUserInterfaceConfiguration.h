//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <BitmovinPlayer/BMPUserInterfaceConfiguration.h>
#import <BitmovinPlayer/BMPCustomMessageHandler.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(BitmovinUserInterfaceConfiguration)
@interface BMPBitmovinUserInterfaceConfiguration : BMPUserInterfaceConfiguration
/**
 Handles the communication with the Bitmovin Web UI in both directions
 */
@property(nonatomic, nullable) BMPCustomMessageHandler *customMessageHandler;
/**
 When set to YES the first frame of the main content will not be rendered before playback starts
 Default: NO

 @note To reliably hide the first frame before a pre-roll ad, please ensure that you are using the AdvertisingConfiguration to schedule ads and not the scheduleAd API call
 */
@property (nonatomic) BOOL hideFirstFrame;
@end

NS_ASSUME_NONNULL_END
