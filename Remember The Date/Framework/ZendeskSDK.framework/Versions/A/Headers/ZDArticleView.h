//
//  ZDArticleView.h
//  ZDHelpCenter
//
//  Created by Zendesk on 24/09/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <UIKit/UIKit.h>

@class ZDHelpCenterArticle;

@interface ZDArticleView : UIView


/**
 * Scroll view that contains the article webview and attachments table
 */
@property (nonatomic, strong) UIScrollView *article;

/**
 * Article title label.
 */
@property (nonatomic, strong) UILabel *articleTitle;

/**
 * The article body.
 */
@property (nonatomic, strong) UIWebView *articleWebView;

/**
 * Displays the author and creation date.
 */
@property (nonatomic, strong) UILabel *articleDetails;

/**
 * A table for article attachments.
 */
@property (nonatomic, strong) UITableView *attachments;


@property (nonatomic, assign, readonly, getter=isLoading) BOOL loading;


/**
 * Initializes the article controller with an article.
 *
 * @param article A help center article.
 */
- (instancetype) initWithArticle:(ZDHelpCenterArticle *)article;


/**
 * Reloads the help center article webview on rotation.
 *
 */
- (void) reloadArticleForRotation;


@end