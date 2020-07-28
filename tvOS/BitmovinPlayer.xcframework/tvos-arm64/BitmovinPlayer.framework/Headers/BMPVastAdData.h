//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <BitmovinPlayer/BMPAdData.h>
#import <BitmovinPlayer/BMPAdPricing.h>
#import <BitmovinPlayer/BMPAdSystem.h>
#import <BitmovinPlayer/BMPAdvertiser.h>
#import <BitmovinPlayer/BMPCreative.h>
#import <BitmovinPlayer/BMPAdSurvey.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Holds various additional ad data that's available in the VAST response.
 */
NS_SWIFT_NAME(VastAdData)
@protocol BMPVastAdData <BMPAdData>

/**
 * A common name for the ad. Specified in `InLine.AdTitle` in the VAST response.
 *
 * @return A common name for the ad. Specified in `InLine.AdTitle` in the VAST response.
 */
@property (nonatomic, readonly, nullable) NSString* adTitle;

/**
 * The AdSystem that returned the ad. Specified in `InLine.AdSystem` in the VAST response.
 *
 * @return The AdSystem that returned the ad. Specified in `InLine.AdSystem` in the VAST response.
 * @see BMPAdSystem
 */
@property (nonatomic, readonly, nullable) BMPAdSystem *adSystem;

/**
 * The IDs of the `Wrapper` ads, starting at the `InLine` ad and ending at the outermost `Wrapper` ad. Contains an
 * empty array if there are no `Wrapper` ads.
 *
 * @return The IDs of the `Wrapper` ads, starting at the `InLine` ad and ending at the outermost `Wrapper` ad. Contains an
 * empty array if there are no `Wrapper` ads.
 */
@property (nonatomic, readonly) NSArray<NSString *> *wrapperAdIds;

/**
 * A longer description of the ad. Specified in `InLine.Description` in the VAST response.
 *
 * @return A longer description of the ad. Specified in `InLine.Description` in the VAST response.
 */
@property (nonatomic, readonly, nullable) NSString *adDescription;

/**
 * The Advertiser as defined by the ad serving party. Specified in `InLine.Advertiser` in the VAST response.
 *
 * @return The Advertiser as defined by the ad serving party. Specified in `InLine.Advertiser` in the VAST response.
 * @see BMPAdvertiser
 */
@property (nonatomic, readonly, nullable) BMPAdvertiser *advertiser;

/**
 * Identifies the API needed to execute an interactive media file or communicate with the creative. Specified in
 * `MediaFile.apiFramework` for linear ads or `NonLinear.apiFramework` for non-linear ads in the VAST response.
 *
 * @return Identifies the API needed to execute an interactive media file or communicate with the creative. Specified in
 * `MediaFile.apiFramework` for linear ads or `NonLinear.apiFramework` for non-linear ads in the VAST response.
 */
@property (nonatomic, readonly, nullable) NSString *apiFramework;

/**
 * Contains various data about the Creative. Specified in `InLine.Creative` or `Wrapper.Creative` in the
 * VAST Response.
 *
 * @return Contains various data about the Creative. Specified in `InLine.Creative` or `Wrapper.Creative` in the
 * VAST Response.
 * @see BMPCreative
 */
@property (nonatomic, readonly, nullable) BMPCreative *creative;

/**
 * The media file ID. Specified in `MediaFile.id` in the VAST response.
 *
 * @return The media file ID. Specified in `MediaFile.id` in the VAST response.
 */
@property (nonatomic, readonly, nullable) NSString *mediaFileId;

/**
 * Either 'progressive' for progressive download protocols or 'streaming' for streaming protocols. Specified in
 * `MediaFile.delivery` in the VAST response.
 *
 * @returns either 'progressive' for progressive download protocols or 'streaming' for streaming protocols. Specified in
 * `MediaFile.delivery` in the VAST response.
 */
@property (nonatomic, readonly, nullable) NSString *delivery;

/**
 * The codec used to encode the file which can take values as specified by https://tools.ietf.org/html/rfc4281.
 * Specified in `MediaFile.codec` in the VAST response.
 *
 * @return The codec used to encode the file which can take values as specified by https://tools.ietf.org/html/rfc4281.
 * Specified in `MediaFile.codec` in the VAST response.
 */
@property (nonatomic, readonly, nullable) NSString *codec;

/**
 * The minimum suggested duration that the creative should be displayed. Specified in `NonLinear.minSuggestedDuration`
 * in the VAST response.
 *
 * @return The minimum suggested duration that the creative should be displayed. Specified in `NonLinear.minSuggestedDuration`
 * in the VAST response.
 */
@property (nonatomic, readonly) NSTimeInterval minSuggestedDuration;

/**
 * Used to provide a value that represents an AdPricing information that can be used by real-time bidding (RTB) systems. Specified
 * in `Inline.Pricing` in the VAST response.
 *
 * @return A value that represents an AdPricing information that can be used by real-time bidding (RTB) systems. Specified
 * in `Inline.Pricing` in the VAST response.
 * @see BMPAdPricing
 */
@property (nonatomic, readonly, nullable) BMPAdPricing *pricing;

/**
 * URI to any resource relating to an integrated AdSurvey. Specified in `InLine.Survey` in the VAST response.
 *
 * @return URI to any resource relating to an integrated AdSurvey. Specified in `InLine.Survey` in the VAST response.
 * @see BMPAdSurvey
 */
@property (nonatomic, readonly, nullable) BMPAdSurvey *survey;

@end

NS_ASSUME_NONNULL_END
