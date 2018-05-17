//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Provides access to DRM scheme UUIDs.
 */
NS_SWIFT_NAME(DRMSystems)
@interface BMPDRMSystems : NSObject
/** UUID for FairPlay Streaming protection system */
@property (class, nonatomic, readonly, copy) NSUUID *fairplayUUID;
/** UUID for Widevine protection system */
@property (class, nonatomic, readonly, copy) NSUUID *widevineUUID;
/** UUID for PlayReady protection system */
@property (class, nonatomic, readonly, copy) NSUUID *playReadyUUID;
/** UUID for ClearKey protection system */
@property (class, nonatomic, readonly, copy) NSUUID *clearKeyUUID;
@end

NS_ASSUME_NONNULL_END
