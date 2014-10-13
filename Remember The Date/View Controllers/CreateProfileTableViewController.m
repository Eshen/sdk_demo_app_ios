//
//  CreateProfileTableViewController.m
//  Remember The Date
//
//  Created by Eduardo Fonseca on 10/10/14.
//  Copyright (c) 2014 RememberTheDate. All rights reserved.
//

#import "CreateProfileTableViewController.h"

@interface CreateProfileTableViewController ()<UIAlertViewDelegate>
@property (weak, nonatomic) IBOutlet UIButton *pictureButton;
@property (weak, nonatomic) IBOutlet UITextField *nameTextField;
@property (weak, nonatomic) IBOutlet UITextField *emailTextField;
@property (weak, nonatomic) IBOutlet UITextField *passwordTextField;

@end

@implementation CreateProfileTableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    NSUserDefaults  *defaults   = [NSUserDefaults standardUserDefaults];
    
    if ([defaults stringForKey:@"userName"] != nil)
    {
        // We have a profile!
        
        self.nameTextField.text         = [defaults stringForKey:@"userName"];
        self.emailTextField.text        = [defaults stringForKey:@"email"];
        self.passwordTextField.text     = [defaults stringForKey:@"password"];
    }
    
    self.pictureButton.layer.cornerRadius   = CGRectGetWidth(self.pictureButton.frame)/2;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)onPictureButtonTapped:(id)sender {

    
}

- (IBAction)onCreateTapped:(id)sender {
    if (self.nameTextField.text != nil)
    {
        NSUserDefaults  *defaults   = [NSUserDefaults standardUserDefaults];
        [defaults setObject:self.nameTextField.text forKey:@"userName"];
        [defaults setObject:self.emailTextField.text forKey:@"email"];
        [defaults setObject:self.passwordTextField.text forKey:@"password"];
        [defaults synchronize];
        
        [self dismissViewControllerAnimated:YES completion:^{
            
        }];
    }
    else
    {
        // Alert user
        UIAlertView *alert  = [[UIAlertView alloc] initWithTitle:NSLocalizedString(@"Error", @"") message:NSLocalizedString(@"Please fill out all fields.", @"") delegate:self cancelButtonTitle:NSLocalizedString(@"OK", @"") otherButtonTitles:nil];
        
        [alert show];
    }
}

- (IBAction)onCloseTapped:(id)sender {
    [self dismissViewControllerAnimated:YES completion:^{
        
    }];
}

@end
