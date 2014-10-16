//
//  ZendeskSDK.h
//  ZendeskSDK
//
//  Created by Zendesk on 03/10/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for ZendeskSDK.
FOUNDATION_EXPORT double ZendeskSDKVersionNumber;

//! Project version string for ZendeskSDK.
FOUNDATION_EXPORT const unsigned char ZendeskSDKVersionString[];


#import <ZendeskSDK/ZDAPI.h>
#import <ZendeskSDK/ZDUI.h>
#import <ZendeskSDK/ZDRMA.h>
#import <ZendeskSDK/ZDCoreSDK.h>
#import <ZendeskSDK/ZDHelpCenter.h>
#import <ZendeskSDK/ZDToast.h>
#import <ZendeskSDK/ZendeskSDKConstants.h>


@interface ZDSDKInit : NSObject


/*
 * Application ID found in the lotus configuration pannel.
 */
@property (nonatomic, strong) NSString *applicationId;

/*
 * The subdomain of your Zendesk account, e.g. if your usual helpdesk
 * URL is 'http://xyz.zendesk.com' then you would set this as 'xyz.zendesk.com'.
 */
@property (nonatomic, strong) NSString *subdomain;

/*
 * Your client ID.
 */
@property (nonatomic, strong) NSString *clientId;

/*
 * Your JWT secrect.
 */
@property (nonatomic, strong) NSString *secret;


@end




/*
 * ZendeskSDK is responsible for initialization of
 * the SDK and manages the backend configuration.
 */
@interface ZendeskSDK : NSObject


/*
 * Initialize the SDK.
 *
 * @param applicationId Application ID found in the lotus configuration pannel.
 * @param subdomain The subdomain of your Zendesk account, e.g. if your usual helpdesk
 * URL is 'http://xyz.zendesk.com' then you would set this as 'xyz.zendesk.com'.
 * @param clientId Your client ID, can be nil if not using any authentication.
 * @param secret Your JWT secrect, can be nil if not using any authentication.
 *
 */
+ (void) initialize:(NSString *)applicationId
      withSubdomain:(NSString *)subdomain
           clientId:(NSString *)clientId
          andSecret:(NSString *)secret;


+ (BOOL) hasConfig;


/**
 * Get the config for a given component.
 *
 * @param key the key for the components config
 * @return The configuration for the key supplied, or nil if no config was found.
 */
+ (NSDictionary *) configForKey:(NSString *) key;


/**
 * Refresh the config from the server, refresh will be started if a refresh
 * is not already in progress and the refresh interval has passed. This method
 * will automatically be invoked when the application enters the foreground to
 * check for updates if due.
 */
+ (void) refresh;


/**
 * The refresh time interval is the maximum frequency with which a refresh will be triggered.
 */
+ (NSTimeInterval) refreshInterval;


/**
 * Set refresh time interval. One hour is the minimum possible value for a refresh interval.
 *
 * @param interval the refresh interval. An interval of less than one hour will result in
 * a minimum refresh interval, eg. [ZendeskSDK setRefreshInterval:0] results in a refresh
 * interval of one hour.
 */
+ (void) setRefreshInterval:(NSTimeInterval)interval;

@end
