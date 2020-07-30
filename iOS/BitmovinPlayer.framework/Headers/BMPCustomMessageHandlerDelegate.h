//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(CustomMessageHandlerDelegate)
/**
 Methods for handling received messages from Bitmovin Web UI
 */
@protocol BMPCustomMessageHandlerDelegate <NSObject>
@optional
/**
 Gets called when a synchronous message was received from the Bitmovin Web UI

 @param message Identifier of the message
 @param data Optional data of the message as string (Can be a serialized object)
 @return Optional return value as string which will be propagates back to the JS counterpart
 */
- (nullable NSString *)receivedSynchronousMessage:(NSString *)message withData:(nullable NSString *)data;

/**
 Gets called when a asynchronous message was received from the Bitmovin Web UI

 @param message Identifier of the message
 @param data Optional data of the message as string (Can be a serialized object)
 */
- (void)receivedAsynchronousMessage:(NSString *)message withData:(nullable NSString *)data;
@end

NS_ASSUME_NONNULL_END
