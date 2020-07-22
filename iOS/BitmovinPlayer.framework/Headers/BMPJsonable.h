//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Provides methods to serialize objects to JSON strings.
 */
@protocol BMPJsonable <NSObject>
/**
 * Serializes the object implementing this protocol to a JSON string
 * @param error Contains an error if serialization failed. Is nil when serialization was successful.
 * @return The serialized JSON string.
 */
- (nullable NSString *)toJsonString:(NSError **)error;
/**
 * Creates a dictionary containing data describing the object implementing this protocol which can be used to
 * serialize it to a JSON string.
 * @return A dictionary containing data describing the object implementing this protocol.
 */
- (NSDictionary *)toJsonData;
/**
 * Converts the given JSON data into an instance of the class which is implementing this protocol.
 *
 * @param jsonData The JSON data which should be converted into an object.
 * @param error Contains information about any errors which happened during deserialization if nil is returned by this method.
 * @return An instance of the class which is implementing this protocol or nil if an error occurred.
 */
+ (nullable instancetype)fromJsonData:(NSDictionary *)jsonData error:(NSError **)error;
@end

NS_ASSUME_NONNULL_END
