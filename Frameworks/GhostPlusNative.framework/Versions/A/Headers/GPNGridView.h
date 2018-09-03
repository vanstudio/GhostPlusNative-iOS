//
//  GPNGridView.h
//  NativeFrameworkSample
//
//  Created by VANSTUDIO on 2017. 7. 28..
//  Copyright © 2017년 VANSTUDIO. All rights reserved.
//

#import <UIKit/UIKit.h>


@protocol GPNGridViewDataSource;
@protocol GPNGridViewDelegate;
@protocol GPNGridViewDelegateFlowLayout;
@protocol GPNGridViewScrollDelegate;

@class GPNGridViewCell;
@class GPNGridReusableView;

/**
 GPNGridView
 네이티브 전시 리스트뷰
 */
@interface GPNGridView : UIView

/** data source */
@property (nonatomic, weak) id <GPNGridViewDataSource> dataSource;
/** delegate */
@property (nonatomic, weak) id <GPNGridViewDelegate> delegate;
/** scroll delegate */
@property (nonatomic, weak) id <GPNGridViewScrollDelegate> scrollDelegate;
/** scroll deceleration rate */
@property (nonatomic, assign) CGFloat decelerationRate;
/** scroll content offset */
@property (nonatomic, assign) CGPoint contentOffset;
/** collection view */
@property (nonatomic, strong, readonly) UICollectionView *collectionView;

/** register nib */
- (void)registerNib:(UINib *)nib forCellWithReuseIdentifier:(NSString *)identifier;
/** register nib */
- (void)registerNib:(UINib *)nib forHeaderViewWithReuseIdentifier:(NSString *)identifier;
/** register nib */
- (void)registerNib:(UINib *)nib forFooterViewWithReuseIdentifier:(NSString *)identifier;

/** set content offset */
- (void)setContentOffset:(CGPoint)contentOffset animated:(BOOL)animated;
/** reload data */
- (void)reloadData;
/** reload sections */
- (void)reloadSections:(NSIndexSet *)sections animated:(BOOL)animated;
/** insert sections */
- (void)insertSections:(NSIndexSet *)sections animated:(BOOL)animated;
/** delete sections */
- (void)deleteSections:(NSIndexSet *)sections animated:(BOOL)animated;

/** dequeue reusable cell */
- (UICollectionViewCell *)dequeueReusableCellForIndexPath:(NSIndexPath *)indexPath;
/** dequeue reusable header view */
- (UICollectionReusableView *)dequeueReusableHeaderViewForIndexPath:(NSIndexPath *)indexPath;
/** dequeue reusable footer view */
- (UICollectionReusableView *)dequeueReusableFooterViewForIndexPath:(NSIndexPath *)indexPath;

/** get row */
- (NSInteger)rowAtIndexPath:(NSIndexPath *)indexPath;
/** get column */
- (NSInteger)columnAtIndexPath:(NSIndexPath *)indexPath;

/** invalidate layout header view */
- (void)invalidateLayoutHeaderView:(UICollectionReusableView *)view inSection:(NSInteger)section;
/** invalidate layout footer view */
- (void)invalidateLayoutFooterView:(UICollectionReusableView *)view inSection:(NSInteger)section;

@end


/**
 GPNGridViewDataSource
 데이터 소스
 
 */
@protocol GPNGridViewDataSource <NSObject>
@required
- (NSInteger)gridView:(GPNGridView *)gridView numberOfColumnsInSection:(NSInteger)section;
- (NSInteger)gridView:(GPNGridView *)gridView numberOfItemsInSection:(NSInteger)section;
- (NSString *)gridView:(GPNGridView *)gridView cellReuseIdentifierForItemAtSection:(NSUInteger)section;
- (UICollectionViewCell *)gridView:(GPNGridView *)gridView cellForItemAtIndexPath:(NSIndexPath *)indexPath;	// The cell that is returned must be retrieved from a call to -dequeueReusableCellForIndexPath:

@optional
- (NSInteger)numberOfSectionsInGridView:(GPNGridView *)gridView;
- (NSString *)gridView:(GPNGridView *)gridView headerViewReuseIdentifierAtSection:(NSUInteger)section;
- (NSString *)gridView:(GPNGridView *)gridView footerViewReuseIdentifierAtSection:(NSUInteger)section;
- (UICollectionReusableView *)gridView:(GPNGridView *)gridView headerViewAtIndexPath:(NSIndexPath *)indexPath;	// The view that is returned must be retrieved from a call to -dequeueReusableHeaderViewForSection:
- (UICollectionReusableView *)gridView:(GPNGridView *)gridView footerViewAtIndexPath:(NSIndexPath *)indexPath;	// The view that is returned must be retrieved from a call to -dequeueReusableFooterViewForSection:
- (BOOL)gridView:(GPNGridView *)gridView shouldCellAutoSizeAtSection:(NSInteger)section;	// default is NO
- (void)gridView:(GPNGridView *)gridView updateDataForCellAutoSizeWithCell:(UICollectionViewCell *)cell atIndexPath:(NSIndexPath *)indexPath;	// must be implementation -gridView:shouldCellAutoSizeAtSection:
@end

