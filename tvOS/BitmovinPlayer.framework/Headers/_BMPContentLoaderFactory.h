//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
@protocol BMPContentLoader;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_ContentLoaderFactory)
@protocol _BMPContentLoaderFactory <NSObject>
- (id<BMPContentLoader>)createContentLoader;
@end

NS_ASSUME_NONNULL_END
