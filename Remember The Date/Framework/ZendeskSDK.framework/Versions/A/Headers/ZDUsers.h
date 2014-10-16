//
//  ZDUsers.h
//  ZDAPI
//
//  Created by Zendesk on 13/06/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "ZDModelObject.h"
#import "ZDUser.h"


/**
 * Cache of Zendesk users backed by persistence.
 */
@interface ZDUsers : ZDModelObject


/*
 * Get the user record for the requested id, if the user is unknown then a new record will be created and returned.
 *
 * @param userId the is of the user to retrieve
 * @return the user record
 */
- (ZDUser*) getUser:(NSNumber*)userId;


/**
 * Clear all data, both in memory and persistence.
 */
- (void) clear;


@end

