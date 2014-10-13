//
//  DateTableViewController.m
//  Remember The Date
//
//  Created by Eduardo Fonseca on 10/10/14.
//  Copyright (c) 2014 RememberTheDate. All rights reserved.
//

#import "DateTableViewController.h"

@interface DateTableViewController ()<UIAlertViewDelegate>
@property (nonatomic, strong)   NSArray     *notificationsArray;
@property (nonatomic, strong)   NSDateFormatter *formatter;
@property (nonatomic, strong)   NSIndexPath *indexPathToBeDeleted;
@end

@implementation DateTableViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    self.formatter  = [[NSDateFormatter alloc] init];
    [self.formatter setTimeStyle:NSDateFormatterNoStyle];
    [self.formatter setDateStyle:NSDateFormatterShortStyle];
    [self.formatter setDateFormat:@"MMM dd"];
    
}

- (void)viewWillAppear:(BOOL)animated
{
    [self reloadTableView];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    if ([[NSUserDefaults standardUserDefaults] stringForKey:@"userName"] == nil)
    {
        [self onProfileTapped:nil];
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)onProfileTapped:(id)sender {
    UINavigationController  *destinationController  = nil;
    if ([[NSUserDefaults standardUserDefaults] stringForKey:@"userName"] != nil)
    {
        destinationController   = [self.storyboard instantiateViewControllerWithIdentifier:@"viewProfile"];
    }
    else
    {
        destinationController   = [self.storyboard instantiateViewControllerWithIdentifier:@"createProfile"];
    }
    
    [self presentViewController:destinationController animated:YES completion:^{
        
    }];
}

#pragma mark - UITableView

- (void)reloadTableView
{
    UIApplication   *application    = [UIApplication sharedApplication];
    self.notificationsArray = [application scheduledLocalNotifications];
    [self.tableView reloadData];

}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell   = [tableView dequeueReusableCellWithIdentifier:@"DateCell" forIndexPath:indexPath];
    
    UILabel *dateName       = (UILabel *)[cell viewWithTag:1001];
    UILabel *date           = (UILabel *)[cell viewWithTag:1002];
    
    UILocalNotification *currentNotification    = [self.notificationsArray objectAtIndex:indexPath.row];
    
    dateName.text           = currentNotification.alertBody;
    date.text               = [self.formatter stringFromDate:currentNotification.fireDate];
    
    return cell;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [self.notificationsArray count];
}

- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath
{
    return YES;
}

- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (editingStyle == UITableViewCellEditingStyleDelete)
    {
        self.indexPathToBeDeleted   = indexPath;
        UIAlertView *alert  = [[UIAlertView alloc] initWithTitle:NSLocalizedString(@"Are you sure?", @"") message:NSLocalizedString(@"You can't undo this.", @"") delegate:self cancelButtonTitle:NSLocalizedString(@"Cancel", @"") otherButtonTitles:NSLocalizedString(@"OK", @""), nil];
        
        [alert show];
        
    }
}

#pragma mark - AlertView

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    if ([[alertView buttonTitleAtIndex:buttonIndex] isEqualToString:NSLocalizedString(@"OK", @"")])
    {
        UILocalNotification *notification   = [self.notificationsArray objectAtIndex:self.indexPathToBeDeleted.row];
        [[UIApplication sharedApplication] cancelLocalNotification:notification];
        [self reloadTableView];
        
        self.indexPathToBeDeleted   = nil;
    }
}

@end
