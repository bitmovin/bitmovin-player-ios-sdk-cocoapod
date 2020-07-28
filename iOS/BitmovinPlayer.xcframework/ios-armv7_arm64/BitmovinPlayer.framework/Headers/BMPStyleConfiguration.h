//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPConfiguration.h>
#import <BitmovinPlayer/BMPUserInterfaceType.h>
#import <BitmovinPlayer/BMPScalingMode.h>
#import <BitmovinPlayer/BMPUserInterfaceConfiguration.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Contains configuration values which can be used to alter the visual presentation and behaviour of the player UI.
 */
NS_SWIFT_NAME(StyleConfiguration)
@interface BMPStyleConfiguration : BMPConfiguration

/**
 * Sets if the the UI should be enabled or not. Default value is YES.
 */
@property (nonatomic, getter=isUiEnabled) BOOL uiEnabled;
/**
 * Set which user interface type should be used. Default value is BMPUserInterfaceTypeBitmovin on iOS and
 * BMPUserInterfaceTypeSystem on tvOS. This setting only applies if BMPStyleConfiguration#uiEnabled is set to YES.
 */
@property (nonatomic) BMPUserInterfaceType userInterfaceType;
/**
 * Set the CSS file that will be used for the UI. The default CSS file will be completely replaced by the CSS file
 * set with this property.
 */
@property (nonatomic, copy) NSURL *playerUiCss;
/**
 * Set a CSS file which contains supplemental styles for the player UI. These styles will be added to the default CSS
 * file or the CSS file set with BMPStyleConfiguration#playerUiCss.
 */
@property (nonatomic, copy, nullable) NSURL *supplementalPlayerUiCss;
/**
 * Sets the JS file that will be used for the UI. The default JS file will be completely replaced by the JS file
 * set with this property.
 */
@property (nonatomic, copy) NSURL *playerUiJs;
/**
 * Determines how the video content is scaled or stretched within the parent container's bounds.
 * Possible values are defined in BMPScalingMode. Default value is BMPScalingModeFit.
 */
@property (nonatomic) BMPScalingMode scalingMode;
/**
 * An optional configuration object, containing configuration values which apply to the selected user interface type.
 * - When BMPUserInterfaceTypeSystem is selected, a BMPSystemUserInterfaceConfiguration can be set.
 * - When BMPUserInterfaceTypeSubtitle is selected, a BMPSubtitleUserInterfaceConfiguration can be set.
 */
@property (nonatomic, nullable, strong) BMPUserInterfaceConfiguration *userInterfaceConfiguration;

@end

NS_ASSUME_NONNULL_END
