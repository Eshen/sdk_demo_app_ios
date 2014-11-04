//
//  ZenHelpViewController.m
//  Remember The Date
//
//  Created by Zendesk on 10/10/14.
//  Copyright (c) 2014 RememberTheDate. All rights reserved.
//

#import <ZendeskSDK/ZendeskSDK.h>

#import "ZenHelpViewController.h"
#import "RequestListViewController.h"
#import "SaveTheDateTabBarController.h"


@interface ZenHelpViewController ()

@end

@implementation ZenHelpViewController



-(NSString *) userEmail {
    NSUserDefaults  *defaults   = [NSUserDefaults standardUserDefaults];
    
    if ([defaults stringForKey:@"userName"] != nil)
    {
        NSString* email = [defaults stringForKey:@"email"];
        if ([email length]>0) {
            return email;
        }
    }

    return nil;
}

-(void) setupSupportInformation {

    
    NSString * email = [self userEmail];

    [ZDKRequests configure:^(ZDKAccount *account, ZDKRequestCreationConfig *requestCreationConfig) {
        requestCreationConfig.tags = @[@"ios"];
        requestCreationConfig.additionalRequestInfo = @"";
        
        
        account.email = email;
        
        // our JWT endpoint for this application is using the email as the user identifier for user validation
        account.userId = email;
    }];
}


- (void)viewDidLoad {
    [super viewDidLoad];
}

//
//  Show support component
//
//

- (IBAction)showHelpCenter:(id)sender {
    SaveTheDateTabBarController * tabbarController = (SaveTheDateTabBarController*)self.tabBarController;
    [tabbarController hideTabbar];

    
    [ZDKHelpCenter showHelpCenterWithNavController:self.navigationController];
}

//
//  Request Creation component
//
//

- (IBAction)contactSupport:(id)sender {
         [ZDKRequests showRequestCreationWithNavController:self.navigationController
                                        withSuccess:^(NSData *data) {
                                            
                                            // do something here if you want to...
                                            
                                        } andError:^(NSError *err) {
                                            
                                            // do something here if you want to...
                                        }];
}

//
//  Rate My App component
//
// The send button feedback is disabled as the control can not be trigger programmatically
// but is driven by the configuration done on the Zendesk Mobile SDK Administration
//
//  The following code is here for demonstration purpose only.
//

- (IBAction)sendFeedback:(id)sender {
    
    NSString *email = [self userEmail];
    if ([email length] > 0) {
        
         // Setup Rate My App
        [ZDKRMA configure:^(ZDKAccount *account, ZDKRMAConfigObject *config) {
            
            account.email = email;
            
            // configgure additional info
            NSString *versionString = [NSString stringWithFormat:@"%@ (%@)",
                                       [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"],
                                       [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"]];
            
            NSString *appVersion = [NSString stringWithFormat:@"App version: %@", versionString];
            
            config.additionalRequestInfo = [NSString stringWithFormat:@"Additional info here.\n%@", appVersion];
        }];
        
        /////////////////////////////////////////////////////////////////////////////////////////////////////
        // OPTIONAL - Customize appearance
        /////////////////////////////////////////////////////////////////////////////////////////////////////
        
        [ZDKRMA configure:^(ZDKAccount *account, ZDKRMAConfigObject *config) {
            
            // set success and error dialog images images
            config.successImageName = @"rma_tick";
            config.errorImageName = @"rma_error";
        }];
        
        [ZDKRMA showInView:self.view];
        
    } else {
        UIAlertView * alert = [[UIAlertView alloc] initWithTitle:@"Wait a second..." message:@"You need to go in the profile screen and enter your email ..." delegate:self cancelButtonTitle:@"OK, doing it now :)" otherButtonTitles:nil];
        [alert show];
    }
}

- (IBAction)showMyRequests:(id)sender {
    
    if ([[self userEmail] length] > 0) {
        
        SaveTheDateTabBarController * tabbarController = (SaveTheDateTabBarController*)self.tabBarController;
        [tabbarController hideTabbar];
        
        RequestListViewController *vc = [RequestListViewController new];
        [self.navigationController pushViewController:vc animated:YES];
    }
    else {
        UIAlertView * alert = [[UIAlertView alloc] initWithTitle:@"Wait a second..." message:@"You need to go in the profile screen and setup your email ..." delegate:self cancelButtonTitle:@"OK, doing it now :)" otherButtonTitles:nil];
        [alert show];
    }
    
}


-(void) viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    //
    // Setup the support information
    //
    [self setupSupportInformation];
    
    
    SaveTheDateTabBarController * tabbarController = (SaveTheDateTabBarController*)self.tabBarController;
    [tabbarController showTabbar];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

@end
