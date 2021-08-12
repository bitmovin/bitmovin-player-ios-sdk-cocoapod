//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPBitmovinCastManagerListener.h>
#import <BitmovinPlayer/BMPGoogleCastReceiverVersion.h>

@protocol GCKSessionManagerListener;
@class GCKMediaInformation;
@class GCKMediaStatus;
@class GCKMediaMetadata;
@class GCKDevice;
@class GCKCastChannel;
@class BMPBitmovinCastManagerOptions;

NS_ASSUME_NONNULL_BEGIN

/**
 * IMPORTANT: Methods from BMPBitmovinCastManager need to be called from the main thread.
 *
 * Singleton providing access to GoogleCast related features. The BMPBitmovinCastManager needs to be initialized by calling
 * BMPBitmovinCastManager#initializeCasting in the AppDelegate of the application which should support casting.
 */
NS_SWIFT_NAME(BitmovinCastManager)
__TVOS_PROHIBITED
@interface BMPBitmovinCastManager : NSObject
@property (nonatomic, readonly, getter=isConnected) BOOL connected;
@property (nonatomic, readonly, getter=isConnecting) BOOL connecting;
@property (nonatomic, readonly, getter=isCastAvailable) BOOL castAvailable;
@property (nonatomic, readonly, nullable) GCKMediaStatus *currentMediaStatus;
@property (nonatomic, readonly, nullable) GCKMediaMetadata *currentMediaMetadata;
@property (nonatomic, readonly, nullable) GCKDevice *currentDevice;
@property (nonatomic, readonly, getter=isPlaying) BOOL playing;
@property (nonatomic, readonly, getter=isPaused) BOOL paused;
@property (nonatomic, readonly, getter=isMuted) BOOL muted;
@property (nonatomic, readonly, getter=isStalled) BOOL stalled;
@property (nonatomic, readonly) NSTimeInterval currentTime;
@property (nonatomic, readonly) NSTimeInterval duration;
@property (nonatomic, readonly, nullable, strong) GCKCastChannel *defaultChannel;
@property (nonatomic, readonly) BMPGoogleCastReceiverVersion castReceiverVersion;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
+ (instancetype)sharedInstance;
+ (BOOL)isInitialized;
/**
 Uses Bitmovin v2 receiver by default
 */
+ (void)initializeCasting;
/**
 Uses Bitmovin v2 or v3 receiver based on castReceiverVersion
 @param castReceiverVersion version of receiver
 */
+ (void)initializeCasting:(BMPGoogleCastReceiverVersion)castReceiverVersion NS_SWIFT_NAME(initializeCasting(castReceiverVersion:)) __deprecated_msg("Use BMPBitmovinCastManager#initializeCasting(options:) instead.");
/**
 Uses given receiver app and assumes it is v2
 @param applicationId ID of receiver application
 @param messageNamespace Custom namespace
 */
+ (void)initializeCasting:(NSString *)applicationId
         messageNamespace:(nullable NSString *)messageNamespace NS_SWIFT_NAME(initializeCasting(applicationId:messageNamespace:))  __deprecated_msg("Use BMPBitmovinCastManager#initializeCasting(options:) instead.");
/**
 Uses given receiver app with given receiver version
 @param applicationId ID of receiver application
 @param castReceiverVersion version of receiver
 */
+ (void)initializeCasting:(NSString *)applicationId
      castReceiverVersion:(BMPGoogleCastReceiverVersion)castReceiverVersion NS_SWIFT_NAME(initializeCasting(applicationId:castReceiverVersion:)) __deprecated_msg("Use BMPBitmovinCastManager#initializeCasting(options:) instead.");
/**
 Uses given receiver app with given receiver version and namespace
 @param applicationId ID of receiver application
 @param castReceiverVersion version of receiver
 @param messageNamespace Custom namespace
 */
+ (void)initializeCasting:(NSString *)applicationId
      castReceiverVersion:(BMPGoogleCastReceiverVersion)castReceiverVersion
         messageNamespace:(nullable NSString *)messageNamespace NS_SWIFT_NAME(initializeCasting(applicationId:castReceiverVersion:messageNamespace:))  __deprecated_msg("Use BMPBitmovinCastManager#initializeCasting(options:) instead.");
/**
 Initialize `BitmovinCastManager` based on the provided `BitmovinCastManagerOptions`.
 @param options `BMPBitmovinCastManagerOptions` to use for initializing `BMPBitmovinCastManager`
 */
+ (void)initializeCastingWithOptions:(BMPBitmovinCastManagerOptions *)options NS_SWIFT_NAME(initializeCasting(options:));
- (void)prepareWithMediaInformation:(GCKMediaInformation *)mediaInformation NS_SWIFT_NAME(prepare(mediaInformation:));
- (void)loadMedia;
- (void)loadMedia:(BOOL)autoplay NS_SWIFT_NAME(loadMedia(autoplay:));
- (void)loadMedia:(BOOL)autoplay position:(NSTimeInterval)position NS_SWIFT_NAME(loadMedia(autoplay:position:));
- (void)unload;
- (void)showDialog;
- (void)addListener:(id<BMPBitmovinCastManagerListener>)listener NS_SWIFT_NAME(add(listener:));
- (void)removeListener:(id<BMPBitmovinCastManagerListener>)listener NS_SWIFT_NAME(remove(listener:));
- (void)play;
- (void)pause;
- (void)seek:(NSTimeInterval)time NS_SWIFT_NAME(seek(time:));

/**
 Sends the given message to the cast receiver.
 The receiver can pick up the message on the namespace returned by defaultChannel.protocolNamespace.

 @param message The message to send.
 @return true if the message could be sent successfully.
 */
- (BOOL)sendMessage:(NSString *)message NS_SWIFT_NAME(sendMessage(_:));
/**
 Sends the given message to the cast receiver on the provided namespace.
 If no namespace is provided, the one returned by defaultChannel.protocolNamespace is used.

 @param message The message to send.
 @param messageNamespace The namespace the message should be send on.
 @return true if the message could be sent successfully.
 */
- (BOOL)sendMessage:(NSString *)message withNamespace:(nullable NSString *)messageNamespace NS_SWIFT_NAME(sendMessage(_:withNamespace:));
/**
 Sends the given metadata wrapped in a metadata message object to the cast receiver on the configured message namespace.
 The provided metadata must be serializable using NSJSONSerialization.

 @param metadata The metadata to send. Must be serializable using NSJSONSerialization.
 @return true if the message could be sent successfully.
 */
- (BOOL)sendMetadata:(NSDictionary *)metadata NS_SWIFT_NAME(send(metadata:));
@end

NS_ASSUME_NONNULL_END
