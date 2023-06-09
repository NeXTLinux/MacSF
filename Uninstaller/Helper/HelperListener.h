//
//  file: HelperListener.h
//  project: (open-source) installer
//  description: XPC listener for connections for user components (header)
//
//  created by Patrick Wardle
//  copyright (c) 2018 NeXTLinux. All rights reserved.
//

@import OSLog;
@import Foundation;

#import "HelperInterface.h"

//function def
OSStatus SecTaskValidateForRequirement(SecTaskRef task, CFStringRef requirement);

@interface HelperListener : NSObject <NSXPCListenerDelegate>
{
    
}

/* PROPERTIES */

//XPC listener obj
@property(nonatomic, retain)NSXPCListener* listener;

/* METHODS */

//setup XPC listener
-(BOOL)initListener;

//automatically invoked
// allows NSXPCListener to configure/accept/resume a new incoming NSXPCConnection
// note: we only allow binaries signed by NeXTLinux to talk to this to be extra safe :)
-(BOOL)listener:(NSXPCListener *)listener shouldAcceptNewConnection:(NSXPCConnection *)newConnection;

@end
