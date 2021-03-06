//
//  ZDKArticleViewController.h
//  ZendeskSDK
//
//  Created by Zendesk on 24/09/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ZDKUIViewController.h"

@class ZDKArticleView, ZDKHelpCenterArticle;



@interface ZDKArticleViewController : ZDKUIViewController


/**
 * The article view.
 */
@property (nonatomic, strong) ZDKArticleView *articleView;


/**
 * Initializes the article controller with an article.
 *
 * @param article A help center article.
 */
- (instancetype) initWithArticle:(ZDKHelpCenterArticle *)article;


@end
