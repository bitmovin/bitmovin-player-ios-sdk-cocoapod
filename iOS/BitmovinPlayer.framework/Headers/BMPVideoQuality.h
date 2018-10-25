//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPQuality.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(VideoQuality)
@interface BMPVideoQuality : BMPQuality
/** The width of the video representation. */
@property (nonatomic, readonly) NSUInteger width;
/** The height of the video representation. */
@property (nonatomic, readonly) NSUInteger height;
/// :nodoc:
- (instancetype)initWithIdentifier:(NSString *)identifier
                             label:(NSString *)label
                           bitrate:(NSUInteger)bitrate NS_UNAVAILABLE;
/**
 Creates a new BMPVideoQuality based on the provided data.

 @param identifier The unique identifier of the current media representation.
 @param label The label of the media representation that should be exposed to the user (e.g. in the UI).
 @param bitrate The bitrate of the media representation.
 @param width The width of the video representation.
 @param height The height of the video representation.
 @return A new video quality representation initialized with the provided data.
 */
- (instancetype)initWithIdentifier:(NSString *)identifier
                             label:(NSString *)label
                           bitrate:(NSUInteger)bitrate
                             width:(NSUInteger)width
                            height:(NSUInteger)height NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
