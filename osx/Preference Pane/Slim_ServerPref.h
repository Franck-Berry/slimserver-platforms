//
//  Slim_ServerPref.h
//  Slim Server
//
//  Created by Dave Nanian on Wed Oct 16 2002.
//  Copyright (c) 2002-2003 Slim Devices, Inc. All rights reserved.
//

#import <PreferencePanes/PreferencePanes.h>

#define SLIMLocalizedPrefString(key, comment) [[NSBundle bundleForClass:[self class]] localizedStringForKey:(key) value:@"" table:nil]

#define kSLIMNoAutomaticStartup 0
#define kSLIMStartupAtLogin 1
#define kSLIMStartupAtBoot 2

@interface Slim_ServerPref : NSPreferencePane 
{
    bool serverState;

    IBOutlet NSButton *toggleServerButton;
    IBOutlet NSTextField *serverStateDescription;
    IBOutlet NSImageView *serverStateImage;
    IBOutlet NSButton *webLaunchButton;
    IBOutlet NSButton *aboutButton;

    IBOutlet NSWindow *aboutBox;

    IBOutlet NSPopUpButton *startupType;

    AuthorizationRef myAuthorizationRef;
}

-(void)mainViewDidLoad;

-(bool)serverState;
-(void)setServerState:(bool)newState;
-(bool)changeAutoStartupFrom:(int)oldState to:(int)newState;

-(int)serverPID;
-(void)updateUI;

-(IBAction)openWebInterface:(id)sender;
-(IBAction)aboutSlimServer:(id)sender;
-(IBAction)dismissAboutBox:(id)sender;
-(IBAction)toggleServer:(id)sender;

-(IBAction)changeStartupPreference:(id)sender;
@end