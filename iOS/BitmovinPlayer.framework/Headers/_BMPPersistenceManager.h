//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import "_BMPPersistentArchive.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_PersistenceManager)
@interface _BMPPersistenceManager : NSObject
/**
 The base directory URL for bitmovin player.
 */
@property (nonatomic, nonnull, strong, readonly) NSURL *baseDirectoryURL;
/**
 The singleton instance of this manager.

 @return An instance of _BMPPersistenceManager.
 */
+ (instancetype)sharedInstance;
/**
 Completes a given relative path by appending it to NSHomeDirectory().

 @param relativePath The relative path to complete.
 @return A NSURL representing relativePath appended to NSHomeDirectory().
 */
+ (NSURL *)completeRelativPath:(NSString *)relativePath;
/**
 Returns an persistent archive for a given name. If that name is a path the last path component will be used as name.
 The archive will be created at baseDirectoryURL's location if it does not already exist there.

 @note If you want to pass create/retrieve an archive in a subdirectory of baseDirectoryURL use archiveForName:withPath:

 @param archiveName The name for the archive.
 @return An instance of _BMPPersistentArchive located at baseDirectoryURL.
 */
- (_BMPPersistentArchive *)archiveForName:(NSString *)archiveName;
/**
 Returns an persistent archive for a given name at a specific subdirectory of baseDirectoryURL.
 If the provided name is a path the last path component will be used as name.
 The archive will be created at the specified location if it does not already exist there.

 @note Calling this method by passing nil as path is equal to calling archiveForName:.

 @param archiveName The name for the archive.
 @return An instance of _BMPPersistentArchive located at baseDirectoryURL.
 */
- (_BMPPersistentArchive *)archiveForName:(NSString *)archiveName withPath:(nullable NSString *)path;
/**
 Returns an URL by appending path to baseDirectoryURL and creates the resulting directory if it does not yet exist.

 @param path The relative path to baseDirectoryURL.
 @return The NSURL pointing to the requested directory.
 */
- (NSURL *)baseDirectoryURLForPath:(NSString *)path;
/**
 Ensures that the given directory exists and returns the url to this directory.

 @param directoryPath The absolute path to the desired directory.
 @return The NSURL pointing to the requested directory.
 */
- (NSURL *)ensureDirectoryAtPath:(NSString *)directoryPath;
@end

NS_ASSUME_NONNULL_END
