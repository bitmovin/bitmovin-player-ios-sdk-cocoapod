//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <BitmovinPlayer/BMPMetadataEntry.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(DaterangeMetadataEntry)
@interface BMPDaterangeMetadataEntry : NSObject <BMPMetadataEntry>
/** Indicates the start date of the metadata */
@property (nonatomic, readonly, copy) NSDate *startDate;
/** Indicates the end date of the metadata */
@property (nonatomic, readonly, copy, nullable) NSDate *endDate;
/** An array of AVMetadataItems */
@property (nonatomic, readonly, copy) NSArray<AVMetadataItem *> *items;
/**
 Initializes an instance of BMPDaterangeMetadataEntry with a collection of metadata items.

 @param items An NSArray of AVMetadataItems.
 @param startDate The start date of the collection of AVMetadataItems.
 @param endDate The end date of the collection of AVMetadataItems. If the receiver is intended to represent information about an instantaneous event, the value of endDate should be equal to the value of startDate. A value of nil for endDate indicates that the endDate is indefinite.
 @return An instance of BMPDaterangeMetadataEntry.
 */
- (instancetype)initWithItems:(NSArray<AVMetadataItem *> *)items startDate:(NSDate *)startDate endDate:(nullable NSDate *)endDate;
@end

NS_ASSUME_NONNULL_END
