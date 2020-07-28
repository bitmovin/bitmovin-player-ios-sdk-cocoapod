//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
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
NS_SWIFT_NAME(SourceMetadataChangedEvent)
@interface BMPSourceMetadataChangedEvent : BMPPlayerEvent
/** Contains metadata which was removed */
@property (nonatomic, copy, nullable) NSDictionary<NSString *, id<NSObject, NSCopying>> *from;
/** Contains metadata which was added */
@property (nonatomic, copy, nullable) NSDictionary<NSString *, id<NSObject, NSCopying>> *to;

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithOldMetadata:(nullable NSDictionary<NSString *, id<NSObject, NSCopying>> *)oldMetadata
                        newMetadata:(nullable NSDictionary<NSString *, id<NSObject, NSCopying>> *)newMetadata NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
