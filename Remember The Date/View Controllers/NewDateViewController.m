//
//  NewDateViewController.m
//  Remember The Date
//
//  Created by Eduardo Fonseca on 10/10/14.
//  Copyright (c) 2014 RememberTheDate. All rights reserved.
//

#import "NewDateViewController.h"

@interface NewDateViewController ()
@property (weak, nonatomic) IBOutlet UITextField *dateNameTextField;
@property (weak, nonatomic) IBOutlet UIDatePicker *datePicker;

@end

@implementation NewDateViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.datePicker.minimumDate = [NSDate date];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)onAddTapped:(id)sender {
    if ([self.dateNameTextField.text isEqualToString:@""] == NO)
    {
        BOOL isAfter = [self.datePicker.date compare:[NSDate date]] == NSOrderedDescending;
        
        if (isAfter)
        {
            UILocalNotification *notification   = [[UILocalNotification alloc] init];
            notification.fireDate               = self.datePicker.date;
            notification.timeZone               = [NSTimeZone localTimeZone];
            notification.alertBody              = self.dateNameTextField.text;
            notification.soundName              = UILocalNotificationDefaultSoundName;
            [[UIApplication sharedApplication] scheduleLocalNotification:notification];
            
            [self dismissViewControllerAnimated:YES completion:^{
                
            }];
        }
        else
        {
            // Tell the user
        }
    }
}

- (IBAction)onCancelTapped:(id)sender {
    [self dismissViewControllerAnimated:YES completion:^{
        
    }];   
}

@end
