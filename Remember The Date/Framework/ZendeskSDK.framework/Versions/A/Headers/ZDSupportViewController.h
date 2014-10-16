//
//  ZDSupportViewController.h
//  ZDHelpCenter
//
//  Created by Zendesk on 10/09/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ZDUIUIViewController.h"

@class ZDSupportView, ZDHelpCenterCategory, ZDHelpCenterSection;



@interface ZDSupportViewController : ZDUIUIViewController <UIScrollViewDelegate, UISearchBarDelegate>


/**
 * The support view that displays help center content.
 */
@property (nonatomic, strong) ZDSupportView *supportView;


/**
 * Initializes the support controller with the list of categories in help center.
 */
- (instancetype) init;


/**
 * Initializes the support controller with the list of sections in the given category.
 *
 * @param category A help center category. The sections in this category will be loaded in the view.
 */
- (instancetype) initWithCategory:(ZDHelpCenterCategory *)category;


/**
 * Initializes the support controller with the list of articles in the given section.
 *
 * @param section A help center section. The articles in this section will be loaded in the view.
 */
- (instancetype) initWithSection:(ZDHelpCenterSection *)section;


@end
