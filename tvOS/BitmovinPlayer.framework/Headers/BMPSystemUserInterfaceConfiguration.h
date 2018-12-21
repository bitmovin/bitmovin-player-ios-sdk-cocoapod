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
 * An array of text style rules to apply to WebVTT subtitles and other legible text.
 */
@property (nonatomic, nullable, copy) NSArray<AVTextStyleRule *> *subtitleStyles;
@end

NS_ASSUME_NONNULL_END
