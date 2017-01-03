### LollypopSDK 使用文档介绍

####如何引用LollypopSDK

在项目工程中添加LollypopSDK.framework的时候有以下几个注意点。

1. LollypopSDK的使用同时需要包含以下几个系统库:

	* **libsqlite3.tbd**
	* **Fundation.framework**
	* **CoreBluetooth.framework**
	* **SystemConfiguration.framework**
	* **MobileCoreServices.framework**
	* **CoreGraphices.framework**
	* **Security.framework**

2. 由于LollypopSDK中使用了Bluetooth模块，所以需要在App的Capabilities的Background Modes中勾选Use Bluetooth LE accessories。

3. 为了防止第三方库不能使用Category，需要在Build Settings中的Other Linker Flags里添加-ObjC

####LollypopSDK结构介绍

LollypopDeviceInfo包含了关于设备信息

 * **deviceId** 设备的UUID
 * **batteryLevel** 电量显示
 * **softwareVersion** 软件版本号
 * **hardwareVersion** 硬件版本号

LollypopTemperatureInfo包含了关于获取的体温信息

 * **temperature** 体温数值（举例：3676代表36.76摄氏度）
 * **timestamp** 测温的时间戳
 * **isAccurateResult** 是否是实测值（true代表实测，false代表预测）

LollypopSDK包含了一些SDK的操作方法

 * +(void)setApplicationId:(NSString *)applicationId;
 
    **注册AppKey给服务器**
 
 * +(void)registerWithPhoneNo:(NSString *)phoneNo
                     password:(NSString *)password
                     callback:(LollypopCallback)callback;
                     
  **注册用户信息，注册成功后会同时登录**
  
 * -(void)loginWithPhoneNo:(NSString *)phoneNo
                  password:(NSString *)password
                  callback:(LollypopCallback)callback;
   
   **登录用户**
   
 * -(BOOL)isLogin;
 
   **判断用户是否登录**
   
 * -(NSError *)logout;

   **注销用户**
   
 * -(void)conntectDeviceWithCallBack:(LollypopCallback)callback;
  
   **连接Device，需要先登录用户**
   
 * -(void)disconntectDeviceWithCallBack:(LollypopCallback)callback;
   
   **断开设备，需要先登录用户**
   
 * -(void)getDeviceInfoWithCallBack:(LollypopDeviceInfoNotifier)callback;
   
   **获取设备信息，需要先登录用户**
   
 * -(void)getTemperatureWithTemperatureNotifier:(LollypopTemperatureNotifier)temperatureNotifier
                                       callback:(LollypopCallback)callback;
                                       
   **监听设备温度，需要先登录用户**  
   
   
   
####备注

**操作流程 ： 登录／注册 -> 连接设备 -> 注册测温监听／获取设备信息 -> 测量温度 -> 收到温度 -> 断开设备 -> 退出登录**

**AppKey : gqqmgtHBgapew6ke**

**cn.lollypop.err.ble Error**

1. ScanTimeoutFailed = 1
2. ConnectTimeoutFailed = 2
3. DisconnectTimeoutFailed = 3
4. CharacteristicNotFound = 4
5. BluetoothNotReady = 5
6. OperationInProgress = 6
7. BLENotSupported = 7
8. DeviceNotBinded = 8
9. UnknownError = 9
