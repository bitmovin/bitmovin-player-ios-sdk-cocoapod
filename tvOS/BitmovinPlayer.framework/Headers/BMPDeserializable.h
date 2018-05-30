//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Deserializable)
@protocol BMPDeserializable <NSObject>
/**
 * Converts the given JSON data into an instance of the class which is implementing this protocol.
 *
 * @param jsonData The JSON data which should be converted into an object.
 * @return An instance of the class which is implementing this protocol or nil if an error occurred.
 */
+ (nullable id)fromJsonData:(NSDictionary *)jsonData;
@end

NS_ASSUME_NONNULL_END
