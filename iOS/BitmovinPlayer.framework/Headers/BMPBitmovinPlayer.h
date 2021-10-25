//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <AVFoundation/AVFoundation.h>
#import <BitmovinPlayer/BMPPlayerAPI.h>
#import <BitmovinPlayer/BMPPlayerEventHandler.h>
#import <BitmovinPlayer/BMPRemoteControlAPI.h>
#import <BitmovinPlayer/BMPPlayerConfiguration.h>
#import <BitmovinPlayer/_BMPIntegrationLanguage.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * This class represents the player itself. It implements the BMPPlayerAPI and BMPRemoteControlAPI which can be used to
 * control the player. It also implements the BMPPlayerEventHandler interface which enables adding and removing of event listeners
 * to this player instance. This player does not come with an UI, it represents only the player logic. If you wish to use the
 * player along with an UI please use BMPBitmovinPlayerView.
 */
NS_SWIFT_NAME(Player)
@interface BMPBitmovinPlayer : NSObject <BMPPlayerAPI, BMPPlayerEventHandler, BMPRemoteControlAPI>
- (instancetype)init __deprecated_msg("Use BMPPlayerFactory#create() instead. This will be removed in v3.");
+ (instancetype)new __deprecated_msg("Use BMPPlayerFactory#create() instead. This will be removed in v3.");
- (instancetype)initWithConfiguration:(BMPPlayerConfiguration *)configuration __deprecated_msg("Use BMPPlayerFactory#createWithPlayerConfiguration(playerConfiguration:) instead. This will be removed in v3.");
@end

NS_ASSUME_NONNULL_END
