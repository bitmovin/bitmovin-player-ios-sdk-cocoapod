//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// :nodoc:
@interface NSURL (BMPAdditions)
@property (nonatomic, readonly, copy) NSString *_bmp_relativePathToHomeDirectory;
@property (nonatomic, readonly) BOOL _bmp_isSkdScheme;
@property (nonatomic, readonly) BOOL _bmp_isBitmovinScheme;
@property (nonatomic, readonly) BOOL _bmp_isRelative;
@property (nonatomic, readonly) BOOL _bmp_isAbsolute;

- (NSURL *)_bmp_UrlByChangingSchemeToBitmovin;
- (NSURL *)_bmp_UrlByChangingSchemeToHttp;
- (NSURL *)_bmp_absoluteUrlWithBaseUrl:(NSURL *)baseUrl;
@end

NS_ASSUME_NONNULL_END
