//
//  ZDDispatcher.h
//  ZDAPI
//
//  Created by Zendesk on 08/06/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "ZDDispatcherDelegate.h"
#import "ZDDispatcherResponse.h"



/**
 * API success block.
 */
typedef void (^ZDAPISuccess) (id);


/**
 * API error block
 */
typedef void (^ZDAPIError) (NSError*);


/**
 * ZDAPI Error codes.
 */
typedef NS_ENUM(NSInteger, ZDAPIErrorCode) {

    /** No internet connection available according to Reachability. */
    ZDAPIErrorUnreachable,

    /** Connection could not be established. */
    ZDAPIErrorConnection,

    /** Authentication failed. */
    ZDAPIErrorAuth,

    /** Request failed. */
    ZDAPIErrorRequest,

    /** No valid subdomain has been set. */
    ZDAPIErrorSubdomain,

    /** No sdk client id. */
    ZDAPIErrorClientId,

    /** No token or user email. */
    ZDAPIErrorUserId,

    /** Invalid delegate config for request. */
    ZDAPIErrorDelegateConfig,
};


/**
 * Convenience method for executing a block on the request queue
 * @param block the block to be executed
 */
static inline void zd_on_queue(dispatch_queue_t queue, dispatch_block_t block)
{
    dispatch_async(queue, block);
}


/**
 * Convenience method for executing a block on the UI queue
 * @param block the block to be executed
 */
static inline void zd_on_main_thread(dispatch_block_t block)
{
    dispatch_async(dispatch_get_main_queue(), block);
}


/**
 * ZDAPI Login state
 */
typedef NS_ENUM(NSInteger, ZDAPILoginState) {

    /**
     * The SDK has not yet authenticated during this session.
     */
    ZDAPILoginStateNotLoggedIn,

    /**
     * The SDK is in the process of loggin in.
     */
    ZDAPILoginStateLoggingIn,

    /**
     * The SDK has an oauth token that was valid the last time it was used.
     */
    ZDAPILoginStateLoggedIn
};


#pragma mark - Dispatcher



/**
 * The core communications controller.
 */
@interface ZDDispatcher : NSObject


@property (nonatomic, weak) id<ZDDispatcherDelegate> delegate;


/**
 * Enable or disable debug logging output.
 *
 * @param enabled YES for debug logging.
 */
+ (void) setDebugLogging:(BOOL)enabled;


/**
 * Verifies the configuration, logs in if necessary and then executes the request on the request queue.
 * This method handles putting the requets process into the request queue and then ensuring that the final
 * responses are sent on the main thread.
 *
 * If the error block is invoked with a 'ZDAPIErrorUnreachable' error then this is an immediate response on the same thread.
 *
 * @param requestBlock block which builds the NSMutableURLRequest
 * @param successBlock block which will be invoked on the main thread if the request is successful
 * @param errorBlock block which will be invoked on the main thread if the request fails
 * @param requiresAuth boolen indicating if the request requires authentication
 */
- (void) executeRequest:(NSMutableURLRequest* (^)(void))requestBlock
              onSuccess:(ZDAPISuccess)successBlock
                onError:(ZDAPIError)errorBlock
           requiresAuth:(BOOL)requiresAuth;


@end
