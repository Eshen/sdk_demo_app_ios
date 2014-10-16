//
//  ZDArticleViewController.h
//  ZDHelpCenter
//
//  Created by Zendesk on 24/09/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ZDUIUIViewController.h"

@class ZDArticleView, ZDHelpCenterArticle;



@interface ZDArticleViewController : ZDUIUIViewController


/**
 * The article view.
 */
@property (nonatomic, strong) ZDArticleView *articleView;


/**
 * Initializes the article controller with an article.
 *
 * @param article A help center article.
 */
- (instancetype) initWithArticle:(ZDHelpCenterArticle *)article;


@end
