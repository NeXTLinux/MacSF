//
//  FilterDataProvider.h
//  MacSF
//
//  Created by Patrick Wardle on 8/1/20.
//  Copyright (c) 2020 NeXTLinux. All rights reserved.
//

#import <bsm/libbsm.h>

@import OSLog;
@import NetworkExtension;

#import "GrayList.h"

@interface FilterDataProvider : NEFilterDataProvider

/* PROPERTIES */

//(process) cache
@property(atomic, retain)NSCache* cache;

//graylist obj
@property(nonatomic, retain)GrayList* grayList;

//related flows
@property(nonatomic, retain)NSMutableDictionary* relatedFlows;

@end
