//
//  ZDToastView.h
//  ZDToast
//
//  Created by Zendesk on 12/05/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "ZDToastStyle.h"


#import "ZDToastStyle.h"


/**
 * Toast animation block.
 * @param animatingIn YES if animating in, NO if animating out
 * @param height toast message height
 */
typedef void (^ZDToastAnimation) (BOOL animatingIn, CGFloat height);


/**
 * Toast button action block.
 */
typedef void (^ZDToastButtonAction) (void);


/**
 * Toast button action block.
 */
typedef void (^ZDToastCompletion) (void);


/**
 * The view for presenting default toast messages.
 * @since 0.1
 */
@interface ZDToastView : UIView {
    
    /**
     * The actual toast content.
     * @since 0.1
     */
    UIView *toast;
    
    /**
     * Single pixel lower border.
     * @since 0.1
     */
    UIView *lowerBorder;
    
    /**
     * The message itself.
     * @since 0.1
     */
    UILabel *text;
    
    /**
     * Animation time.
     * @since 0.1
     */
    NSTimeInterval animationTime;
    
    /**
     * Presentation time.
     * @since 0.1
     */
    NSTimeInterval durationInSeconds;
    
    /**
     * Dismiss button
     * @since 0.2
     */
    UIButton *button;
    
}


#pragma mark - Animation Properties


/**
 * Timestamp for the point at which the toast has finished animating in.
 * @since 0.1
 */
@property (strong) NSDate *timePresented;


/**
 * Animation block run when animating in and out.
 */
@property (nonatomic, copy) ZDToastAnimation animationBlock;


/**
 * Block to be run when the toast button is pressed.
 */
@property (nonatomic, copy) ZDToastButtonAction buttonBlock;


#pragma mark - Parent View Controller


/**
 * The parent view controller specified when presenting the toast.
 */
@property (nonatomic, weak) UIViewController *viewController;


#pragma mark - Lifecycle


/**
 * Initialise and animate in a new toast.
 * @param view the view in which the toast is to be presented
 * @param initialYPosisition the y for the start of the toast frame
 * @param message the text to be presented
 * @param type the ZDToastTypeEnum type of the toast
 * @param durationInSeconds the duration for which the toast should be fully visible
 * @param animationTime the time the toast should spend per animation in/out
 * @param animationBlock animations to be run while presenting the Toast
 * @param animateIn YES to animate in
 * @since 0.1
 */
- (instancetype) initInView:(UIView*)view
          forViewController:(UIViewController*)viewController
                        atY:(CGFloat)initialYPosisition
                withMessage:(NSString*)message
                 buttonText:(NSString*)buttonText
               buttonAction:(ZDToastButtonAction)buttonActionBlock
                    andType:(ZDToastUIType)type
                   duration:(NSTimeInterval)durationInSeconds
              animationTime:(NSTimeInterval)animationTime
                  animation:(ZDToastAnimation)animationBlock
                  animateIn:(BOOL)animateIn;


#pragma mark Presentation and Dissmissal


/**
 * Present this toast.
 * @param animate if YES animate the dismiss
 */
- (void) present:(BOOL)animate;


/**
 * Dismiss this toast.
 * @param animate if YES animate the dismiss
 */
- (void) dismiss:(BOOL)animate;


/**
 * Dismiss this toast.
 * @param animate if YES animate the dismiss
 * @param completion A block that is executed after the toast has been dismissed.
 */
- (void) dismiss:(BOOL)animate comepletion:(ZDToastCompletion)completion;


@end
