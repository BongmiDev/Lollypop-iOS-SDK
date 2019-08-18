/**
 * Copyright (c) 2016, Bongmi
 * All rights reserved
 * Author: wuyike@bongmi.com
 */

#import <Foundation/Foundation.h>

extern NSString *const kLollypopSDKErrorDomain;

typedef NS_ENUM(NSInteger, LollypopSDKErrorCode) {
  kLollypopSDKErrorCodeScanTimeoutFailed = 1,
  kLollypopSDKErrorCodeConnectTimeoutFailed = 2,
  kLollypopSDKErrorCodeDisconnectTimeoutFailed = 3,
  kLollypopSDKErrorCodeCharacteristicNotFound = 4,
  kLollypopSDKErrorCodeBluetoothNotReady = 5,
  kLollypopSDKErrorCodeOperationInProgress = 6,
  kLollypopSDKErrorCodeBLENotSupported = 7,
  kLollypopSDKErrorCodeNoTemperature = 9,
  kLollypopSDKErrorCodeOTAVersionNotSupport = 10,
  kLollypopSDKErrorCodeOperationTimeout = 11,
  kLollypopSDKErrorCodeNotLogin = 12,
  kLollypopSDKErrorCodeAlreadyLogin = 13,
  kLollypopSDKErrorCodeOther
};
