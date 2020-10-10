// Copyright (c) 2019, Bongmi
// All rights reserved
// Author: renchonghui@bongmi.com

#import "BMViewController.h"

#import <LollypopSDK/LollypopSDK.h>

@interface BMViewController () <LollypopSDKDelegate>

@property (weak, nonatomic) IBOutlet UIButton *connectButton;
@property (weak, nonatomic) IBOutlet UIButton *beepButton;
@property (weak, nonatomic) IBOutlet UILabel *deviceLabel;
@property (weak, nonatomic) IBOutlet UILabel *logLabel;

@property (nonatomic, strong) LollypopDeviceInfo *deviceInfo;
@property (nonatomic, assign) LollypopDeviceType deviceType;

@end

@implementation BMViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  self.deviceType = kLollypopDeviceTypeFemometer;
  [[LollypopSDK sharedInstance] setAppKey:@"KKunpAnyEUJzNeEG"];
  [LollypopSDK sharedInstance].delegate = self;
  [[LollypopSDK sharedInstance] loginWithPhoneNo:@"18267136773" password:@"111111bm" callback:^(id  _Nullable result, NSError * _Nullable error) {
    NSLog(@"login with result:%@, error: %@", result, error);
  }];
}

#pragma mark - Events

- (IBAction)onConnectButtonTapped:(id)sender {
  if ([[LollypopSDK sharedInstance] isConnected:self.deviceType]) {
    [self disconnect];
  } else {
    [self connect];
  }
}

- (IBAction)onBeepButtonTapped:(id)sender {
  [self makeBeep];
}

#pragma mark - UI

- (void)refreshUIWithDeviceInfo {
  if (self.deviceInfo) {
    self.deviceLabel.text = self.deviceInfo.description;
  } else {
    self.deviceLabel.text = nil;
  }
}

- (void)updateButtonState {
  if ([[LollypopSDK sharedInstance] isConnected:self.deviceType]) {
    [self.connectButton setTitle:@"Disconnect" forState:UIControlStateNormal];
    self.beepButton.enabled = YES;
  } else {
    [self.connectButton setTitle:@"Connect" forState:UIControlStateNormal];
    self.beepButton.enabled = NO;
  }
}

#pragma mark - Device

- (void)connect {
  self.connectButton.enabled = NO;
  self.logLabel.text = @"Connecting...";
  [[LollypopSDK sharedInstance] conntectDevice:self.deviceType
                                      callback:^(id _Nullable result, NSError *_Nullable error) {
                                        if (!error) {
                                          self.deviceInfo = result;
                                          [self refreshUIWithDeviceInfo];
                                          [self updateButtonState];
                                          self.logLabel.text = @"Connect success.";
                                        } else {
                                          self.logLabel.text = [NSString stringWithFormat:@"Connect failed with error:%@.", error];
                                        }
                                        self.connectButton.enabled = YES;
                                      }];
}

- (void)disconnect {
  self.connectButton.enabled = NO;
  self.logLabel.text = @"Disconnect...";
  [[LollypopSDK sharedInstance] disconnectDevice:self.deviceType];
  dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
    self.deviceInfo = nil;
    self.connectButton.enabled = YES;
    self.logLabel.text = @"Disconnect success.";
    [self updateButtonState];
    [self refreshUIWithDeviceInfo];
  });
}

- (void)makeBeep {
  [[LollypopSDK sharedInstance] beep];
}

#pragma mark - LollypopSDKDelegate

- (void)lollypopDidReceiveTemperature:(LollypopTemperature *)temperature {
  dispatch_async(dispatch_get_main_queue(), ^{
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"yyyMMddHHmmss"];
    NSString *timeStr = [formatter stringFromDate:temperature.timestamp];
    self.logLabel.text = [NSString stringWithFormat:@"Received temperature: %ld on %@.", (long)temperature.temperature, timeStr];
  });
}

- (void)lollypopDidReceiveHeightWeight:(LollypopHeightWeight *)hwData {
  dispatch_async(dispatch_get_main_queue(), ^{
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"yyyMMddHHmmss"];
    NSString *timeStr = [formatter stringFromDate:hwData.timestamp];
    self.logLabel.text = [NSString stringWithFormat:@"Received height:%ld weight: %ld on %@.", (long)hwData.heightValue,
                          (long)hwData.weightValue, timeStr];
  });
}

@end
