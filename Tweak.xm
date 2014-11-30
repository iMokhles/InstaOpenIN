#import "InstaOpenINHeader.h"
#import <substrate.h>
#import "SVProgressHUD.h"

static float progress = 0.0f;

%hook IGFeedItemPhotoCell
- (void)layoutSubviews {
	UILongPressGestureRecognizer *longPressMenu = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(longPressSaveImage:)];
    [self addGestureRecognizer:longPressMenu];
    %orig;
}
%new
- (void)longPressSaveImage:(UILongPressGestureRecognizer*)gesture {
    if ( gesture.state == UIGestureRecognizerStateEnded ) {

    	progress = 0.0f;
    	[SVProgressHUD showProgress:0 status:@"Preparing Image"];
         NSURL *imageURL = self.post.imageURLForFullSizeImage;
         progress+=0.1f;
    	[SVProgressHUD showProgress:progress status:@"Preparing Image"];
         NSData *imageData = [NSData dataWithContentsOfURL:imageURL];
         progress+=0.4f;
    	[SVProgressHUD showProgress:progress status:@"Preparing Image"];
         UIImage *imageToSave = [UIImage imageWithData:imageData];
         progress+=0.6f;
    	[SVProgressHUD showProgress:progress status:@"Preparing Image"];
         NSData *pngData = UIImagePNGRepresentation(imageToSave);
         progress+=0.8f;
    	[SVProgressHUD showProgress:progress status:@"Preparing Image"];
         NSString *documentsPath = @"/var/mobile/Library/InstaOpenIN/"; //Get the docs directory 
		 NSString *filePath = [documentsPath stringByAppendingPathComponent:@"image.png"]; //Add the file name
		 [pngData writeToFile:filePath atomically:YES]; //Write the file
		 progress+=1.0f;
    	[SVProgressHUD showProgress:progress status:@"Preparing Image"];

         NSURL *URL = [NSURL fileURLWithPath:filePath];
		TTOpenInAppActivity *openInAppActivity = [[TTOpenInAppActivity alloc] initWithView:self andRect:self.frame];
		UIActivityViewController *activityViewController = [[UIActivityViewController alloc] initWithActivityItems:@[URL] applicationActivities:@[openInAppActivity]];
		[SVProgressHUD showSuccessWithStatus:@"Success!"];
		if(UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone){
		    // Store reference to superview (UIActionSheet) to allow dismissal
		    openInAppActivity.superViewController = activityViewController;
		    // Show UIActivityViewController
		    [[UIApplication sharedApplication].keyWindow.rootViewController presentViewController:activityViewController animated:YES completion:NULL];
		} else {
		    // Create pop up
		    activityPopoverController = [[UIPopoverController alloc] initWithContentViewController:activityViewController];
		    // Store reference to superview (UIPopoverController) to allow dismissal
		    openInAppActivity.superViewController = activityPopoverController;
		    // Show UIActivityViewController in popup
		    [activityPopoverController presentPopoverFromRect:self.frame inView:self permittedArrowDirections:UIPopoverArrowDirectionAny animated:YES];
		}

    }
}
%end

%hook IGFeedItemVideoCell
- (void)layoutSubviews {
	UILongPressGestureRecognizer *longPressMenu = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(longPressSaveVideo:)];
    [self addGestureRecognizer:longPressMenu];
    %orig;
}
%new
- (void)longPressSaveVideo:(UILongPressGestureRecognizer*)gesture {
    if ( gesture.state == UIGestureRecognizerStateEnded ) {
    	progress = 0.0f;
    	[SVProgressHUD showProgress:0 status:@"Preparing Video"];
    	NSInteger videoVersion = [%c(IGPost) videoVersionForCurrentNetworkConditions];
    	progress = 0.2f;
    	[SVProgressHUD showProgress:0 status:@"Preparing Video"];
        NSURL *videoURL = [self.post videoURLForVideoVersion:videoVersion];
        progress = 0.4f;
    	[SVProgressHUD showProgress:0 status:@"Preparing Video"];
        NSData *videoData = [NSData dataWithContentsOfURL:videoURL];
        progress = 0.6f;
    	[SVProgressHUD showProgress:0 status:@"Preparing Video"];
        NSString *documentsPath = @"/var/mobile/Library/InstaOpenIN/"; //Get the docs directory 
        progress = 0.8f;
    	[SVProgressHUD showProgress:0 status:@"Preparing Video"];
		NSString *filePath = [documentsPath stringByAppendingPathComponent:@"video.mp4"]; //Add the file name
		[videoData writeToFile:filePath atomically:YES]; //Write the file
		progress = 1.0f;
    	[SVProgressHUD showProgress:0 status:@"Preparing Video"];

        NSURL *URL = [NSURL fileURLWithPath:filePath];
		TTOpenInAppActivity *openInAppActivity = [[TTOpenInAppActivity alloc] initWithView:self andRect:self.frame];
		UIActivityViewController *activityViewController = [[UIActivityViewController alloc] initWithActivityItems:@[URL] applicationActivities:@[openInAppActivity]];
		[SVProgressHUD showSuccessWithStatus:@"Success!"];
		if(UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone){
		    // Store reference to superview (UIActionSheet) to allow dismissal
		    openInAppActivity.superViewController = activityViewController;
		    // Show UIActivityViewController
		    [[UIApplication sharedApplication].keyWindow.rootViewController presentViewController:activityViewController animated:YES completion:NULL];
		} else {
		    // Create pop up
		    activityPopoverController = [[UIPopoverController alloc] initWithContentViewController:activityViewController];
		    // Store reference to superview (UIPopoverController) to allow dismissal
		    openInAppActivity.superViewController = activityPopoverController;
		    // Show UIActivityViewController in popup
		    [activityPopoverController presentPopoverFromRect:self.frame inView:self permittedArrowDirections:UIPopoverArrowDirectionAny animated:YES];
		}

    }
}
%end