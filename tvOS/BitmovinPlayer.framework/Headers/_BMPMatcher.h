//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_Matcher)
@interface _BMPMatcher : NSObject
/**
 Matches all AES Key URLs within an M3U8 variant playlist by ignoring data URIs.
 */
@property (class, nonatomic, readonly, copy) NSRegularExpression *aesKeyUrlsExcludingDataUris;

/**
 Returns a RegEx pattern that matches with line where the given tag is present

 @param stringToMatch string to match
 @return NSRegularExpression that matches given tag
 */
+ (NSRegularExpression *)lineContainingString:(NSString *)stringToMatch;

/**
 Returns a RegEx pattern that matches with line where the given AES key URL is present

 @param url URL to match
 @return NSRegularExpression that matches given URL
 */
+ (NSRegularExpression *)aesKeyUrlWithUrl:(NSString *)url;
/**
 Returns a RegEx pattern that matches the given url either in a full line or in URI="" tags

 @param url URL to match
 @return NSRegularExpression that matches the given URL
 */
+ (NSRegularExpression *)fullLineOrUriWithUrl:(NSString *)url;

/**
 Returns the range for the first match or (NSNotFound, 0) if no match was found.

 @param expression RegEx for matching
 @param stringData The String data which should be used to search for matches
 @return The range of the first match or (NSNotFound, 0) if no match was found
 */
+ (NSRange)firstMatchFor:(NSRegularExpression *)expression in:(NSString *)stringData;

/**
 The range for the matching group at the specified index for the first match is returned.
 Returns (NSNotFound, 0) if no match was found or the group index was invalid.

 @param expression RegEx for matching
 @param stringData The String data which should be used to search for matches
 @param groupIndex The index of the group for which the range should be returned, starting at 0 for the first group.
 @return The range for the group at the specified index for the first match or (NSNotFound, 0) if no match was
    found or the group index was invalid.
 */
+ (NSRange)groupInFirstMatchFor:(NSRegularExpression *)expression in:(NSString *)stringData groupIndex:(NSUInteger)groupIndex;
@end

NS_ASSUME_NONNULL_END
