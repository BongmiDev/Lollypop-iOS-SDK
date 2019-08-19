// Copyright (c) 2018, Bongmi
// All rights reserved
// Author: renchonghui@bongmi.com

#import <Foundation/Foundation.h>

#import "LollypopTemperature.h"
#import "LollypopHeightWeight.h"
#import "LollypopDeviceInfo.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^LollypopCallback)(id _Nullable result, NSError *_Nullable error);

typedef NS_ENUM(NSInteger, BMDBDeviceType);

@protocol LollypopSDKDelegate <NSObject>

@optional

- (void)lollypopDidReceiveTemperature:(LollypopTemperature *)temperature;

- (void)lollypopDidReceiveHeightWeight:(LollypopHeightWeight *)hwData;

@end

@interface LollypopSDK : NSObject


/**
 lollypop SDK delegate, data like temperature, height, weight will be notify via this delegate.
 */
@property (nonatomic, weak) id<LollypopSDKDelegate> delegate;

+ (instancetype)sharedInstance;


/**
 Init SDK with appkey, make sure call it before any other lollypop api.

 @param appKey appKey for your App, ask provider if you don't have one.
 */
- (void)setAppKey:(NSString *)appKey;


/**
 Register lollypop account, every device must use as an lollypop user.

 @param phoneNo phone number
 @param password password
 @param callback callback
 */
- (void)registerWithPhoneNo:(NSString *)phoneNo password:(NSString *)password callback:(LollypopCallback)callback;


/**
 Login as lollypop account.

 @param phoneNo registered phone number
 @param password password
 @param callback callback
 */
- (void)loginWithPhoneNo:(NSString *)phoneNo password:(NSString *)password callback:(LollypopCallback)callback;


/**
 Logout lollypop account

 @return return nil if success, otherwise an error will return.
 */
- (NSError *)logout;


/**
 Check if has login lollypop account.

 @return return YES if has login
 */
- (BOOL)isLogin;


/**
 Connect lollypop bluetooth device, currently you can only connect one type of device at the same time, but multiple devices with different device type.

 @param deviceType the device type you want to connect, refer LollypopDeviceType definition for support device type
 @param callback connection callback
 */
- (void)conntectDevice:(LollypopDeviceType)deviceType callback:(LollypopCallback)callback;


/**
 Check if has connected device.

 @param deviceType the device type you want to check
 @return return YES if it has connected
 */
- (BOOL)isConnected:(LollypopDeviceType)deviceType;


/**
 Disconnect device

 @param deviceType the device type you want to disconnect
 */
- (void)disconnectDevice:(LollypopDeviceType)deviceType;


/**
 Get device information for the device type you want to check

 @param deviceType the device type
 @return return LollypopDeviceInfo object which represnet for device informations.
 */
- (LollypopDeviceInfo *)deviceInfoForDeviceType:(LollypopDeviceType)deviceType;


/**
 Make a beep sound for debugging purpose. For example, to check if it has connected to specific device. Note that not all of device type support this feature.
 */
- (void)beep;

@end

NS_ASSUME_NONNULL_END
