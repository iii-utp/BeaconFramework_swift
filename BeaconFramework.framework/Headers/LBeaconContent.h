//
//  LBeaconContent.h
//  libLBeaconKit
//
//  Created by Cynthia Chian on 2016/8/23.
//  Copyright © 2016年 Cynthia Chian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface LBeaconContent : NSObject
@property(nonatomic, strong) NSString *uuid;
@property(nonatomic, assign) int major;
@property(nonatomic, assign) int minor;
@property(nonatomic, assign) NSInteger rssi;
@property(nonatomic, assign) double accuracy;
@property(nonatomic, assign) CLProximity proximity;
- (id)initWithUuid:(NSString *)uuid major:(int)major minor:(int)minor;
- (id)initWithUuid:(NSString *)uuid major:(int)major minor:(int)minor rssi:(NSInteger)rssi accuracy:(double)accuracy proximity:(CLProximity)proximity;
@end
