//
//  file: HelperInterface.h
//  project: (open-source) installer
//  description: interface for app installer comms (header)
//
//  created by Patrick Wardle
//  copyright (c) 2018 NeXTLinux. All rights reserved.
//

@import OSLog;
@import Foundation;

#import "XPCProtocol.h"
#import "HelperInterface.h"

@interface HelperInterface : NSObject <XPCProtocol>
{
    
}

@end
