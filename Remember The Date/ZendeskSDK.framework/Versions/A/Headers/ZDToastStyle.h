//
//  ZDToastStyle.h
//  ZDToast
//
//  Created by Zendesk on 13/05/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <Foundation/Foundation.h>


/**
 * Toast types providing specific styling as defined in ZDToastStyle.
 * @since 0.1
 */
typedef NS_ENUM(NSUInteger, ZDToastUIType) {
    ZDToastUITypeInfo,
    ZDToastUITypeOK,
    ZDToastUITypeWarning,
    ZDToastUITypeError,
    ZDToastUIType_count
};




/**
 * Toast styling options.
 * @since 0.1
 */
typedef NS_ENUM(NSUInteger, ZDToastUIStyle) {
    ZDToastUIStyleBackgroundColor,
    ZDToastUIStyleBorderColor,
    ZDToastUIStyleFontColor,
    ZDToastUIStyleButtonBorderColor,
    ZDToastUIStyleButtonBackgroundColor,
    ZDToastUIStyleButtonFontColor,
    ZDToastUIStyleButtonFontName,
    ZDToastUIStyleButtonFontSize,
    ZDToastUIStyleFontName,
    ZDToastUIStyleFontSize,
    ZDToastUIStyleIconName, // v0.2
    ZDToastUIStyle_count
};



/**
 * Singleton class holding the styling details for toast messages.
 * @since 0.1
 */
@interface ZDToastStyle : NSObject


/**
 * Set the style value for the specified type.
 * @param value this should be: UIColor for 'Color' styles, NSString for 'Name' styles and NSNumber for 'Size' styles
 * @param type ZDToastUIType defining the type to be styled
 * @param style ZDToastUIStyle defining the style to be set
 * @since 0.1
 */
+ (void) setValue:(id)value forType:(ZDToastUIType)type andStyle:(ZDToastUIStyle)style;



/**
 * Get the requested style value for the type.
 * @param type ZDToastUIType defining the style to be retrieved
 * @param style ZDToastUIStyle the style to be retrieved
 * @since 0.1
 */
+ (id) getValueForType:(ZDToastUIType)type andStyle:(ZDToastUIStyle)style;


@end

