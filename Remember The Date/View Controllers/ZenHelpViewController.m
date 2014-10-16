//
//  ZenHelpViewController.m
//  Remember The Date
//
//  Created by Eduardo Fonseca on 10/10/14.
//  Copyright (c) 2014 RememberTheDate. All rights reserved.
//

#import "ZenHelpViewController.h"


#import <ZendeskSDK/ZDHelpCenter.h>
#import <ZendeskSDK/ZDCoreSDK.h>
#import <ZendeskSDK/ZDRMA.h>
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
    
    if ([email length] > 0) {
        [ZDCoreSDK configure:^(ZDAccount *account, ZDRequestCreationConfig *requestCreationConfig) {
            requestCreationConfig.tags = @[@"ios"];
            requestCreationConfig.additionalRequestInfo = @"";
            
            account.email = email;
            account.userToken = email;
        }];
    }

}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
}


- (IBAction)showHelpCenter:(id)sender {
        [ZDHelpCenter showHelpCenterWithNavController:self.navigationController];
}

- (IBAction)contactSupport:(id)sender {
    if ([[self userEmail] length] > 0) {

         [ZDCoreSDK showRequestCreationWithNavController:self.navigationController
                                        withSuccess:^(NSData *data) {
                                            
                                            // do something here if you want to...
                                            
                                        } andError:^(NSError *err) {
                                            
                                            // do something here if you want to...
                                        }];
    }
    else {
        UIAlertView * alert = [[UIAlertView alloc] initWithTitle:@"Wait a second..." message:@"You need to go in the profile screen and enter your email ..." delegate:self cancelButtonTitle:@"OK, doing it now :)" otherButtonTitles:nil];
        [alert show];
    }
}
- (IBAction)sendFeedback:(id)sender {
    
    NSString *email = [self userEmail];
    if ([email length] > 0) {
        
        
        
        // Setup Rate My App
        [ZDRMA configure:^(ZDAccount *account, ZDRMAConfigObject *config) {
            
            
            
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
        
        [ZDRMA configure:^(ZDAccount *account, ZDRMAConfigObject *config) {
            
            // set success and error dialog images images
            config.successImageName = @"rma_tick";
            config.errorImageName = @"rma_error";
        }];
        
        
        [ZDRMA showEveryTimeInView:self.view];
        
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
    [self setupSupportInformation];
    SaveTheDateTabBarController * tabbarController = (SaveTheDateTabBarController*)self.tabBarController;
    [tabbarController showTabbar];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
