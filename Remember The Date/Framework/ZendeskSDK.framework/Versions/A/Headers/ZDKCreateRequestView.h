//
//  ZDKCoreCreateRequestView.h
//  ZendeskSDK
//
//  Created by Zendesk on 31/10/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ZDKSpinnerDelegate.h"

@class ZDKUITextView;


/**
 * Request creation view.
 */
@interface ZDKCreateRequestView : UIView <UIAppearanceContainer>


/**
 * Text view for request description.
 */
@property (nonatomic, strong) ZDKUITextView *textView;

/**
 * Text view for request email address
 */
@property (nonatomic, strong) UITextField *emailTextView;

/**
 * Spacer view between description and email field
 */
@property (nonatomic, strong) UIView *seperatorView;

/**
 * Color for the text views placeholder text.
 */
@property (nonatomic, strong) UIColor *placeholderTextColor UI_APPEARANCE_SELECTOR;


/**
 * Color for the text entry text.
 */
@property (nonatomic, strong) UIColor *textEntryColor UI_APPEARANCE_SELECTOR;

/**
 * Color for the background color of the text view
 */
@property (nonatomic, strong) UIColor *textEntryBackgroundColor UI_APPEARANCE_SELECTOR;

/**
 * Background color for the view.
 */
@property (nonatomic, strong) UIColor *viewBackgroundColor UI_APPEARANCE_SELECTOR;


/**
 * Font for the text entry view.
 */
@property (nonatomic, strong) UIFont *textEntryFont UI_APPEARANCE_SELECTOR;


/**
 * Loading spinner for the request creation view.
 */
@property (nonatomic, strong) id<ZDKSpinnerDelegate> spinner UI_APPEARANCE_SELECTOR;


/**
 * Color of the separator between description and email text inputs
 */
@property (nonatomic, strong) UIColor *separatorBackgroundColor UI_APPEARANCE_SELECTOR;


/**
 * Font for the email entry view.
 */
@property (nonatomic, strong) UIFont *emailEntryFont UI_APPEARANCE_SELECTOR;


/**
 * Color for the email entry text
 */
@property (nonatomic, strong) UIColor *emailEntryTextColor UI_APPEARANCE_SELECTOR;


/**
 * Background color for the email entry view
 */
@property (nonatomic, strong) UIColor *emailEntryBackgroundColor UI_APPEARANCE_SELECTOR;


/**
 * Number either 0 == NO, anything else is YES
 */
@property (nonatomic, assign) NSInteger automaticallyHideNavBarOnLandscape  UI_APPEARANCE_SELECTOR;


@end
