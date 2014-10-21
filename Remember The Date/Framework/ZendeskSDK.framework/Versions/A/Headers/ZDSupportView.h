//
//  ZDSupportView.h
//  ZDHelpCenter
//
//  Created by Zendesk on 11/09/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 * A view that displays help center content.
 */
@interface ZDSupportView : UIView

/**
 * Lists categorys, sections and articles.
 */
@property (nonatomic, strong) UITableView *table;

/**
 * Seach field for searching help center content.
 */
@property (nonatomic, strong) UISearchBar *searchField;

/**
 * loading spinner. 
 */
@property (nonatomic, strong) UIActivityIndicatorView *spinner;

@property (nonatomic, strong) UIColor * btnContactUsColor UI_APPEARANCE_SELECTOR;


/**
 * Sets the state of the support view. YES changes the view to a loading
 * state with a spinner, NO shows the tabel as normal.
 */
@property (nonatomic, assign, getter=isLoading, setter=setLoading:) BOOL loading;


@end
