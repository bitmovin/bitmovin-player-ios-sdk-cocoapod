//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPCustomMessageHandlerDelegate.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(CustomMessageHandler)
/**
 This class handles all communication between the native environment and the Bitmovin Web UI environment in one place
 */
@interface BMPCustomMessageHandler : NSObject

/**
 Delegate to handle communication from Bitmovin Web UI to native
 */
@property(nonatomic, weak, nullable) id <BMPCustomMessageHandlerDelegate> delegate;

/**
 Calls the registered callback within the NativeCommunicationHandler in the Bitmovin Web UI

 @param message Identifier for the callback which should be called
 */
- (void)sendMessage:(NSString *)message;

/**
 Calls the registered callback within the NativeCommunicationHandler in the Bitmovin Web UI

 @param message Identifier for the callback which should be called
 @param data Payload for the callback
 */
- (void)sendMessage:(NSString *)message withData:(nullable NSString *)data;
@end

NS_ASSUME_NONNULL_END
