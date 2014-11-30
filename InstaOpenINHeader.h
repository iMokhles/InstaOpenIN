//
//  DecFile.h
//  Rendarya
//
//  Created by iMokhles on 3/23/14.
//
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <CoreImage/CoreImage.h>
#import <MobileCoreServices/MobileCoreServices.h>
#import <objc/runtime.h>
#import <CoreMedia/CoreMedia.h>
#import <QuartzCore/QuartzCore.h>
#import <AVFoundation/AVFoundation.h>
#import <MediaPlayer/MediaPlayer.h>
#import "TTOpenInAppActivity.h"

@interface UIWindow ()
+(id)keyWindow;
@end

@class TGModernConversationController;

OBJC_EXTERN CFStringRef MGCopyAnswer(CFStringRef key) WEAK_IMPORT_ATTRIBUTE;

#define kPreferencesPath @"/User/Library/Preferences/com.imokhles.InstaOpenIN.plist"
#define kPreferencesChanged "com.imokhles.InstaOpenIN.preferences-changed"


#define kEnablePhotos @"enablePhotos"
#define kEnableVideos @"enableVideos"

static BOOL enablePhotos;
static BOOL enableVideos;
static UIPopoverController *activityPopoverController;

// InstaGram Declarations

@interface IGPost : NSObject 
{
    BOOL _hasLiked;
    BOOL _moreCommentsAvailable;
    BOOL _collapseComments;
    BOOL _needsFetch;
    int _mediaType;
    NSNumber *_deviceTimestamp;
    NSDictionary *_imageVersions;
    NSDictionary *_videoVersions;
    int _videoLength;
    NSMutableOrderedSet *_likers;
    int _likeCount;
    NSMutableArray *_pendingComments;
    NSArray *_activeComments;
    NSMutableArray *_allComments;
    NSNumber *_commentCursor;
    int _commentCount;
    NSString *_rankToken;
    NSString *_exploreContext;
}

+ (int)fullSizeImageVersionForDevice;
+ (int)videoVersionForCurrentNetworkConditions;
@property(nonatomic) BOOL needsFetch; // @synthesize needsFetch=_needsFetch;
@property(readonly, copy) NSString *exploreContext; // @synthesize exploreContext=_exploreContext;
@property(readonly) NSString *rankToken; // @synthesize rankToken=_rankToken;
- (id)urlToFlagComment:(id)arg1;
- (id)urlToDeleteComment:(id)arg1;
- (id)urlToPostComment;
- (void)schedulePostUpdatedNotification;
- (void)postPostUpdatedNotification;
- (void)commentRemoveRequestFailed:(id)arg1;
- (void)commentRemoveRequestFinished:(id)arg1;
- (void)commentRemoveRequestStarted:(id)arg1;
- (void)commentPostRequestFailedSpam:(id)arg1;
- (void)commentPostRequestFailed:(id)arg1;
- (void)commentPostRequestFinished:(id)arg1;
- (void)commentPostRequestStarted:(id)arg1;
- (void)fetchMoreCommentsWithCompletionHandler:(id)arg1;
- (void)invalidateActiveComments;
@property(readonly) NSArray *activeCaptionAndComments;
@property(readonly) NSArray *activeComments; // @synthesize activeComments=_activeComments;
- (void)removeCommentWithPK:(id)arg1;
- (void)addComment:(id)arg1;
- (void)setCommentInfoFromDictionary:(id)arg1 append:(BOOL)arg2;
@property(retain) NSMutableArray *pendingComments; // @synthesize pendingComments=_pendingComments;
@property(readonly) NSMutableArray *allComments; // @synthesize allComments=_allComments;
- (void)performLike:(BOOL)arg1 userDidDoubleTap:(BOOL)arg2 completion:(id)arg3;
- (void)updateLocalLikeStatus:(BOOL)arg1;
- (void)setLikeInfoFromDictionary:(id)arg1;
- (void)removeLocalLocationInformation;
- (void)setLocationInfoFromDictionary:(id)arg1;
- (void)fetchAdditionalInfo;
- (void)setMediaType:(int)arg1;
- (BOOL)updateWithDictionary:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;
@property(readonly) BOOL collapseComments; // @synthesize collapseComments=_collapseComments;
- (void)setCollapseComments:(BOOL)arg1;
@property(readonly) BOOL moreCommentsAvailable; // @synthesize moreCommentsAvailable=_moreCommentsAvailable;
- (void)setMoreCommentsAvailable:(BOOL)arg1;
@property(readonly) int commentCount; // @synthesize commentCount=_commentCount;
- (void)setCommentCount:(int)arg1;
@property(readonly) NSNumber *commentCursor; // @synthesize commentCursor=_commentCursor;
- (void)setCommentCursor:(id)arg1;
- (void)setCaption:(id)arg1;
- (void)setAllComments:(id)arg1;
- (void)setActiveComments:(id)arg1;
@property(readonly) BOOL hasLiked; // @synthesize hasLiked=_hasLiked;
- (void)setHasLiked:(BOOL)arg1;
@property(readonly) int likeCount; // @synthesize likeCount=_likeCount;
- (void)setLikeCount:(int)arg1;
@property(readonly) NSMutableOrderedSet *likers; // @synthesize likers=_likers;
- (void)setLikers:(id)arg1;
- (void)setMediaCoord:(id)arg1;
- (void)setLocation:(id)arg1;
@property(readonly) int videoLength; // @synthesize videoLength=_videoLength;
- (void)setVideoLength:(int)arg1;
@property(readonly) NSDictionary *videoVersions; // @synthesize videoVersions=_videoVersions;
- (void)setVideoVersions:(id)arg1;
@property(readonly) NSDictionary *imageVersions; // @synthesize imageVersions=_imageVersions;
- (void)setImageVersions:(id)arg1;
@property(readonly) NSNumber *deviceTimestamp; // @synthesize deviceTimestamp=_deviceTimestamp;
- (void)setDeviceTimestamp:(id)arg1;
- (void)setTakenAt:(id)arg1;
- (void)setUser:(id)arg1;
@property(readonly) int mediaType; // @synthesize mediaType=_mediaType;
- (id)imageURLForImageVersion:(int)arg1;
- (id)imageURLForFullSizeImage;
- (void)reportInappropriateWithCompletionHandler:(id)arg1;
- (id)allVideoURLs;
- (id)videoURLForVideoVersion:(int)arg1;

@end

@interface IGFeedItemPhotoCell : UITableViewCell

@property(retain, nonatomic) IGPost *post;
- (id)accessibleElements;
- (int)indexOfAccessibilityElement:(id)arg1;
- (id)accessibilityElementAtIndex:(int)arg1;
- (int)accessibilityElementCount;
- (void)layoutSubviews;
- (id)initWithReuseIdentifier:(id)arg1;

@end

@interface IGFeedItemVideoCell : UITableViewCell

@property(retain, nonatomic) IGPost *post;
- (id)accessibleElements;
- (int)indexOfAccessibilityElement:(id)arg1;
- (id)accessibilityElementAtIndex:(int)arg1;
- (int)accessibilityElementCount;
- (void)setNavigationController:(id)arg1;
- (void)layoutSubviews;
- (id)initWithReuseIdentifier:(id)arg1;

@end
