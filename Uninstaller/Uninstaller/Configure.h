//
//  file: Configure.h
//  project: macsf (config)
//  description: install/uninstall logic (header)
//
//  created by Patrick Wardle
//  copyright (c) 2018 NeXTLinux. All rights reserved.
//

#ifndef MacSF_Configure_h
#define MacSF_Configure_h

#import "HelperComms.h"

@import OSLog;
@import Foundation;

@interface Configure : NSObject
{
    
}

/* PROPERTIES */

//helper installed & connected
@property(nonatomic) BOOL gotHelp;

//daemom comms object
@property(nonatomic, retain) HelperComms* xpcComms;

/* METHODS */

//uninstall
-(BOOL)uninstall:(NSInteger)action;

//remove helper (daemon)
-(BOOL)removeHelper;

@end

#endif
