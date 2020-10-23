//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <BitmovinPlayer/BitmovinPlayer.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Represents ID3 metadata found in the stream.
 */
NS_SWIFT_NAME(Id3Metadata)
@interface BMPId3Metadata : BMPMetadata
/** Indicates the start time of the metadata in seconds */
@property (nonatomic, readonly) NSTimeInterval startTime;
/// :nodoc:
- (instancetype)initWithEntries:(NSArray<id<BMPMetadataEntry>> *)entries NS_UNAVAILABLE;
/**
 Initializes an instance of BMPId3Metadata with a collection of metadata entries.

 @param entries An NSArray of BMPMetadataEntry.
 @param startTime The start time of the ID3 Metadata.
 @return An instance of BMPId3Metadata.
 */
- (instancetype)initWithEntries:(NSArray<id<BMPMetadataEntry>> *)entries startTime:(NSTimeInterval)startTime NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
