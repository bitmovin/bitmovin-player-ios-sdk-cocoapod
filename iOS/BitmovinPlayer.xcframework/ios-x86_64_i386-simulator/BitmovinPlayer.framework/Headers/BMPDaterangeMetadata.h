//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPMetadata.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Represents in-playlist timed metadata.

 @note Only supported starting with iOS 9.3
 */
NS_SWIFT_NAME(DaterangeMetadata)
@interface BMPDaterangeMetadata : BMPMetadata
/** Indicates the start date of the metadata */
@property (nonatomic, readonly, copy) NSDate *startDate;
/** Indicates the end date of the metadata */
@property (nonatomic, readonly, copy, nullable) NSDate *endDate;
/// :nodoc:
- (instancetype)initWithEntries:(NSArray<id<BMPMetadataEntry>> *)entries NS_UNAVAILABLE;
/**
 Initializes an instance of BMPDaterangeMetadata with a collection of metadata entries.

 @param entries An NSArray of BMPMetadataEntries.
 @param startDate The start date of the date range.
 @param endDate The end date of the date range. If the receiver is intended to represent information about an instantaneous event, the value of endDate should be equal to the value of startDate. A value of nil for endDate indicates that the endDate is indefinite.
 @return An instance of BMPDaterangeMetadata.
 */
- (instancetype)initWithEntries:(NSArray<id<BMPMetadataEntry>> *)entries startDate:(NSDate *)startDate endDate:(nullable NSDate *)endDate NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
