//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <BitmovinPlayer/BitmovinPlayer.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Represents the SCTE-35 metadata from the media playlist.
 */
NS_SWIFT_NAME(ScteMetadata)
@interface BMPScteMetadata : BMPMetadata
/** Indicates the start time of the metadata in seconds */
@property (nonatomic, readonly) NSTimeInterval startTime;
/// :nodoc:
- (instancetype)initWithEntries:(NSArray<id<BMPMetadataEntry>> *)entries NS_UNAVAILABLE;
/**
 Initializes an instance of BMPScteMetadata with a collection of metadata entries.

 @param entries An NSArray of BMPMetadataEntry.
 @param startTime The start time of the SCTE Metadata.
 @return An instance of BMPScteMetadata.
 */
- (instancetype)initWithEntries:(NSArray<id<BMPMetadataEntry>> *)entries startTime:(NSTimeInterval)startTime NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
