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


#define RED_COLOR [UIColor colorWithRed:205.0f/255.f green:35.0f/255.0f blue:85.0f/255.0f alpha:1.0f]
#define ORANGE_COLOR [UIColor colorWithRed:253.0f/255.f green:144.0f/255.0f blue:38.0f/255.0f alpha:1.0f]
#define ORANGE_COLOR_40 [UIColor colorWithRed:253.0f/255.f green:144.0f/255.0f blue:38.0f/255.0f alpha:0.4f]

#define TEXT_COLOR [UIColor colorWithRed:150.0f/255.f green:110.0f/255.0f blue:90.0f/255.0f alpha:1.0f]
#define TEXT_COLOR_40 [UIColor colorWithRed:150.0f/255.f green:110.0f/255.0f blue:90.0f/255.0f alpha:.4f]

#define PLACEHOLDER_COLOR [UIColor colorWithRed:217.0f/255.f green:205.0f/255.0f blue:200.0f/255.0f alpha:1.0f]
#define NAVBAR_COLOR [UIColor colorWithRed:240.0f/255.f green:240.0f/255.0f blue:240.0f/255.0f alpha:1.0f]




@interface ZenHelpViewController ()

@end

@implementation ZenHelpViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.

    
}
- (IBAction)showHelpCenter:(id)sender {
        [ZDHelpCenter showHelpCenterWithNavController:self.navigationController];
}

- (IBAction)contactSupport:(id)sender {
    
    
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

    
    
    // status bar
    [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent];
    
    // nav bar
    NSDictionary *navbarAttributes = [NSDictionary dictionaryWithObjectsAndKeys:
                                      [UIColor whiteColor] ,NSForegroundColorAttributeName, nil];
    [[UINavigationBar appearance] setTintColor:[UIColor whiteColor]];
    [[UINavigationBar appearance] setBarTintColor:RED_COLOR];
    [[UINavigationBar appearance] setTitleTextAttributes:navbarAttributes];
    
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
}

-(void) viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    NSLog(@"count : %@", self.view.subviews);
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