/**
 GPNGridViewDelegate
 델리게이트
 */
@protocol GPNGridViewDelegate <NSObject>
@optional
- (BOOL)gridView:(GPNGridView *)gridView shouldHighlightItemAtIndexPath:(NSIndexPath *)indexPath;
- (void)gridView:(GPNGridView *)gridView didHighlightItemAtIndexPath:(NSIndexPath *)indexPath;
- (void)gridView:(GPNGridView *)gridView didUnhighlightItemAtIndexPath:(NSIndexPath *)indexPath;
- (BOOL)gridView:(GPNGridView *)gridView shouldSelectItemAtIndexPath:(NSIndexPath *)indexPath;
- (BOOL)gridView:(GPNGridView *)gridView shouldDeselectItemAtIndexPath:(NSIndexPath *)indexPath;
- (void)gridView:(GPNGridView *)gridView didSelectItemAtIndexPath:(NSIndexPath *)indexPath;
- (void)gridView:(GPNGridView *)gridView didDeselectItemAtIndexPath:(NSIndexPath *)indexPath;

- (void)gridView:(GPNGridView *)gridView willDisplayCell:(UICollectionViewCell *)cell forItemAtIndexPath:(NSIndexPath *)indexPath;
- (void)gridView:(GPNGridView *)gridView willDisplaySupplementaryView:(UICollectionReusableView *)view forElementKind:(NSString *)elementKind atIndexPath:(NSIndexPath *)indexPath;
- (void)gridView:(GPNGridView *)gridView didEndDisplayingCell:(UICollectionViewCell *)cell forItemAtIndexPath:(NSIndexPath *)indexPath;
- (void)gridView:(GPNGridView *)gridView didEndDisplayingSupplementaryView:(UICollectionReusableView *)view forElementOfKind:(NSString *)elementKind atIndexPath:(NSIndexPath *)indexPath;

- (BOOL)gridView:(GPNGridView *)gridView shouldShowMenuForItemAtIndexPath:(NSIndexPath *)indexPath;
- (BOOL)gridView:(GPNGridView *)gridView canPerformAction:(SEL)action forItemAtIndexPath:(NSIndexPath *)indexPath withSender:(id)sender;
- (void)gridView:(GPNGridView *)gridView performAction:(SEL)action forItemAtIndexPath:(NSIndexPath *)indexPath withSender:(id)sender;
@end


/**
 GPNGridViewDelegateFlowLayout
 델리게이트 플로우 레이아웃
 */
@protocol GPNGridViewDelegateFlowLayout <GPNGridViewDelegate>
@optional
- (UIEdgeInsets)gridView:(GPNGridView *)gridView layout:(UICollectionViewLayout*)collectionViewLayout insetForSectionAtIndex:(NSInteger)section;
- (CGFloat)gridView:(GPNGridView *)gridView layout:(UICollectionViewLayout*)collectionViewLayout minimumLineSpacingForSectionAtIndex:(NSInteger)section;
- (CGFloat)gridView:(GPNGridView *)gridView layout:(UICollectionViewLayout*)collectionViewLayout minimumInteritemSpacingForSectionAtIndex:(NSInteger)section;
- (UIColor *)gridView:(GPNGridView *)gridView layout:(UICollectionViewLayout*)collectionViewLayout separatorColorAtSection:(NSInteger)section;
- (CGFloat)gridView:(GPNGridView *)gridView layout:(UICollectionViewLayout*)collectionViewLayout separatorLineWidthAtSection:(NSInteger)section;
@end


/**
 GPNGridViewScrollDelegate
 스크롤 델리게이트
 */
@protocol GPNGridViewScrollDelegate <NSObject>
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


/**
 GPNGridViewCell
 그리드뷰 셀
 */
@interface GPNGridViewCell : UICollectionViewCell
@property (weak, nonatomic, readonly) GPNGridView *gridView;
@property (strong, nonatomic, readonly) NSIndexPath *indexPath;
@end


/**
 GPNGridReusableView
 그리드 재사용뷰
 */
@interface GPNGridReusableView : UICollectionReusableView
@property (weak, nonatomic, readonly) GPNGridView *gridView;
@property (strong, nonatomic, readonly) NSIndexPath *indexPath;
@end
