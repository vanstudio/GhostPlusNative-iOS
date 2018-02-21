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
@protocol GPNDynamicBannerViewScrollDelegate;


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
/** scroll delegate */
@property (nonatomic, weak) id <GPNDynamicBannerViewScrollDelegate> scrollDelegate;

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
/** select item */
- (void)selectItemAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated scrollPosition:(UICollectionViewScrollPosition)scrollPosition;
/** deselect item */
- (void)deselectItemAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated;
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
- (BOOL)dynamicBannerView:(GPNDynamicBannerView *)dynamicBannerView shouldHighlightItemAtIndex:(NSInteger)index;
- (void)dynamicBannerView:(GPNDynamicBannerView *)dynamicBannerView didHighlightItemAtIndex:(NSInteger)index;
- (void)dynamicBannerView:(GPNDynamicBannerView *)dynamicBannerView didUnhighlightItemAtIndex:(NSInteger)index;
- (BOOL)dynamicBannerView:(GPNDynamicBannerView *)dynamicBannerView shouldSelectItemAtIndex:(NSInteger)index;
- (BOOL)dynamicBannerView:(GPNDynamicBannerView *)dynamicBannerView shouldDeselectItemAtIndex:(NSInteger)index;
- (void)dynamicBannerView:(GPNDynamicBannerView *)dynamicBannerView didSelectItemAtIndex:(NSInteger)index;
- (void)dynamicBannerView:(GPNDynamicBannerView *)dynamicBannerView didDeselectItemAtIndex:(NSInteger)index;

- (void)dynamicBannerView:(GPNDynamicBannerView *)dynamicBannerView willDisplayCell:(UICollectionViewCell *)cell forItemAtIndex:(NSInteger)index;
- (void)dynamicBannerView:(GPNDynamicBannerView *)dynamicBannerView willDisplaySupplementaryView:(UICollectionReusableView *)view forElementKind:(NSString *)elementKind atIndex:(NSInteger)index;
- (void)dynamicBannerView:(GPNDynamicBannerView *)dynamicBannerView didEndDisplayingCell:(UICollectionViewCell *)cell forItemAtIndex:(NSInteger)index;
- (void)dynamicBannerView:(GPNDynamicBannerView *)dynamicBannerView didEndDisplayingSupplementaryView:(UICollectionReusableView *)view forElementOfKind:(NSString *)elementKind atIndex:(NSInteger)index;
@end


/**
 GPNDynamicBannerViewScrollDelegate
 스크롤 델리게이트
 */
@protocol GPNDynamicBannerViewScrollDelegate <NSObject>
@optional
- (void)scrollViewDidScroll:(UIScrollView *)scrollView;
- (void)scrollViewDidZoom:(UIScrollView *)scrollView;
- (void)scrollViewWillBeginDragging:(UIScrollView *)scrollView;
- (void)scrollViewWillEndDragging:(UIScrollView *)scrollView withVelocity:(CGPoint)velocity targetContentOffset:(inout CGPoint *)targetContentOffset;
- (void)scrollViewDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate;
- (void)scrollViewWillBeginDecelerating:(UIScrollView *)scrollView;
- (void)scrollViewDidEndDecelerating:(UIScrollView *)scrollView;
- (void)scrollViewDidEndScrollingAnimation:(UIScrollView *)scrollView;
- (BOOL)scrollViewShouldScrollToTop:(UIScrollView *)scrollView;
- (void)scrollViewDidScrollToTop:(UIScrollView *)scrollView;
@end
