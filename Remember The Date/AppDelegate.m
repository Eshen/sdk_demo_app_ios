//
//  AppDelegate.m
//  Remember The Date
//
//  Created by Eduardo Fonseca on 10/9/14.
//  Copyright (c) 2014 RememberTheDate. All rights reserved.
//

#import "AppDelegate.h"
#import <ZendeskSDK/ZendeskSDK.h>
#import <ZendeskSDK/ZDSupportView.h>

#define RED_COLOR [UIColor colorWithRed:232.0f/255.f green:42.0f/255.0f blue:42.0f/255.0f alpha:1.0f]
#define ORANGE_COLOR [UIColor colorWithRed:253.0f/255.f green:144.0f/255.0f blue:38.0f/255.0f alpha:1.0f]
#define ORANGE_COLOR_40 [UIColor colorWithRed:253.0f/255.f green:144.0f/255.0f blue:38.0f/255.0f alpha:0.4f]

#define TEXT_COLOR [UIColor colorWithRed:150.0f/255.f green:110.0f/255.0f blue:90.0f/255.0f alpha:1.0f]
#define TEXT_COLOR_40 [UIColor colorWithRed:150.0f/255.f green:110.0f/255.0f blue:90.0f/255.0f alpha:.4f]

#define PLACEHOLDER_COLOR [UIColor colorWithRed:217.0f/255.f green:205.0f/255.0f blue:200.0f/255.0f alpha:1.0f]
#define NAVBAR_COLOR [UIColor colorWithRed:240.0f/255.f green:240.0f/255.0f blue:240.0f/255.0f alpha:1.0f]
#define EMAIL_COLOR [UIColor colorWithRed:214.0f/255.f green:214.0f/255.0f blue:214.0f/255.0f alpha:1.0f]


@interface AppDelegate ()

@end

@implementation AppDelegate



-(void) setupVisualStyle {

    // status bar
    [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent];
    
    // nav bar
    NSDictionary *navbarAttributes = [NSDictionary dictionaryWithObjectsAndKeys:
                                      [UIColor whiteColor] ,NSForegroundColorAttributeName, nil];
    [[UINavigationBar appearance] setTintColor:[UIColor whiteColor]];
    [[UINavigationBar appearance] setBarTintColor:RED_COLOR];
    [[UINavigationBar appearance] setTitleTextAttributes:navbarAttributes];
    
    
    [[ZDCoreCreateRequestView appearance] setPlaceholderTextColor:TEXT_COLOR_40];
    [[ZDCoreCreateRequestView appearance] setTextEntryColor:TEXT_COLOR];
    
    [[ZDUITextView appearance] setTintColor:RED_COLOR];
    
    [[ZDCoreCreateRequestView appearance] setTextEntryFont:[UIFont fontWithName:@"Helvetica" size:16]];
    
    
    UIActivityIndicatorView *spinner = [[UIActivityIndicatorView alloc] initWithFrame:CGRectMake(0, 0, 20, 20)];
    spinner.activityIndicatorViewStyle = UIActivityIndicatorViewStyleGray;
    [spinner setTintColor:RED_COLOR];
    [spinner setColor:RED_COLOR];
    
    [[ZDCoreCreateRequestView appearance] setSpinner:(id<ZDSpinnerDelegate>)spinner];
    [[ZDRequestListLoadingTableCell appearance] setSpinner:(id<ZDSpinnerDelegate>)spinner];
    [[ZDRequestListTableCell appearance] setLeftInset:20];
    
    [[ZDCoreCreateRequestView appearance] setSeperatorBackgroundColor:[UIColor colorWithWhite:0.8980f alpha:1.0f]];
    [[ZDCoreCreateRequestView appearance] setEmailEntryTextColor:EMAIL_COLOR];
    
    [[ZDSupportView appearance] setBtnContactUsColor:RED_COLOR];

    
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    // sync the default
    NSUserDefaults  *defaults   = [NSUserDefaults standardUserDefaults];
    [defaults synchronize];
    // Visual setup
    
    [[UITabBar appearance] setSelectedImageTintColor: [UIColor colorWithRed:0.38 green:0.85 blue:0.82 alpha:1.0]];
    [[UITabBar appearance] setShadowImage:[[UIImage alloc] init]];
    [[UINavigationBar appearance] setTitleTextAttributes:@{NSForegroundColorAttributeName: [UIColor whiteColor]}];
    [application setStatusBarStyle:UIStatusBarStyleLightContent];
    
    // Request Local Notifications
    if ([UIApplication instancesRespondToSelector:@selector(registerUserNotificationSettings:)]){
        [application registerUserNotificationSettings:[UIUserNotificationSettings settingsForTypes:UIUserNotificationTypeAlert|UIUserNotificationTypeBadge|UIUserNotificationTypeSound categories:nil]];
    }
    
    //
    [self setupVisualStyle];
    
    // setup the sdk
    
    [ZendeskSDK initialize:@"e5dd7520b178e21212f5cc2751a28f4b5a7dc76698dc79bd"
             withSubdomain:@"https://rememberthedate.zendesk.com"
                  clientId:@"client_for_rtd_jwt_endpoint"
                 andSecret:@"d8bb54e67fea6c466294f8b23d673d75b0fb0408348b09b7d6694962a484f89c"];
  
    [ZDCoreSDK configure:^(ZDAccount *account, ZDRequestCreationConfig *requestCreationConfig) {
        account.userToken = @"test@mobile.com";
    }];
    
    return YES;
}

@end
