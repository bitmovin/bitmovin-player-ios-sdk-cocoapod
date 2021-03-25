//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPSourceItem.h>
#import <BitmovinPlayer/BMPRemoteControlType.h>
#import <BitmovinPlayer/BMPConfiguration.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Contains configuration values which can be used to alter the behaviour of the player when it comes to remote playback.
 */
NS_SWIFT_NAME(RemoteControlConfiguration)
@interface BMPRemoteControlConfiguration : BMPConfiguration
/** A URL to a CSS file the Chromecast receiver app loads. Can be used to style the receiver app. */
@property (nonatomic, copy, nullable) NSURL *receiverStylesheetUrl;
/** Arbitrary configuration values that are sent to the remote control receiver. */
@property (nonatomic, strong) NSMutableDictionary<NSString *, NSString *> *customReceiverConfiguration;
/**
 * This block can be used to prepare a different BMPSourceConfiguration to be used for remote playback that for local
 * playback. This can be useful when the remote playback device supports different streaming formats, DRM systems, etc.
 * than the local device.
 */
@property (nonatomic, copy, nullable) BMPSourceItem * __nullable (^prepareSource)(BMPRemoteControlType type, BMPSourceItem *sourceItem);
/**
 * Indicates whether the player should automatically switch to "external playback" mode while the "external
 * screen" mode is active in order to play video content and switch back to "external screen" mode as soon
 * as playback is done.
 * Brief transition may be visible on the external display when automatically switching between the two modes.
 * Default value is NO.
 *
 * NOTE: This is only supported with AirPlay.
 */
@property (nonatomic, assign) BOOL usesExternalPlaybackWhileExternalScreenIsActive;

/**
 * Indicates whether cookies and credentials will be sent along manifest requests on the Cast receiver
 *
 * Default value is NO.
 * NOTE: This is only supported with CAF (v3) receivers.
 */
@property (nonatomic, assign) BOOL sendManifestRequestsWithCredentials;
/**
 * Indicates whether cookies and credentials will be sent along segment requests on the Cast receiver
 *
 * Default value is NO.
 * NOTE: This is only supported with CAF (v3) receivers.
 */
@property (nonatomic, assign) BOOL sendSegmentRequestsWithCredentials;
/**
 * Indicates whether cookies and credentials will be sent along DRM licence requests on the Cast receiver
 *
 * Default value is NO.
 * NOTE: This is only supported with CAF (v3) receivers.
 */
@property (nonatomic, assign) BOOL sendDrmLicenseRequestsWithCredentials;
@end
NS_ASSUME_NONNULL_END
