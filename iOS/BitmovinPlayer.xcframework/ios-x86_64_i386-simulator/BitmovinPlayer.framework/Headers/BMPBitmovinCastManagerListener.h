//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

@class GCKMediaStatus;
@class GCKMediaMetadata;
@class GCKCastChannel;

NS_ASSUME_NONNULL_BEGIN

/**
 * Listener protocol which can be used to listen to events of the BMPBitmovinCastManager.
 */
NS_SWIFT_NAME(BitmovinCastManagerListener)
__TVOS_PROHIBITED
@protocol BMPBitmovinCastManagerListener <NSObject>
@optional
/**
 * Called when GCKMediaStatus been updated
 * @param mediaStatus The updated GCKMediaStatus object
 */
- (void)updatedMediaStatus:(GCKMediaStatus *)mediaStatus;

/**
 * Called when GCKMediaMetadata has been updated
 * @param mediaMetadata The updated GCKMediaMetadata object
 */
- (void)updatedMediaMetadata:(GCKMediaMetadata *)mediaMetadata;

/**
 * Called when a GCKCastSession session is about to be started or resumed
 */
- (void)applicationWillConnect:(NSString *)deviceName;

/**
 * Called when a GCKCastSession to a cast device has been successfully started or resumed
 * @param deviceName The friendly name of the cast device
 */
- (void)applicationConnected:(NSString *)deviceName;

/**
 * Called when a GCKCastSession has been stopped or suspended.
 */
- (void)applicationDisconnected;

/**
 * Called when availability of cast devices has changed
 * @param castAvailable YES if cast devices are available, NO otherwise
 */
- (void)castAvailableChanged:(BOOL)castAvailable;

/**
 * Called when the current cast channel received a text message
 * @param castChannel the channel which received the message
 * @param textMessage the text message
 */
- (void)castChannel:(GCKCastChannel *)castChannel didReceiveTextMessage:(NSString *)textMessage;
@end

NS_ASSUME_NONNULL_END
