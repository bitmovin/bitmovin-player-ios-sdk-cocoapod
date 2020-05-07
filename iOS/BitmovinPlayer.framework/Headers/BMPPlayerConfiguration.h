//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPConfiguration.h>
#import <BitmovinPlayer/BMPSourceConfiguration.h>
#import <BitmovinPlayer/BMPSourceItem.h>
#import <BitmovinPlayer/BMPStyleConfiguration.h>
#import <BitmovinPlayer/BMPPlaybackConfiguration.h>
#import <BitmovinPlayer/BMPAdvertisingConfiguration.h>
#import <BitmovinPlayer/BMPCastConfiguration.h>
#import <BitmovinPlayer/BMPRemoteControlConfiguration.h>
#import <BitmovinPlayer/BMPAdaptationConfiguration.h>
#import <BitmovinPlayer/BMPNetworkConfiguration.h>
#import <BitmovinPlayer/BMPTweaksConfiguration.h>
#import <BitmovinPlayer/BMPBufferConfiguration.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Contains configuration values regarding the playback behaviour of the player.
 */
NS_SWIFT_NAME(PlayerConfiguration)
@interface BMPPlayerConfiguration : BMPConfiguration
/**
  * A personal key can be found in the bitmovin portal and can be specified here (in addition to the one in the Info.plist)
  * Do not forget to enter all your domains (subdomains are included) in your account.
  *
  * If a license key is set here, it will be used instead of the license key found in Info.plist.
  */
@property (nonatomic, nullable, copy) NSString *key;
/** The BMPSourceConfiguration of this BMPPlayerConfiguration. */
@property (nonatomic, nonnull, strong) BMPSourceConfiguration *sourceConfiguration;
/** The BMPStyleConfiguration of this BMPPlayerConfiguration. */
@property (nonatomic, nonnull, strong) BMPStyleConfiguration *styleConfiguration;
/** The BMPPlaybackConfiguration of this BMPPlayerConfiguration. */
@property (nonatomic, nonnull, strong) BMPPlaybackConfiguration *playbackConfiguration;
/** The BMPAdvertisingConfiguration of this BMPPlayerConfiguration. */
@property (nonatomic, nonnull, strong) BMPAdvertisingConfiguration *advertisingConfiguration __TVOS_PROHIBITED;
/** The BMPCastConfiguration of this BMPPlayerConfiguration. */
@property (nonatomic, nonnull, strong) BMPCastConfiguration *castConfiguration __TVOS_PROHIBITED;
/** The BMPRemoteControlConfiguration of this BMPPlayerConfiguration. */
@property (nonatomic, nonnull, strong) BMPRemoteControlConfiguration *remoteControlConfiguration __TVOS_PROHIBITED;
/** The BMPAdaptationConfiguration of this BMPPlayerConfiguration. */
@property (nonatomic, nonnull, strong) BMPAdaptationConfiguration *adaptationConfiguration;
/** The BMPNetworkConfiguration of this BMPPlayerConfiguration. */
@property (nonatomic, nonnull, strong) BMPNetworkConfiguration *networkConfiguration;
/** The BMPTweaksConfiguration of this BMPPlayerConfiguration. */
@property (nonatomic, nonnull, strong) BMPTweaksConfiguration *tweaksConfiguration;
/** The BMPBufferConfiguration of this BMPPlayerConfiguration. */
@property (nonatomic, nonnull, strong) BMPBufferConfiguration *bufferConfiguration API_AVAILABLE(ios(10.0), tvos(10.0));

/**
 * Get/Set a source item for this PlayerConfiguration. When a source item is set, also a new new SourceConfiguration
 * containing this single source item is created for this PlayerConfiguration.
 */
@property (nonatomic, nullable, strong) BMPSourceItem *sourceItem;

/**
 * Creates and returns a BMPPlayerConfiguration based on the given JSON String.
 *
 * @param jsonString The JSON string representing the BMPPlayerConfiguration.
 */
+ (nullable instancetype)fromJsonString:(NSString *)jsonString error:(NSError **)error;

/**
 * Sets a new source item based on the provided url for this PlayerConfiguration.
 *
 * @param urlString The url to a DASH, HLS or Progressive MP4 source which is used to create a new SourceConfiguration
 * and SourceItem for this PlayerConfiguration.
 */
- (BOOL)setSourceItemWithString:(NSString *)urlString error:(NSError **)error NS_SWIFT_NAME(setSourceItem(urlString:));

/**
 * Sets a new source item based on the provided url for this PlayerConfiguration.
 *
 * @param url The url to a DASH, HLS or Progressive MP4 source which is used to create a new SourceConfiguration
 * and SourceItem for this PlayerConfiguration.
 */
- (BOOL)setSourceItemWithUrl:(NSURL *)url error:(NSError **)error NS_SWIFT_NAME(setSourceItem(url:));
@end

NS_ASSUME_NONNULL_END
