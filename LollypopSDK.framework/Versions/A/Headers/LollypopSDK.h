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

@property (nonatomic, weak) id<LollypopSDKDelegate> delegate;

+ (instancetype)sharedInstance;

- (void)setAppKey:(NSString *)appKey;

- (void)registerWithPhoneNo:(NSString *)phoneNo password:(NSString *)password callback:(LollypopCallback)callback;

- (void)loginWithPhoneNo:(NSString *)phoneNo password:(NSString *)password callback:(LollypopCallback)callback;

- (NSError *)logout;

- (BOOL)isLogin;

- (void)conntectDevice:(LollypopDeviceType)deviceType callback:(LollypopCallback)callback;

- (BOOL)isConnected:(LollypopDeviceType)deviceType;

- (void)disconnectDevice:(LollypopDeviceType)deviceType;

- (LollypopDeviceInfo *)deviceInfoForDeviceType:(LollypopDeviceType)deviceType;

- (void)beep;

@end

NS_ASSUME_NONNULL_END
