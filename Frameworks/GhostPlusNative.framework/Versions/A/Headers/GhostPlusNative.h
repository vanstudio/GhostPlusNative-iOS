//
//  GhostPlusNative.h
//  GhostPlusNative
//
//  Created by VANSTUDIO
//  Copyright © 2016년 GhostPlus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// GhostPlus
#import <GhostPlus/GhostPlus.h>

// Constant
#define GhostPlusNative_BUNDLE	[GhostPlusNative bundle]

// Library

// Module
#import <GhostPlusNative/GPNBannerView.h>
#import <GhostPlusNative/GPNDynamicBannerView.h>
#import <GhostPlusNative/GPNGridView.h>

// Constans
#define GhostPlusNative_VERSION           @"1.23";
#define GhostPlusNative_BUILD_VERSION     @"123";


/**
 GhostPlusNative 메인클래스
 */
@interface GhostPlusNative : NSObject

/**
 GhostPlusNative 번들
 */
+ (NSBundle *)bundle;

/** 
 GhostPlusNative 번들로부터 이미지 불러오기
 @param filename 파일이름
 */
+ (UIImage *)imageWithFilename:(NSString *)filename;

@end
