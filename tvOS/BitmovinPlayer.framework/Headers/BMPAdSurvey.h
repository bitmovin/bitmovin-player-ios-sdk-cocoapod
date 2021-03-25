//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <BitmovinPlayer/BMPJsonable.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A string representation of a URI to any resource relating to an integrated survey. Specified in `InLine.Survey` in the VAST response.
 */
NS_SWIFT_NAME(AdSurvey)
@interface BMPAdSurvey : NSObject <BMPJsonable>

/**
 * A string representation of a URI to any resource relating to an integrated survey.
 *
 * @return A string representation of a URI  to any resource relating to an integrated survey.
 */
@property (nonatomic, readonly) NSString *uri;

/**
 * The MIME type of the resource being served.
 *
 * @return The MIME type of the resource being served.
 */
@property (nonatomic, readonly, nullable) NSString *type;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithUri:(NSString *)uri
                       type:(nullable NSString *)type NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
