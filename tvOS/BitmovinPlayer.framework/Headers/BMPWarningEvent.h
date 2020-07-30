//
// Bitmovin Player iOS SDK
// Copyright (C) 2018, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPPlayerEvent.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * See BMPPlayerListener.h for more information on this event.
 */
NS_SWIFT_NAME(WarningEvent)
@interface BMPWarningEvent : BMPPlayerEvent
@property (nonatomic, readonly) NSUInteger code;
@property (nonatomic, copy, readonly) NSString *message;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

/**
 Creates a new BMPWarningEvent based on the given code and message. Supported codes are defined in BMPWarningCodes.h.

 @param code The code for this warning.
 @param message The message for this warning.
 @return A new warning event initialized with the given code and message.
 */
- (instancetype)initWithCode:(NSUInteger)code message:(NSString *)message NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
