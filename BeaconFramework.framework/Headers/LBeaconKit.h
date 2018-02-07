//
//  LBeaconKit.h
//  libLBeaconKit
//
//  Created by Cynthia Chian on 2016/8/19.
//  Copyright © 2016年 Cynthia Chian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@class LBeacon;
@protocol LBeaconScanDelegate;

/**
 * @api {Class} LBeaconKit
 * @apiVersion 0.1.0
 * @apiGroup LBeaconKit
 *
 * @apiDescription
 * LBeaconKit constructor
 *
 * @apiParam {LBeacon} lbeacon Linc Beacon object for configuration
 * @apiParam {Array} uuids array of CBUUID to scan for
 * @apiParam {Bool} centralManagerScanOptionAllowDuplicatesKey if the scan should run without duplicate filtering
 * @apiParam {LBeaconScanDelegate} lbeaconScanDelegate callback of LBeaconScanDelegate
 *
 */
@interface LBeaconKit: NSObject

@property(nonatomic, weak) id<LBeaconScanDelegate> lbeaconScanDelegate;
@property(nonatomic, strong) LBeacon *lbeacon;
@property(nonatomic, strong) NSArray<CBUUID *> *uuids;
@property(nonatomic, assign) BOOL centralManagerScanOptionAllowDuplicatesKey;

- (id)initWithDelegate:(id<LBeaconScanDelegate>)delegate;
- (void)startScan;
- (void)stopScan;
- (void)connectDevice:(NSString *)mac;
- (void)disconnectDevice;

@end

/**
 * @api {Protocol} LBeaconScanDelegate
 * @apiVersion 0.1.0
 * @apiGroup LBeaconScanDelegate
 *
 * @apiDescription
 * user needs to adopt the protocol for linc beacon device found callback
 *
 * @apiExample {curl} Example
 * class Example: LBeaconScanDelegate { }
 *
 */
@protocol LBeaconScanDelegate <NSObject>

/**
 * @api {Method} lbeaconDeviceFound lbeaconDeviceFound
 * @apiVersion 0.1.0
 * @apiGroup LBeaconScanDelegate
 *
 * @apiDescription
 * function for user implementation when Linc beacon device found
 *
 * @apiExample {curl} Define
 * func lbeaconDeviceFound() {
 * }
 *
 */
- (void)lbeaconDeviceFound;
@end