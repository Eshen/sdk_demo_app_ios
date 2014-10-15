//
//  AppDelegate.m
//  Remember The Date
//
//  Created by Eduardo Fonseca on 10/9/14.
//  Copyright (c) 2014 RememberTheDate. All rights reserved.
//

#import "AppDelegate.h"
#import <ZendeskSDK/ZendeskSDK.h>

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    // Visual setup
    
    [[UITabBar appearance] setSelectedImageTintColor: [UIColor colorWithRed:0.38 green:0.85 blue:0.82 alpha:1.0]];
    [[UINavigationBar appearance] setTitleTextAttributes:@{NSForegroundColorAttributeName: [UIColor whiteColor]}];
    [application setStatusBarStyle:UIStatusBarStyleLightContent];
    
    // Request Local Notifications
    if ([UIApplication instancesRespondToSelector:@selector(registerUserNotificationSettings:)]){
        [application registerUserNotificationSettings:[UIUserNotificationSettings settingsForTypes:UIUserNotificationTypeAlert|UIUserNotificationTypeBadge|UIUserNotificationTypeSound categories:nil]];
    }
    
    // setup the sdk
    [ZendeskSDK initialize:@"e5dd7520b178e21212f5cc2751a28f4b5a7dc76698dc79bd"
             withSubdomain:@"https://rememberthedate.zendesk.com"
                  clientId:@"client_for_rtd_jwt_endpoint"
                 andSecret:@"d8bb54e67fea6c466294f8b23d673d75b0fb0408348b09b7d6694962a484f89c"];
    
    return YES;
}

@end
