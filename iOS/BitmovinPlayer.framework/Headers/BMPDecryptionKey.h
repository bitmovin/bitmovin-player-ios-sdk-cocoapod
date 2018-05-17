//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPJsonable.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(DecryptionKey)
@interface BMPDecryptionKey : NSObject <NSCopying, BMPJsonable>
/** The KID for the decryption key in hex string format (Optional). */
@property (nonatomic, copy, nullable) NSString *kid;
/** The decryption key in hex string format. */
@property (nonatomic, copy, nonnull) NSString *key;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithKid:(nullable NSString *)kid key:(NSString *)key NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
