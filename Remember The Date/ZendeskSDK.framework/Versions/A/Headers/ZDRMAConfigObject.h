//
//  ZDRMAConfigObject.h
//  ZDRateMyApp
//
//  Created by Zendesk on 24/03/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZDRMADataObject.h"


/**
 * A block to decide whether to show the Rate My App dialog. Returning YES will show the Rate My App dialog.
 *
 * @param visitCount the number of times a user has visited the view which Rate My App will be dislayed on top of.
 * @param initialCheckDate the date which ShouldShow was first run.
 * @param lastDisplayDate the date Rate My App was last displayed.
 * @param lastOptionSelected the action chosen the last time Rate My App was shown.
 * @param appVersionAtLastInteraction the version of the app when Rate My App was last shown.
 *
 * @return Returning YES causes the Rate My App dialog to be displayed. NO causes nothing to be displayed.
 */
typedef BOOL (^ShouldShow) (NSNumber *visitCount, NSDate *initialCheckDate, NSDate *lastDisplayDate, ZDRMAAction lastOptionSelected, NSString *appVersionAtLastInteraction);


/**
 * A block for sending the description in ZDRMAFeedbackView to some endpoint. The default behaviour creates a request
 * using the zendesk subdomain in ZDRMA.
 *
 * @param feedback The contents of the text view in ZDRMAFeedbackView.
 */
typedef void (^SendFeedback) (NSString *feedback);


/**
 * A success block for SendFeedback.
 */
typedef void (^SendFeedbackSuccess) (void);


/**
 * An error block for SendFeedback.
 */
typedef void (^SendFeedbackError) (void);


/**
 *
 * ZDRMAConfigObject encapsulates the configurable properties of ZDRMA. A 
 * ZDRMAConfigObject is supplied to the ZDRMA configure method:
 *
 * @see + configure: in ZDRMA.h
 * 
 * To override the default settings of ZDRMA, call the configure method and 
 * set new values as desired.
 *
 */
@interface ZDRMAConfigObject : NSObject <NSCopying>


/**
 *
 * Is RMA enabled.
 *
 */
@property (nonatomic, readonly, getter = isEnabled) BOOL enabled;


/**
 *
 * A threshold for visit count. By default minimumVisits in conjunction with
 * minimumDays are set to ensure that an app has been used enough for a rating
 * to be of value.
 *
 * The default value is 15.
 *
 */
@property (nonatomic, strong, readonly) NSNumber *minimumVisits;

/**
 * A threshold in days since the initial call to logVisit. By default minimumDays 
 * in conjunction with minimumVisits are set to ensure that an app has been used
 * enough for a rating to be of value.
 *
 * The default value is 7.
 */
@property (nonatomic, strong, readonly) NSNumber *minimumDays;

/**
 * Your itunes app id. This is used to link to the app store.
 * You must set this in the configure method of ZDRMA.
 *
 * Default value is nil.
 */
@property (nonatomic, strong, readonly) NSString *itunesAppId;

/**
 * The delay in seconds between a call to [ZDRMA showInView:view] and ZDRMA 
 * being displayed.
 *
 * The default value is 2.0.
 */
@property (nonatomic, strong, readonly) NSNumber *displayDelay;


/**
 * Tags to be set on the new request.
 *
 * Default value is set in the lotus config. These tags are concatinated with additionalTags.
 */
@property (nonatomic, strong, readonly) NSArray *serverConfigTags;


/**
 * Additional tags to be set on the new request.
 *
 * Default value is nil.
 */
@property (nonatomic, strong) NSArray *additionalTags;

/**
 * Additional info to be included in the new request, this will be added 
 * above the device info and below the user request.
 *
 * Default value is nil.
 */
@property (nonatomic, strong) NSString *additionalRequestInfo;

/**
 * An array that specifies the options in the dialog view.
 *
 * @see - arrayWithZDRMAActions:
 *
 * Default value is @[ZDRMARateApp, ZDRMASendFeedback, ZDRMADontAskAgain]
 */
@property (nonatomic, strong) NSArray *dialogActions;

/**
 * The name of the image shown on successful feedback submission. The image will
 * be centred in the available area, which is 500 x 160. Images larger than this
 * will be cropped.
 *
 * Default value is nil.
 */
@property (nonatomic, strong) NSString *successImageName;

/**
 * The name of the image shown feedback submission fails. The image will
 * be centred in the available area, which is 500 x 160. Images larger than this
 * will be cropped.
 *
 * Default value is nil.
 */
@property (nonatomic, strong) NSString *errorImageName;

/**
 * A block that is responsible for deciding whether Rate My App is shown or not.
 * When a call to [ZDRMA showInView:view] is made, this block is invoked.
 *
 * Returning YES results in Rate My App being shown. Returning NO will mean 
 * Rate My App is not shown. Can be overridden for custom behaviour.
 * 
 * Default implementation returns YES if the visitCount is greater than 
 * minimumVisitCount and days since initialCheckDate is greater than 
 * minimumDays, and returns NO otherwise.
 *
 */
@property (nonatomic, copy, readonly) ShouldShow shouldShowBlock;

/**
 * A block that is invoked when the "Send feedback" button is pressed. 
 *
 * The default implementation creates a request with the Zendesk account specified 
 * by zendeskSubdomain and userEmail.
 *
 */
@property (nonatomic, copy) SendFeedback sendFeedbackBlock;


/**
 * Helper method which builds an array from ZDRMAActions. This determines what actions
 * are displayed in the dialog view. The order in which they are specified in the list is 
 * the order that they will appear in the dialog.
 *
 * This is used during the initialisation of ZDRMAConfigObject to set the default values 
 * of the dialogActions property.
 *
 * @see ZDRMAAction, dialogActions.
 *
 * @param action A comma sepporated list of ZDRMAAtion values with a nil terminator.
 * @return An array of ZDRMAActions as NSNumbers.
 */
+ (NSArray*) arrayWithZDRMAActions:(ZDRMAAction) action, ...;


/**
 * A helper method that calculates the number of days between two NSDate object.
 *
 * @param fromDate The start date.
 * @param toDate The end date.
 * @return The number of days between the dates.
 */
+ (NSInteger) daysBetweenDate:(NSDate*)fromDate andDate:(NSDate*)toDate;


/**
 * A helper method that concatenates the server config tags with the additional tags.
 *
 * @return An array containing all tags in serverConfigTags and additionalTags.
 */
- (NSArray *) tagList;

@end
