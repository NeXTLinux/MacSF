//
//  File: Signing.h
//  Project: Proc Info
//
//  Created by: Patrick Wardle
//  Copyright:  2017 NeXTLinux
//  License:    Creative Commons Attribution-NonCommercial 4.0 International License
//

#ifndef Signing_h
#define Signing_h

@import Foundation;

/* FUNCTIONS */

//get the signing info of a item
// audit token: extract dynamic code signing info
// path specified: generate static code signing info
NSMutableDictionary* extractSigningInfo(audit_token_t* token, NSString* path, SecCSFlags flags);

//determine who signed item
NSNumber* extractSigner(SecStaticCodeRef code, SecCSFlags flags, BOOL isDynamic);

//validate a requirement
OSStatus validateRequirement(SecStaticCodeRef code, SecRequirementRef requirement, SecCSFlags flags, BOOL isDynamic);

//extract (names) of signing auths
NSMutableArray* extractSigningAuths(NSDictionary* signingDetails);

#endif
