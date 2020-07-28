//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPMetadataEntry.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Describes default properties of the custom SCTE35 tag from the playlist.
 */
NS_SWIFT_NAME(ScteMetadataEntry)
@interface BMPScteMetadataEntry : NSObject <BMPMetadataEntry>

/**
 Key of the SCTE35 attribute.
 */
@property (strong, nonatomic, readonly) NSString *key;

/**
 Value of the SCTE35 attribute.
 */
@property (nullable, strong, nonatomic, readonly) NSString *value;

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithKey:(NSString *)key value:(nullable NSString *)value NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
