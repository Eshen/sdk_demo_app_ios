//
//  ZenHelpViewController.m
//  Remember The Date
//
//  Created by Eduardo Fonseca on 10/10/14.
//  Copyright (c) 2014 RememberTheDate. All rights reserved.
//

#import "ZenHelpViewController.h"

#import <ZendeskSDK/ZDCoreSDK.h>
#import <ZendeskSDK/ZDHelpCenter.h>

#import "RequestListViewController.h"
#import "SaveTheDateTabBarController.h"





@interface ZenHelpViewController ()

@end

@implementation ZenHelpViewController



-(void) setupSupportInformation {
    NSUserDefaults  *defaults   = [NSUserDefaults standardUserDefaults];
    
    if ([defaults stringForKey:@"userName"] != nil)
    {
        NSString* email = [defaults stringForKey:@"email"];
        if ([email length]>0) {
            [ZDCoreSDK configure:^(ZDAccount *account, ZDRequestCreationConfig *requestCreationConfig) {
                requestCreationConfig.tags = @[@"ios"];
                requestCreationConfig.additionalRequestInfo = @"";
                
                account.email = email;
                account.userToken = email;
            }];
        }
    } else {
        [ZDCoreSDK configure:^(ZDAccount *account, ZDRequestCreationConfig *requestCreationConfig) {
            requestCreationConfig.tags = @[@"ios"];
            requestCreationConfig.additionalRequestInfo = @"";
            
            account.email = @"mobile@zendesk.com";
            account.userToken = @"mobile@zendesk.com";
            
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
    
    [ZDCoreSDK showRequestCreationWithNavController:self.navigationController
                                        withSuccess:^(NSData *data) {
                                            
                                            // do something here if you want to...
                                            
                                        } andError:^(NSError *err) {
                                            
                                            // do something here if you want to...
                                        }];
}
- (IBAction)sendFeedback:(id)sender {
}

- (IBAction)showMyRequests:(id)sender {
    SaveTheDateTabBarController * tabbarController = (SaveTheDateTabBarController*)self.tabBarController;
    [tabbarController hideTabbar];
    RequestListViewController *vc = [RequestListViewController new];
    [self.navigationController pushViewController:vc animated:YES];
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
