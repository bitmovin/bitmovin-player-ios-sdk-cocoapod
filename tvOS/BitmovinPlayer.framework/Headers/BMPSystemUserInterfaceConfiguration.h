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

 @note This flag is only available on tvOS
 */
@property (nonatomic) BOOL showAutoSubtitleOption API_UNAVAILABLE(ios) API_AVAILABLE(tvos(9.0));
@end

NS_ASSUME_NONNULL_END
