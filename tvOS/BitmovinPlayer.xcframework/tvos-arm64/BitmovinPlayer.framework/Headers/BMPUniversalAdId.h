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
 * Describes a unique creative identifier that is maintained across systems. Specified in `Creative.UniversalAdId` in the
 * VAST response.
 */
NS_SWIFT_NAME(UniversalAdId)
@interface BMPUniversalAdId : NSObject <BMPJsonable>

/**
 * The registry website where the unique creative ID is cataloged. Default value is 'unknown'.
 *
 * @return The registry website where the unique creative ID is cataloged. Default value is 'unknown'.
 */
@property (nonatomic, readonly) NSString *idRegistry;

/**
 * The unique creative identifier. Default value is 'unknown'.
 *
 * @return The unique creative identifier. Default value is 'unknown'.
 */
@property (nonatomic, readonly) NSString *value;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithIdRegistry:(NSString *)idRegistry
                             value:(NSString *)value NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
