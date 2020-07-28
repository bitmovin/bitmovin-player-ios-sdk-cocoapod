//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_JsonHelper)
@interface _BMPJsonHelper : NSObject
/**
 * Serializes the given JSON data into a JSON string.
 *
 * @param data The JSON data as an NSDictionary which should be serialized.
 * @param error The error which will be set in case of an error.
 * @return The serialized JSON string or nil if an error occurred.
 */
+ (nullable NSString *)toJSON:(NSDictionary *)data error:(NSError **)error;
/**
 * Deserializes the given JSON string into a NSDictionary holding the JSON data.
 *
 * @param jsonString The JSON string which should be deserialized into a NSDictionary.
 * @param error The error which will be set in case of an error.
 * @return The deserialized JSON data as a NSDictionary or nil if an error occurred.
 */
+ (nullable NSDictionary *)fromJSON:(NSString *)jsonString error:(NSError **)error;
/**
 * Cleans the given JSON data from invalid values:
 * - Removes [NSNull null] values
 * - Replaces the value INFINITY with the String "Infinity"
 * - Removes the value NaN
 * - Removes values with types which are not serializable to json
 *
 * @param data The JSON data which should be cleaned.
 * @return The cleaned JSON data.
 */
+ (nullable NSDictionary *)removeInvalidValuesFromJSONData:(NSDictionary *)data;
@end

NS_ASSUME_NONNULL_END
