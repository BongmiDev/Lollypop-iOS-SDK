Pod::Spec.new do |s|
  s.name = "LollypopSDK"
  s.version = "0.1.9"
  s.summary = "A short description of LollypopSDK."
  s.license = {"type"=>"Commercial", :text => "Copyright (C) 2019 Bongmi, Inc. All rights reserved."}
  s.authors = {"Aren"=>"renchonghui@bongmi.com"}
  s.homepage = "https://github.com/BongmiDev/Lollypop-iOS-SDK"
  s.description = "lollypop sdk for iOS"
  s.source = { :http => "https://dl.bongmi.com/lollypopsdk/ios/LollypopSDK-0.1.9.zip" }

  s.frameworks = 'SystemConfiguration','CoreBluetooth','MobileCoreServices','CoreTelephony'
  s.library = 'libsqlite3'
  s.ios.deployment_target    = '8.0'
  s.ios.vendored_framework   = 'LollypopSDK.framework'
end
