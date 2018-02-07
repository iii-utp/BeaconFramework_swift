//
//  LBeaconDevice.h
//  libLBeaconKit
//
//  Created by Cynthia Chian on 2016/8/23.
//  Copyright © 2016年 Cynthia Chian. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @api {Class} LBeaconDevice
 * @apiVersion 0.1.0
 * @apiGroup LBeaconDevice
 *
 * @apiDescription
 * LBeaconDevice
 *
 * @apiParam {String} mac mac address  of Linc Beacon device
 * @apiParam {Int} battery battery level (%) of Linc Beacon device
 * @apiParam {Int} currentRssi current rssi  of Linc Beacon device
 *
 */
@interface LBeaconDevice : NSObject
@property(nonatomic, strong) NSString *mac;
@property(nonatomic, assign) int battery;
@property(nonatomic, assign) int currentRssi;
    
    
- (BOOL)isComplete;
@end
