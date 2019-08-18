## LollypopSDK Instruction

### Installation
Lollypop iOS SDK supports multiple methods for installing the library in a project.
#### Installation with CocoaPods
[CocoaPods](http://cocoapods.org) is a dependency manager for Objective-C, which automates and simplifies the process of using 3rd-party libraries like AFNetworking in your projects. See the ["Getting Started" guide for more information](https://github.com/AFNetworking/AFNetworking/wiki/Getting-Started-with-AFNetworking). You can install it with the following command:

```bash
$ gem install cocoapods
```

> CocoaPods 0.39.0+ is required to build AFNetworking 3.0.0+.

#### Podfile

To integrate Lollypop iOS SDK into your Xcode project using CocoaPods, specify it in your `Podfile`:

```ruby
source 'https://github.com/CocoaPods/Specs.git'
platform :ios, '8.0'

target 'TargetName' do
pod 'lollypop', '0.1.9'
end
```

Then, run the following command:

```bash
$ pod install
```
#### Installation manually

1. Add LollypopSDK.framework to your project.
2. Add required framework and library below:
	* **libsqlite3.tbd**
	* **Fundation.framework**
	* **CoreBluetooth.framework**
	* **SystemConfiguration.framework**
	* **MobileCoreServices.framework**
	* **CoreGraphices.framework**
	* **Security.framework**
	
No matter which method you are using, you need to add bluetooth privacy manually to info.plist.

### Usage
  **Init with appkey**
  ```Objective-c
  - (void)setAppKey:(NSString *)appKey;
```
 
 **Set delegate and implement it**
 ```Objective-c
  [LollypopSDK sharedInstance].delegate = self;
  
  - (void)lollypopDidReceiveTemperature:(LollypopTemperature *)temperature;

  - (void)lollypopDidReceiveHeightWeight:(LollypopHeightWeight *)hwData;
```
  **registher account for user**
  
  ```Objective-c
  - (void)registerWithPhoneNo:(NSString *)phoneNo password:(NSString *)password callback:(LollypopCallback)callback;
```
  **login account**
  
  ```Objective-c
  - (void)loginWithPhoneNo:(NSString *)phoneNo password:(NSString *)password callback:(LollypopCallback)callback;
```
**Connect device (need to login first)**
  ```Objective-c
  - (void)conntectDevice:(LollypopDeviceType)deviceType callback:(LollypopCallback)callback;
```
