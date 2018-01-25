//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

@class BMPOfflineManager;

NS_ASSUME_NONNULL_BEGIN

/**
 * Protocol for listeners for the BMPOfflineManager.
 */
NS_SWIFT_NAME(OfflineManagerListener)
@protocol BMPOfflineManagerListener <NSObject>
/**
 * Is called when the download of the media content failed.
 *
 * @param offlineManager The BMPOfflineManager calling the listener.
 * @param error An optional error object describing the cause of the failure.
 */
- (void)offlineManager:(BMPOfflineManager *)offlineManager didFailWithError:(nullable NSError *)error;
/**
 * Is called when the download of the media content was successful.
 *
 * @param offlineManager The BMPOfflineManager calling the listener.
 */
- (void)offlineManagerDidFinishDownload:(BMPOfflineManager *)offlineManager;
/**
 * Is called then the download of the media content progressed to a new percentage value.
 *
 * @param offlineManager The BMPOfflineManager calling the listener.
 * @param progress The percentage of completion for the current download task.
 */
- (void)offlineManager:(BMPOfflineManager *)offlineManager didProgressTo:(double)progress;
@end

NS_ASSUME_NONNULL_END
