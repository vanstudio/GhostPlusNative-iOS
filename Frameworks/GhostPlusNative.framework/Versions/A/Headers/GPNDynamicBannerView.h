//
//  GPNDynamicBannerView.h
//  GhostPlusNative
//
//  Created by VANSTUDIO on 2018. 1.
//  Copyright © 2018년 GhostPlus. All rights reserved.
//

#import <UIKit/UIKit.h>


@protocol GPNDynamicBannerViewDataSource;
@protocol GPNDynamicBannerViewDelegate;


@interface GPNDynamicBannerViewOptions : NSObject
@property (nonatomic, assign) UIEdgeInsets sectionInset;		// default is UIEdgeInsetsZero
@property (nonatomic, assign) UIEdgeInsets contentInset;		// default is UIEdgeInsetsZero
@property (nonatomic, assign) CGFloat itemSpacing;				// default is 0
@property (nonatomic, assign) CGFloat decelerationRate;			// default is UIScrollViewDecelerationRateFast
@property (nonatomic, assign) BOOL horizontally;				// default is YES
@property (nonatomic, assign) BOOL scrollMagnetic;				// default is NO
@end

/**
 GPNDynamicBannerView
 네이티브 동적 배너뷰
 */
@interface GPNDynamicBannerView : UIView
/** data source */
@property (nonatomic, weak) id <GPNDynamicBannerViewDataSource> dataSource;
/** delegate */
@property (nonatomic, weak) id <GPNDynamicBannerViewDelegate> delegate;

/** init with options */
- (instancetype)initWithOptions:(GPNDynamicBannerViewOptions *)options;
/** register nib */
- (void)registerNib:(UINib *)nib forCellWithReuseIdentifier:(NSString *)identifier;
/** dequeue reusable cell */
- (UICollectionViewCell *)dequeueReusableCellForIndexPath:(NSIndexPath *)indexPath;
/** reload data */
- (void)reloadData;
/** set bounces */
- (void)setBounces:(BOOL)bounces;
@end


/**
 GPNDynamicBannerViewDataSource
 배너뷰 데이터소스
 */
@protocol GPNDynamicBannerViewDataSource <NSObject>
@required
- (NSInteger)numberOfItemsInDynamicBannerView:(GPNDynamicBannerView *)dynamicBannerView;
- (NSString *)dynamicBannerView:(GPNDynamicBannerView *)dynamicBannerView cellReuseIdentifierForItemAtItem:(NSUInteger)item;
- (UICollectionViewCell *)dynamicBannerView:(GPNDynamicBannerView *)dynamicBannerView cellForItemAtIndexPath:(NSIndexPath *)indexPath;	// The cell that is returned must be retrieved from a call to -dequeueReusableCellWithReuseIdentifier:forIndexPath
@end


/**
 GPNDynamicBannerViewDelegate
 배너뷰 델리게이트
 */
@protocol GPNDynamicBannerViewDelegate <UIScrollViewDelegate>
@optional
- (void)dynamicBannerView:(GPNDynamicBannerView *)dynamicBannerView didSelectItemAtIndex:(NSInteger)index;
@end
