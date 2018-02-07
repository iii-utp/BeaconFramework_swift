//
//  LBeaconConfig.h
//  libLBeaconKit
//
//  Created by Cynthia Chian on 2016/8/23.
//  Copyright © 2016年 Cynthia Chian. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LBeaconConfig : NSObject
@property(nonatomic, assign) int majorId;
@property(nonatomic, assign) int minorId;
@property(nonatomic, strong) NSString *uuid;
@property(nonatomic, assign) int rssi1m;
@property(nonatomic, assign) int advInterval;
@property(nonatomic, assign) BOOL privacyEnable;
@property(nonatomic, assign) BOOL secureEnable;
@property(nonatomic, assign) BOOL isLocked;
@property(nonatomic, strong) NSData *deviceUuid;
@property(nonatomic, assign) int mgmtAdvInterval;

- (void)reset;
@end
