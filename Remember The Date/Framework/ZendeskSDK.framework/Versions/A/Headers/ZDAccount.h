//
//  ZDAccount.h
//  ZDAPI
//
//  Created by Zendesk on 06/06/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <Foundation/Foundation.h>


typedef NS_ENUM(NSInteger, ZDAccountState) {

    /**
     * Account details have not yet been loaded.
     */
    ZDAccountStateUnloaded,
    
    /**
     * Account state is valid.
     */
    ZDAccountStateValid,

    /**
     * A defining value has been changed and the account can not be guaranteed to point to the same Zendesk account.
     */
    ZDAccountStateInvalidated
};


/**
 * The ZDAccount is a wrapper around the account and
 * user details required to interact with your helpdesk.
 */
@interface ZDAccount : NSObject


/**
 * The subdomain of your Zendesk account
 * e.g. if your usual helpdesk URL is 'http://xyz.zendesk.com' then you would set this as 'xyz.zendesk.com'
 */
@property (nonatomic, strong) NSString *subdomain;


/**
 * Your app ID. This is created while configuring SDK in lotus.
 */
@property (nonatomic, strong) NSString *applicationId;


/**
 * End users email address, this should be set at runtime before any other methods are invoked.
 */
@property (nonatomic, strong) NSString *email;

/**
 * The token the SDK will use to authenticate against your specified service.
 */
@property (nonatomic, strong) NSString *userToken;

/**
 * The SDK client id.
 */
@property (nonatomic, strong) NSString *clientId;

/**
 * The current Zendesk oauth token.
 */
@property (nonatomic, strong) NSString *oauthToken;

/**
 * The zendesk user id of the user in the current subdomain.
 */
@property (nonatomic, strong) NSNumber *zendeskUserId;

/**
 * Indicates account state and whether the account state has been invalidated by a credential change.
 */
@property (assign) ZDAccountState state;


@end

