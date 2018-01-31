//
//  GPNBannerView.h
//  GhostPlusNative
//
//  Created by VANSTUDIO on 2017. 7.
//  Copyright © 2017년 VANSTUDIO. All rights reserved.
//

#import <UIKit/UIKit.h>


@protocol GPNBannerViewDataSource;
@protocol GPNBannerViewDelegate;


@interface GPNBannerViewOptions : NSObject
@property (nonatomic, assign) BOOL infinite;					// default is NO
@property (nonatomic, assign) BOOL autoScroll;					// default is NO
@property (nonatomic, assign) NSTimeInterval autoScrollDelay;	// default is 3.0
@property (nonatomic, assign) UIEdgeInsets contentInset;		// default is UIEdgeInsetsZero
@property (nonatomic, assign) CGFloat itemSpacing;				// default is 0
@property (nonatomic, assign) CGFloat decelerationRate;			// default is UIScrollViewDecelerationRateFast 
@end

/**
 GPNBannerView
 네이티브 배너뷰
 */
@interface GPNBannerView : UIView
/** data source */
@property (nonatomic, weak) id <GPNBannerViewDataSource> dataSource;
/** delegate */
@property (nonatomic, weak) id <GPNBannerViewDelegate> delegate;
/** current page */
@property (nonatomic, assign) NSInteger currentPage;

/** init with options */
- (instancetype)initWithOptions:(GPNBannerViewOptions *)options;
/** register nib */
- (void)registerNib:(UINib *)nib forCellWithReuseIdentifier:(NSString *)identifier;
/** dequeue reusable cell */
- (UICollectionViewCell *)dequeueReusableCellWithReuseIdentifier:(NSString *)identifier forIndexPath:(NSIndexPath *)indexPath;
/** set current page */
- (void)setCurrentPage:(NSInteger)currentPage animated:(BOOL)animated;
/** move prev page */
- (void)prevPageWithAnimated:(BOOL)animated;
/** move next page */
- (void)nextPageWithAnimated:(BOOL)animated;
/** reload data */
- (void)reloadData;
/** set bounces */
- (void)setBounces:(BOOL)bounces;
/** get auto scrolling state */
- (BOOL)isAutoScrolling;
/** start auto scroll */
- (void)startAutoScroll;
/** stop auto scroll */
- (void)stopAutoScroll;
@end


/**
 GPNBannerViewDataSource
 배너뷰 데이터소스
 */
@protocol GPNBannerViewDataSource <NSObject>
@required
- (NSInteger)numberOfItemsInBannerView:(GPNBannerView *)bannerView;
- (UICollectionViewCell *)bannerView:(GPNBannerView *)bannerView cellForItemAtIndexPath:(NSIndexPath *)indexPath;	// The cell that is returned must be retrieved from a call to -dequeueReusableCellWithReuseIdentifier:forIndexPath
@end


/**
 GPNBannerViewDelegate
 배너뷰 델리게이트
 */
@protocol GPNBannerViewDelegate <UIScrollViewDelegate>
@optional
- (void)bannerView:(GPNBannerView *)bannerView didScrollItemAtIndex:(NSInteger)index;
- (void)bannerView:(GPNBannerView *)bannerView didSelectItemAtIndex:(NSInteger)index;
@end


/**
 GPNBannerImageCell
 배너 이미지셀
 */
@interface GPNBannerImageCell : UICollectionViewCell
+ (NSString *)identifier;
@property (nonatomic, strong) UIImageView *aImageView;
@end
