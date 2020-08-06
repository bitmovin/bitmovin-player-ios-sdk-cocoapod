//
// Bitmovin Player iOS SDK
// Copyright (C) 2018, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_ErrorFactory)
@interface _BMPErrorFactory : NSObject
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
+ (NSError *)createErrorForMissingKeyInJsonData:(NSString *)key;
+ (NSError *)createJsonDataErrorWithMessage:(nullable NSString *)message;
+ (NSError *)createJsonDeserializationNotImplementedErrorForClass:(NSString *)className;
+ (NSError *)createGeneralErrorWithMessage:(nullable NSString *)message;
+ (NSError *)createGeneralDrmErrorWithMessage:(nullable NSString *)message;
+ (NSError *)createDrmMissingConfigurationErrorWithMessage:(nullable NSString *)userInfo;
+ (NSError *)createDrmCertificateRequestFailedError;
+ (NSError *)createDrmLicenseRequestFailedError;
+ (NSError *)createDrmNoLicenseServerUrlProvidedError;
+ (NSError *)createOfflineInsufficientStorageError;
+ (NSError *)createOfflineFailedPersistingContentKeyError;
+ (NSError *)createOfflineFailedPostProcessingError;
+ (NSError *)createGeneralNetworkErrorWithMessage:(nullable NSString *)message;
@end

NS_ASSUME_NONNULL_END
