//
// Bitmovin Player iOS SDK
// Copyright (C) 2021, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Provides methods to deserialize objects to JSON strings.
 */
@protocol BMPJsonDecodable <NSObject>
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
