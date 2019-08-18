// Copyright (c) 2018, Bongmi
// All rights reserved
// Author: renchonghui@bongmi.com

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LollypopUserInfo : NSObject

@property (nonatomic, strong, readonly) NSNumber *userId;

@property (nonatomic, strong, readonly) NSString *phoneNo;

@property (nonatomic, strong, readonly) NSString *passwordMD5;

- (instancetype)initWithUserId:(NSNumber *)userId phoneNo:(NSString *)phoneNo passwordMD5:(NSString *)passwordMD5;

@end

NS_ASSUME_NONNULL_END
