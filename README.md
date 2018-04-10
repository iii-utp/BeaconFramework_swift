# iOS Beacon Notification SDK
III Beacon Detect and Notification Information

## Installation
Import the BeaconFramework.framework file

#### Step1:
Add the BeaconFramework.framework file to Xcode project

![image](https://github.com/iii-utp/BeaconFramework_ios/raw/master/BeaconFramework_demo/Image/image1.png)

#### Step2:
Add the BeaconFramework.framework to Embedded Binaries

![image](https://github.com/iii-utp/BeaconFramework_ios/raw/master/BeaconFramework_demo/Image/image2.png)

#### Step3:
Open Info.plist, and add the following lines to ask privacy usage.

##### iOS 9 App Transport Security issue
Apple made a radical decision with iOS 9, disabling all unsecured HTTP traffic from iOS apps..
Here’s how to disable this issue. 

    <key>NSAppTransportSecurity</key>
        <dict>
            <key>NSAllowsArbitraryLoads</key>
	    <true/>
	    </dict>

##### Specifies the reason for your app to access the user’s location information while your app is in use.
    
    <key>NSLocationWhenInUseUsageDescription</key>
	  <string>Beacon Detect Usage</string>
    
    <key>NSLocationAlwaysAndWhenInUseUsageDescription</key>
	  <string>Beacon Detect Usage</string>
    
or you can add to your Info.plist directly.

![image](https://github.com/iii-utp/BeaconFramework_ios/raw/master/BeaconFramework_demo/Image/image4.png)

#### Objective-c project may enable swift code.

![image](https://github.com/iii-utp/BeaconFramework_ios/raw/master/BeaconFramework_demo/Image/image3.png)


## Usage
### Swift
#### Step1:
import BeaconFramework, and inheritance IIIBeaconDetectionDelegate.

```swift
import BeaconFramework
class MainTableViewController: UIViewController, IIIBeaconDetectionDelegate {

}
```

#### Stpes2:
Declare beacon detection and notification variables.

```swift
var notification = BeaconFramework.IIINotification()
var detection = IIIBeaconDetection()
var iiibeacon = IIIBeacon()
```
 
#### Step3:
Initialize beaconFramework and connect to server.

```swift
iiibeacon.get_beacons_withkey_security(server: "ideas.iiibeacon.net", key: "app key", completion: { (beacon_info: IIIBeacon.BeaconInfo, Sucess: Bool) in
            if(Sucess){                
                DispatchQueue.main.async(execute: {
                    self.detection = IIIBeaconDetection(beacon_data: beacon_info)
                    self.detection.delegate  = self
                    self.detection.Start()
                })
            }
})
```

#### Step4:
Write a program in BeaconDetectd()

```swift
if (detection.ActiveBeaconList?.count)! > 0 {   //if detect more than a beacon
            for item in detection.ActiveBeaconList! {
                    notification.get_push_message_security( //get push message from beacons
                        security_server:"ideas.iiibeacon.net",
                                  major: Int(item.major!)!,
                                  minor: Int(item.minor!)!,
                                    key: "app key" ){ (completion,success)  -> () in
                        if(success){
                            //Create push message struct...
                        }
                   }
              }
  }
```

### Objective-c

#### Step1:
import BeaconFramework, declare beacon detection and notification variables in .h file, then add IIIBeaconDetectionDelegate in .m file


```objc
// .h
#import <BeaconFramework/BeaconFramework.h>

@property (nonatomic, strong) IIINotification *notification;
@property (nonatomic, strong) IIIBeacon *iiibeacon;
@property (nonatomic, strong) IIIBeaconDetection *detection;

// .m
@interface AppDelegate ()<IIIBeaconDetectionDelegate>
@end
```

#### Step2:
Initialize beaconFramework, variables and connect to server.

```objc
_notification = [IIINotification new] ;
_iiibeacon = [IIIBeacon new];
_detection = [IIIBeaconDetection new];

[_iiibeacon get_beacons_withkey_securityWithServer:@"ideas.iiibeacon.net" key: @"app key" completion: ^(BeaconInfo *item , BOOL Sucess) {
        if (Sucess) {
            dispatch_async(dispatch_get_main_queue(), ^{
                _detection = [[IIIBeaconDetection alloc] initWithBeacon_data:item];
                _detection.delegate = self;
                [_detection Start];
            });
        }
    }
];
```

#### Step3:
Write a program in BeaconDetectd()

```objc
-(void)BeaconDetectd{
    if (_detection.ActiveBeaconList.count > 0) {
        for (ActiveBeacon* key in [self.detection ActiveBeaconList]) {
                [_notification get_push_message_securityWithSecurity_server:@"ideas.iiibeacon.net" major: key.major.integerValue minor:key.minor.integerValue key:@"app key" completion:^(message *item, BOOL Sucess){
                    if (Sucess) {
                        // Create push message struct...
                        NSLog(@"%@", [item.content.products[0] sellerName]);
                    }
                }];
            }
        }
}
```


## Requirements
- Xcode 8 or higher
- iOS 8.0 or higher

## Demo
#### Swift
##### Support ios11.0 and higher
- BeaconFramework_swift project

  Build and run the BeaconFramework_swift.xcodeproj in Xcode

#### Object-C:
- BeaconFramework_objc project

  Build and run the BeaconFramework_objc.xcodeproj in Xcode

## Notice
#### Error: linker command failed with exit code 1 (use -v to see invocation)
Go to your project -> Build Settings -> Enable Bitcode -> No

## License
BeaconFramework_demo is available under the Apache v2 License.

Copyright © 2018 cchsieh III.
