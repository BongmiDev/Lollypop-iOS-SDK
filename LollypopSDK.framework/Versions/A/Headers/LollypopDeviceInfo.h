// Copyright (c) 2019, Bongmi
// All rights reserved
// Author: renchonghui@bongmi.com

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, LollypopDeviceType) {
  kLollypopDeviceTypeUnknow = 0,
  kLollypopDeviceTypeFemometer = 1,
  kLollypopDeviceTypeEarmo = 2,
  kLollypopDeviceTypeGrowp = 3
};

@interface LollypopDeviceInfo : NSObject

@property (nonatomic, copy, readonly) NSString *UUIDString;
@property (nonatomic, assign, readonly) NSUInteger batteryLevel;
@property (nonatomic, copy, readonly) NSString *softwareVersion;
@property (nonatomic, copy, readonly) NSString *hardwareVersion;
@property (nonatomic, copy, readonly) NSString *serialNumber;
@property (nonatomic, assign, readonly) NSUInteger voltage;
@property (nonatomic, assign, readonly) LollypopDeviceType deviceType;

- (instancetype)initWithUUIDString:(NSString *)UUIDString
                        deviceType:(LollypopDeviceType)deviceType
                      batteryLevel:(NSUInteger)batteryLevel
                   softwareVersion:(NSString *)softwareVersion
                   hardwareVersion:(NSString *)hardwareVersion
                      serialNumber:(NSString *)serialNumber
                           voltage:(NSUInteger)voltage;

@end

NS_ASSUME_NONNULL_END
