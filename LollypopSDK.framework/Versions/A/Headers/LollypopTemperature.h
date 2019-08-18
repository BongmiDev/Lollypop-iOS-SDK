// Copyright (c) 2019, Bongmi
// All rights reserved
// Author: renchonghui@bongmi.com

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LollypopTemperature : NSObject

@property (nonatomic, assign, readonly) NSInteger temperature;
@property (nonatomic, strong, readonly) NSDate *timestamp;
@property (nonatomic, assign, readonly) BOOL isAccurateResult;

- (instancetype)initWithTemperature:(NSInteger)temperature
                          timestamp:(NSDate *)timestamp
                   isAccurateResult:(BOOL)isAccurateResult;

@end

NS_ASSUME_NONNULL_END
