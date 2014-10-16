//
//  ZendeskSDKConstants.h
//  ZendeskSDK
//
//  Created by Zendesk on 08/10/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//



#pragma mark - ZDToast

/**
 * Default toast animation time.
 */
extern NSTimeInterval const ZD_DefaultAnimationTime;


#pragma mark - ZDAPI

/**
 * Notification that the SDK config has been updated from the server.
 * This notification will only be sent if a change has been detected.
 */
extern NSString * const ZDAPI_ConfigUpdated;

/**
 * Notification for triggering storage of requests.
 */
extern NSString * const ZDAPI_RequestsUpdated;

/**
 * Notification for triggering storage of users.
 */
extern NSString * const ZDAPI_UsersUpdated;

/**
 * Notification that a comment is about to be submitted.
 */
extern NSString * const ZDAPI_CommentSubmissionStarting;

/**
 * Notification that a comment has been successfully submitted.
 */
extern NSString * const ZDAPI_CommentSubmissionSuccess;

/**
 * Notification that there was an error during comment submission.
 */
extern NSString * const ZDAPI_CommentSubmissionError;

/**
 * Notification that a request is about to be submitted.
 */
extern NSString * const ZDAPI_RequestSubmissionStarting;

/**
 * Notification that a request has been successfully submitted.
 */
extern NSString * const ZDAPI_RequestSubmissionSuccess;

/**
 * Notification that there was an error during request submission.
 */
extern NSString * const ZDAPI_RequestSubmissionError;

/**
 * Notification that the request list is about to be retrieved.
 */
extern NSString * const ZDAPI_RequestsStarting;

/**
 * Notification that the request list was successfulyl retrieved.
 */
extern NSString * const ZDAPI_RequestsSuccess;

/**
 * Notification that there was an error while retrieving the request list.
 */
extern NSString * const ZDAPI_RequestsError;

/**
 * Notification that the network status has changed.
 */
extern NSString * const ZDAPI_ReachabilityChangedNotification;



#pragma mark - Help Center


/**
 * Notification that help centre categories were updated.
 */
extern NSString * const ZD_HC_CategoriesUpdated;

/**
 * Notification that help centre sections were updated.
 */
extern NSString * const ZD_HC_SectionsUpdated;

/**
 * Notification that help centre arcticles were updated.
 */
extern NSString * const ZD_HC_ArticlesUpdated;


/**
 * Notification that help centre arcticles were updated.
 */
extern NSString * const ZD_HC_AttachmentsUpdated;


/**
 * Notification that help centre search results have been successfully retrieved.
 */
extern NSString * const ZD_HC_SearchSuccess;


/**
 * Notification that a help centre category was selected.
 */
extern NSString * const ZD_HC_CategorySelected;


/**
 * Notification that a help centre category was selected.
 */
extern NSString * const ZD_HC_SectionSelected;



/**
 * Notification that a help centre article was selected.
 */
extern NSString * const ZD_HC_SectionArticle;


/**
 * Notification that a help centre request errored.
 */
extern NSString * const ZD_HC_RequestError;


/**
 * Notification for resigning first responder.
 */
extern NSString * const ZD_ResignFirstResponder;


#pragma mark - HTTP Header


// HTTP
extern NSString * const ZDD_HTTPPost;
extern NSString * const ZDD_HTTPGet;
extern NSString * const ZDD_HTTPPut;
extern NSString * const ZDD_HTTPDelete;

// HEADERS
extern NSString * const ZDD_ContentType;
extern NSString * const ZDD_Accept;
extern NSString * const ZDD_TypeJSON;
extern NSString * const ZDD_UserAgent;
extern NSString * const ZDD_UserAgentValue;


#pragma mark - Error Domain


// ERRORS
/// error domain for any error reported by the API.
extern NSString * const ZDD_ERROR_Domain;
/// dictionary key for the API error message in the NSError user info dictionary.
extern NSString * const ZDD_ERROR_Key;


#pragma mark - ZDRMA


// itunes link formats
extern NSString * const iOS7AppStoreURLFormat;
extern NSString * const iOSAppStoreURLFormat;


// zendesk request submission strings
extern NSString * const ZDRMARequestFeedbackTag;
extern NSString * const ZDRMARequestIOSTag;
extern NSString * const ZDRMARequestBuildVariantTag;


// persistence keys
extern NSString * const ZDRMAChosenAction;
extern NSString * const ZDRMADateOfActionChosen;
extern NSString * const ZDRMAAppVersion;
extern NSString * const ZDRMAVisitCount;
extern NSString * const ZDRMAInitialCheckDate;
extern NSString * const ZDRMARequestText;


// default accessibility id
extern NSString * const ZDRMAAccessibilityID;


// notifications

/** Posted immediately prior to the display of RMA dialog. */
extern NSString * const ZDRMANotificationTriggered;

/** User tapped 'Yes rate'. */
extern NSString * const ZDRMANotificationYes;

/** User tapped 'No, send feedback'. */
extern NSString * const ZDRMANotificationNo;

/** User tapped 'Don't ask again' */
extern NSString * const ZDRMANotificationDontAsk;

/** User tapped 'back' on send feedback modal. */
extern NSString * const ZDRMANotificationBack;

/** User has tapped to send feedback. */
extern NSString * const ZDRMANotificationSend;

/** Posted immediately prior to the dismissal of RMA dialog. User info is a dictionary with a reference to the Dialog */
extern NSString * const ZDRMANotificationWillHideDialog;

/** Used internally to trigger state persistence. */
extern NSString * const ZDRMANotificationShouldStore;

/** Posted immediately after a successful submission of RMA feedback. */
extern NSString * const ZDRMANotificationFeedbackSuccess;

/** Posted immediately after an unsuccessful submission of RMA feedback. */
extern NSString * const ZDRMANotificationFeedbackError;

