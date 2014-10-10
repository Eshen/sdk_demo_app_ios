//
//  SaveTheDateTabBarController.m
//  Remember The Date
//
//  Created by Eduardo Fonseca on 10/10/14.
//  Copyright (c) 2014 RememberTheDate. All rights reserved.
//

#import "SaveTheDateTabBarController.h"

@interface SaveTheDateTabBarController ()

@end

@implementation SaveTheDateTabBarController

- (void)viewDidLoad
{
    [super viewDidLoad];
    [self.viewControllers enumerateObjectsUsingBlock:^(UIViewController *vc, NSUInteger idx, BOOL *stop) {
        vc.title = nil;
        vc.tabBarItem.imageInsets = UIEdgeInsetsMake(6, 0, -6, 0);
    }];
    
    
    UIButton    *plusButton = [UIButton buttonWithType:UIButtonTypeCustom];
    plusButton.backgroundColor  = [UIColor whiteColor];
    [plusButton setImage:[UIImage imageNamed:@"icoAdd"] forState:UIControlStateNormal];
    [plusButton setImage:[UIImage imageNamed:@"icoAddActive"] forState:UIControlStateHighlighted];
    plusButton.layer.cornerRadius   = 30;
    plusButton.frame        = CGRectMake((CGRectGetWidth(self.view.frame)/2)-19, CGRectGetHeight(self.view.frame)-44, 38, 38);
    
    [plusButton addTarget:self action:@selector(didTapAdd:) forControlEvents:UIControlEventTouchUpInside];
    
    [self.view addSubview:plusButton];
    
}

- (void)didTapAdd:(id)sender
{
    UINavigationController  *addController  = [self.storyboard instantiateViewControllerWithIdentifier:@"newDate"];
    [self presentViewController:addController animated:YES completion:^{
        
    }];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
