//
//  LBeaconMonitor.h
//  libLBeaconKit
//
//  Created by Cynthia Chian on 2016/8/18.
//  Copyright © 2016年 Cynthia Chian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

typedef enum MonitorPrivacyMode: int {
    MonitorPrivacyModePlainText = 0,
    MonitorPrivacyModePrivacy = 1,
    MonitorPrivacyModeMixed = 2,
    MonitorPrivacyModeCount
} MonitorPrivacyMode;

@protocol LBeaconMonitorDelegate;
@class LBeaconContent;
/**
 * @api {Class} LBeaconMonitor
 * @apiVersion 0.1.0
 * @apiGroup LBeaconMonitor
 *
 * @apiDescription
 * LBeaconMonitor constructor
 *
 * @apiParam {LBeaconMonitorDelegate} lbeaconMonitorDelegate callback of LBeaconMonitorDelegate
 *
 */
@interface LBeaconMonitor: NSObject
@property(nonatomic, weak) id<LBeaconMonitorDelegate> lbeaconMonitorDelegate;
- (void)setLbeaconMonitorDelegate:(id<LBeaconMonitorDelegate>) delegate;

- (void)startMonitor:(NSUUID *)uuid privacyMode:(MonitorPrivacyMode)privacyMode;
- (void)stopMonitor:(NSUUID *)uuid;
@end


/**
 * @api {Protocol} LBeaconMonitorDelegate
 * @apiVersion 0.1.0
 * @apiGroup LBeaconMonitorDelegate
 *
 * @apiDescription
 * user needs to adopt the protocol for linc beacon ranged callback
 *
 * @apiExample {curl} Example
 * class Example: LBeaconMonitorDelegate { }
 *
 */
@protocol LBeaconMonitorDelegate

/**
 * @api {Method} lbeaconBeaconsRanged lbeaconBeaconsRanged
 * @apiVersion 0.1.0
 * @apiGroup LBeaconMonitorDelegate
 *
 * @apiDescription
 * function for user implementation when LincBeacon is ranged
 *
 * @apiExample {curl} Define
 * func lbeaconBeaconsRanged(beacons: [(String, Int, Int)]) {
 * }
 *
 * @apiExample {curl} Example
 * func lbeaconBeaconsRanged(beacons: [(String, Int, Int)]) {
 *     for (uuid, major, minor) in beacons {
 *         NSLog("Beacon Ranged: (\(uuid), \(major), \(minor))")
 * }
 *
 * @apiParam {Array} beacons array of tuple (UUID, major id, minor id)
 *
 */
/**
 * @api {Method} lbeaconBeaconsRanged lbeaconBeaconsRanged
 * @apiVersion 0.1.3
 * @apiGroup LBeaconMonitorDelegate
 *
 * @apiDescription
 * function for user implementation when LincBeacon is ranged
 *
 * @apiExample {curl} Define
 * func lbeaconBeaconsRanged(beacons: NSArray) {
 * }
 *
 * @apiExample {curl} Example
 * func lbeaconBeaconsRanged(beacons: NSArray) {
 *     for beacon in beacons {
 *         let beaconContent = beacon as! LBeaconContent
 *         NSLog("Beacon Ranged: (\(beaconContent.uuid), \(beaconContent.major), \(beaconContent.minor))")
 * }
 *
 * @apiParam {Array} beacons array of LBeaconContent
 *
 */
- (void)lbeaconBeaconsRanged:(NSMutableArray *)beacons;
@end

