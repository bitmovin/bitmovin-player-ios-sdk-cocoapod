//
// Bitmovin Player iOS SDK
// Copyright (C) 2018, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPUserInterfaceConfiguration.h>
#import <AVFoundation/AVTextStyleRule.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(SystemUserInterfaceConfiguration)
@interface BMPSystemUserInterfaceConfiguration : BMPUserInterfaceConfiguration
/**
 An array of text style rules to apply to WebVTT subtitles and other legible text.
 */
@property (nonatomic, nullable, copy) NSArray<AVTextStyleRule *> *subtitleStyles;
/**
 Indicates whether to show the 'Auto' option when choosing subtitles or not.
 Defaults to YES.

 @note This property is only available on tvOS
 */
@property (nonatomic) BOOL showAutoSubtitleOption API_UNAVAILABLE(ios) API_AVAILABLE(tvos(9.0));
/**
 When set to YES the first frame of the main content will not be rendered before playback starts
 Default: NO

 @note To reliably hide the first frame before a pre-roll ad, please ensure that you are using the AdvertisingConfiguration to schedule ads and not the scheduleAd API call
 */
@property (nonatomic) BOOL hideFirstFrame;
/**
 Indicates whether to show the seek bar and related controls during user interaction.
 Default is `YES`.

 @note Depending on the tvOS version this property has a different behaviour:

 - On tvOS 14 and below it controls the seek bar visibility.
 Set this property to NO to selectively prevent the seek bar from being displayed during user interaction.

 - On tvOS 15 and above it controls the seek bar and audio/subtitle track selection views visibility.
 Set this property to NOto selectively prevent the seek bar and audio/subtitle track selection views from being displayed during user interaction.

 This property is only available on tvOS.
 The new tvOS 15 System UI is only used when the app is built using Xcode 13.
 */
@property (nonatomic) BOOL showSeekBar API_UNAVAILABLE(ios) API_AVAILABLE(tvos(11.0));
/**
 Indicates whether to show the views for video metadata, navigation markers and playback settings when requested by the user.
 Default is `YES`.

 @note Depending on the tvOS version this property has a different behaviour:

 - On tvOS 14 and below it controls the visibility of the info views which contains the media information and audio/subtitle track selection.
 If no `AVNavigationMarkersGroup` or `AVMetadataItem` are set, only the audio/subtitle selection view is shown.

 - On tvOS 15 and above it controls the visibility of the info views which contains the media information and chapters if `AVNavigationMarkersGroup` are configured. (The audio/subtitle selected was removed from the info view)
 If no `AVNavigationMarkersGroup` or `AVMetadataItem` are set, the info view isn't shown.

 Set this property to NO to selectively prevent the info views from being displayed during user interaction.

 This property is only available on tvOS.
 The new tvOS 15 System UI is only used when the app is built using Xcode 13.
 */
@property (nonatomic) BOOL showInfoViews API_UNAVAILABLE(ios) API_AVAILABLE(tvos(11.0));
@end

NS_ASSUME_NONNULL_END
