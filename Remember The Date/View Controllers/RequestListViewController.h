//
//  RequestListViewController.h
//  CoreSDKSample
//
//  Created by Zendesk on 09/07/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <ZendeskSDK/ZDCoreSDK.h>


@interface RequestListViewController : ZDUIUIViewController


@property (nonatomic, strong) UIScrollView *requestListContainer;
@property (nonatomic, strong) UIView *header;
@property (nonatomic, strong) ZDRequestListTable *requestList;


@end

