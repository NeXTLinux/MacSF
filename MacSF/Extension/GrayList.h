//
//  file: GrayList.h
//  project: macsf (launch daemon)
//  description: gray listed binaries (header)
//
//  created by Patrick Wardle
//  copyright (c) 2017 NeXTLinux. All rights reserved.
//

@import OSLog;
@import Foundation;


@interface GrayList : NSObject

/* PROPERTIES */

//gray listed (apple) binaries
@property(nonatomic, retain)NSMutableSet* graylistedBinaries;

/* METHODS */
//determine if process is graylisted
-(BOOL)isGrayListed:(Process*)process;

@end
