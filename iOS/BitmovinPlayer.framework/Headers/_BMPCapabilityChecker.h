//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPMediaSourceType.h>
#import <BitmovinPlayer/BMPSourceItem.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_CapabilityChecker)
@interface _BMPCapabilityChecker : NSObject
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
/**
 * Returns the preferred stream type for the current platform
 */
+ (BMPMediaSourceType)preferredStreamTypeForSourceItem:(BMPSourceItem *)sourceItem;
@end

NS_ASSUME_NONNULL_END
