//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

@class _BMPFairplayHandler;
@class _BMPRequestMetadata;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_FairplayHandlerDelegate)
@protocol _BMPFairplayHandlerDelegate <NSObject>
/**
 Is called when the BMPFairplayHandler has finished a DRM license request.

 @param sender The BMPFairplayHandler which is calling the delegate method.
 @param metadata The BMPRequestMetadata containing data about the request.
 */
- (void)fairplayHandler:(_BMPFairplayHandler *)sender didFinishDRMLicenseRequestWithMetadata:(_BMPRequestMetadata *)metadata;
/**
 Is called when the BMPFairplayHandler has finished a DRM certificate request.

 @param sender The BMPFairplayHandler which is calling the delegate method.
 @param metadata The BMPRequestMetadata containing data about the request.
 */
- (void)fairplayHandler:(_BMPFairplayHandler *)sender didFinishDRMCertificateRequestWithMetadata:(_BMPRequestMetadata *)metadata;
/**
 Is called when the BMPFairplayHandler has finished with an error.

 @param sender The BMPFairplayHandler which is calling the delegate method.
 @param error The NSError which occurred.
 */
- (void)fairplayHandler:(_BMPFairplayHandler *)sender didFinishWithError:(NSError *)error;
@end

NS_ASSUME_NONNULL_END
