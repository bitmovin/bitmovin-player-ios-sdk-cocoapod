//
// Bitmovin Player iOS SDK
// Copyright (C) 2021, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <AVFoundation/AVFoundation.h>
#import <AVKit/AVKit.h>
#import <BitmovinPlayer/BMPBitmovinPlayer.h>
#import <BitmovinPlayer/BMPPlayerConfiguration.h>
#import <BitmovinPlayer/_BMPIntegrationLanguage.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_InternalPlayerFactory)
@interface _BMPInternalPlayerFactory : NSObject
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
+ (BMPBitmovinPlayer *)createWithIntegrationLanguage:(_BMPIntegrationLanguage)integrationLanguage
                                 playerConfiguration:(BMPPlayerConfiguration *)playerConfiguration NS_SWIFT_NAME(create(integrationLanguage:playerConfiguration:));
+ (BMPBitmovinPlayer *)createWithIntegrationLanguage:(_BMPIntegrationLanguage)integrationLanguage;
@end

NS_ASSUME_NONNULL_END
