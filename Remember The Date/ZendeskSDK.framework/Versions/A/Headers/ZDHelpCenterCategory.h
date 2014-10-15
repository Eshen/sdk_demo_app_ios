//
//  ZDHelpCenterCategory.h
//  ZDAPI
//
//  Created by Zendesk on 25/09/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZDHelpCenterCategory : NSObject

@property (strong, nonatomic) NSString *sid;
@property (strong, nonatomic) NSString *name;
@property (strong, nonatomic) NSString *categoryDescription;
@property (assign, nonatomic) NSInteger position;
@property (assign, nonatomic) BOOL outdated;


/**
 * Parses a single Help Center json category object.
 *
 * @return A new ZDHelpCenterCategory.
 */
+ (ZDHelpCenterCategory *) parseCategory:(NSDictionary *)categoryJson;


/**
 * Parses a collection of Help Center json category objects
 *
 */
+ (NSArray *) parseCategories:(NSDictionary *)json;


@end
