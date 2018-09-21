//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPJsonable.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Contains configuration values regarding the behaviour of the bitrate adaptation.
 */
NS_SWIFT_NAME(AdaptationConfiguration)
@interface BMPAdaptationConfiguration : NSObject <BMPJsonable>
/**
 * The upper bitrate boundary in bits per second for network bandwidth consumption of the played source. Can be set to
 * 0 for no limitation.
 *
 * Default value is 0.
 */
@property (nonatomic) NSUInteger maxSelectableBitrate;

@end

NS_ASSUME_NONNULL_END
