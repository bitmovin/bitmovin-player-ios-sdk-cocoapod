//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPBitmovinCastManagerListener.h>

@protocol GCKSessionManagerListener;
@class GCKMediaInformation;
@class GCKMediaStatus;
@class GCKMediaMetadata;
@class GCKDevice;
@class GCKCastChannel;

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

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
+ (instancetype)sharedInstance;
+ (BOOL)isInitialized;
+ (void)initializeCasting;
+ (void)initializeCasting:(NSString *)applicationId messageNamespace:(nullable NSString *)messageNamespace NS_SWIFT_NAME(initializeCasting(applicationId:messageNamespace:));

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
@end

NS_ASSUME_NONNULL_END
