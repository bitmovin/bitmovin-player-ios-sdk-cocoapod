//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPJsonable.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Quality definition of a media representation.

 @note This class acts as an abstract class.
 */
NS_SWIFT_NAME(Quality)
@interface BMPQuality : NSObject <BMPJsonable>
/** The unique identifier of the quality. */
@property (nonatomic, copy, readonly) NSString *identifier;
/** The label of the media representation that should be exposed to the user (e.g. in the UI). */
@property (nonatomic, copy, readonly) NSString *label;
/** The bitrate of the media representation in bits per second (bps). */
@property (nonatomic, readonly) NSUInteger bitrate;

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
/// :nodoc:
- (instancetype)initWithIdentifier:(NSString *)identifier
                             label:(NSString *)label
                           bitrate:(NSUInteger)bitrate NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
