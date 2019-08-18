// Copyright (c) 2019, Bongmi
// All rights reserved
// Author: renchonghui@bongmi.com

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LollypopHeightWeight : NSObject

@property (nonatomic, strong, readonly) NSDate *timestamp;
@property (nonatomic, assign, readonly) NSInteger heightValue;
@property (nonatomic, assign, readonly) NSInteger weightValue;

- (instancetype)initWithTimestamp:(NSDate *)timestamp height:(NSInteger)heightValue weight:(NSInteger)weightValue;

@end

NS_ASSUME_NONNULL_END
