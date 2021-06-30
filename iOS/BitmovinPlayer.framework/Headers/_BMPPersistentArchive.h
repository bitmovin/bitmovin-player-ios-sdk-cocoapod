//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

/**
 * This class provides an abstraction to access the persistent data stored as key/value pairs in a single file on disk.
 * Each instance of a _BMPPersistentArchive is associated with a single archive file and can be used to read and write
 * its data. The _BMPPersistentArchive takes care of reading from and writing to disk internally and transparent to the
 * object which is using the _BMPPersistentArchive.
 */

NS_ASSUME_NONNULL_BEGIN

/// :nodoc:
NS_SWIFT_NAME(_PersistentArchive)
@interface _BMPPersistentArchive : NSObject
@property (nonatomic, nonnull, strong, readonly) NSURL *archiveURL;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithURL:(NSURL *)archiveUrl NS_DESIGNATED_INITIALIZER;

- (BOOL)storeBoolValue:(BOOL)value forKey:(NSString *)key;
- (BOOL)storeDateValue:(NSDate *)value forKey:(NSString *)key;
- (BOOL)storeDoubleValue:(double)value forKey:(NSString *)key;
- (BOOL)storeStringValue:(NSString *)value forKey:(NSString *)key;
- (BOOL)storeNumberValue:(NSNumber *)value forKey:(NSString *)key;
- (nullable NSNumber *)numberValueForKey:(NSString *)key;
- (nullable NSString *)stringValueForKey:(NSString *)key;
- (double)doubleValueForKey:(NSString *)key;
- (nullable NSDate *)dateValueForKey:(NSString *)key;
- (BOOL)boolValueForKey:(NSString *)key;
- (BOOL)removeValueForKey:(NSString *)key;
- (void)clear;
- (void)overwriteFromArchive:(_BMPPersistentArchive *)otherArchive;
@end

NS_ASSUME_NONNULL_END
