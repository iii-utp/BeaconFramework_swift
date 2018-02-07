//
//  LBeacon.h
//  libLBeaconKit
//
//  Created by Cynthia Chian on 2016/8/22.
//  Copyright © 2016年 Cynthia Chian. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @api {Class} LBeaconConfig
 * @apiVersion 0.1.0
 * @apiGroup LBeaconConfig
 *
 * @apiDescription
 * LBeaconConfig beacon configuration
 *
 * @apiParam {Int} major id
 * @apiParam {Int} minor id
 * @apiParam {Array} uuid uuid array of UInt8, length = 16
 * @apiParam {Int} rssi1m rssi
 * @apiParam {Int} advInterval advertising interval
 * @apiParam {Bool} privacyEnable if privacy control enable
 * @apiParam {Bool} secureEnable if secure control enable
 *
 */


typedef enum LBeaconConfigAction: int {
    LBeaconConfigActionNone = 0,
    LBeaconConfigActionSetUUID,
    LBeaconConfigActionSetMajorId,
    LBeaconConfigActionSetMinorId,
    LBeaconConfigActionSetRSSI1M = 4,
    LBeaconConfigActionSetAdvInterval,
    LBeaconConfigActionGetUUID,
    LBeaconConfigActionGetMajorId,
    LBeaconConfigActionGetMinorId,
    LBeaconConfigActionGetRSSI1M,
    LBeaconConfigActionGetAdvInterval,
    LBeaconConfigActionGetPrivacyControl,
    LBeaconConfigActionSetPrivacyControl,
    LBeaconConfigActionGetLockState,
    LBeaconConfigActionSetLockState,
    LBeaconConfigActionGetMgmtAdvInterval,
    LBeaconConfigActionSetMgmtAdvInterval,
    LBeaconConfigActionCount
} LBeaconConfigAction;

@class LBeaconConfig;
@class LBeaconDevice;
@class ManagerDelegate;
@protocol  LBeaconReadyDelegate;
@protocol  LBeaconConfigDelegate;
@protocol  LBeaconControlDelegate;
/**
 * @api {Class} LBeacon
 * @apiVersion 0.1.0
 * @apiGroup LBeacon
 *
 * @apiDescription
 * LBeacon constructor
 *
 * @apiParam {Dictionary} devices found device dictionary of <String:LBeaconDevice>
 * @apiParam {LBeaconConfig} beaconConfig beacon configuration of current Linc Beacon device
 * @apiParam {LBeaconReadyDelegate} lbeaconReadyDelegate callback of LBeaconReadyDelegate
 * @apiParam {LBeaconConfigDelegate} lbeaconConfigDelegate callback of LBeaconConfigDelegate
 * @apiParam {LBeaconControlDelegate} lbeaconControlDelegate callback of LBeaconControlDelegate
 *
 */
@interface LBeacon : NSObject

@property(nonatomic, strong) NSMutableDictionary<NSString *, LBeaconDevice *> *devices;
@property(nonatomic, strong) LBeaconConfig *beaconConfig;

@property(nonatomic, strong) ManagerDelegate *peripheralDelegate;
@property(nonatomic, weak) id<LBeaconReadyDelegate>lbeaconReadyDelegate;
@property(nonatomic, weak) id<LBeaconConfigDelegate>lbeaconConfigDelegate;
@property(nonatomic, weak) id<LBeaconControlDelegate>lbeaconControlDelegate;


- (void)getBeaconMajorId;
- (void)getBeaconMinorId;
- (void)getBeaconUUID;
- (void)getBeaconAdvInterval;
- (void)getBeaconRSSI1M;
- (void)getPrivacyControl;
- (void)getSecureControl;
- (void)getManagementAdvInterval;
- (void)setBeaconMajorId:(int) value;
- (void)setBeaconMinorId:(int) value;
- (void)setBeaconRSSI1M:(int) value;
- (void)setBeaconAdvInterval:(int) value;
- (void)setBeaconUUID:(NSString *) value;
- (void)setPrivacyControl:(BOOL) value;
- (void)setSecureControl:(BOOL) value;
- (void)setManagementAdvInterval:(int) value;
@end

/**
 * @api {Protocol} LBeaconReadyDelegate
 * @apiVersion 0.1.0
 * @apiGroup LBeaconReadyDelegate
 *
 * @apiDescription
 * user needs to adopt the protocol for linc beacon device connected callback
 *
 * @apiExample {curl} Define
 * class Example: LBeaconReadyDelegate { }
 *
 */
@protocol LBeaconReadyDelegate
/**
 * @api {Method} deviceReady deviceReady
 * @apiVersion 0.1.0
 * @apiGroup LBeaconReadyDelegate
 *
 * @apiDescription
 * function for user implementation when Linc beacon device ready
 *
 * @apiExample {curl} Define
 * func deviceReady() {
 * }
 *
 */
- (void)deviceReady;

@end

/**
 * @api {Protocol} LBeaconConfigDelegate
 * @apiVersion 0.1.0
 * @apiGroup LBeaconConfigDelegate
 *
 * @apiDescription
 * user needs to adopt the protocol for linc beacon device config callback
 *
 * @apiExample {curl} Define
 * class Example: LBeaconConfigDelegate { }
 *
 */
@protocol LBeaconConfigDelegate
/**
 * @api {Method} getBeaconConfigDone getBeaconConfigDone
 * @apiVersion 0.1.0
 * @apiGroup LBeaconConfigDelegate
 *
 * @apiDescription
 * function for user implementation when get config of Linc beacon device done
 *
 * @apiExample {curl} Define
 * func getBeaconConfigDone(action: LBeaconConfigAction, error: NSError?) {
 * }
 *
 * @apiParam {LBeaconConfigAction} action action of beacon config
 * @apiParam {NSError} error if an error occurred, the cause of the failure
 *
 */
- (void)getBeaconConfigDone:(LBeaconConfigAction)action error:(NSError *)error;
/**
 * @api {Method} setBeaconConfigDone setBeaconConfigDone
 * @apiVersion 0.1.0
 * @apiGroup LBeaconConfigDelegate
 *
 * @apiDescription
 * function for user implementation when set config of Linc beacon device done
 *
 * @apiExample {curl} Define
 * func setBeaconConfigDone(action: LBeaconConfigAction, error: NSError?) {
 * }
 *
 * @apiParam {LBeaconConfigAction} action action of beacon config
 * @apiParam {NSError} error if an error occurred, the cause of the failure
 *
 */
- (void)setBeaconConfigDone:(LBeaconConfigAction)action error:(NSError *)error;

@end

/**
 * @api {Protocol} LBeaconControlDelegate
 * @apiVersion 0.1.0
 * @apiGroup LBeaconControlDelegate
 *
 * @apiDescription
 * user needs to adopt the protocol for linc beacon device control callback
 *
 * @apiExample {curl} Define
 * class Example: LBeaconControlDelegate { }
 *
 */
@protocol LBeaconControlDelegate
/**
 * @api {Method} privacyControlSupported privacyControlSupported
 * @apiVersion 0.1.0
 * @apiGroup LBeaconControlDelegate
 *
 * @apiDescription
 * function for user implementation when Linc beacon device support privacy control
 *
 * @apiExample {curl} Define
 * func privacyControlSupported() {
 * }
 *
 */
- (void)privacyControlSupported;
/**
 * @api {Method} getPrivacyControlDone getPrivacyControlDone
 * @apiVersion 0.1.0
 * @apiGroup LBeaconControlDelegate
 *
 * @apiDescription
 * function for user implementation when get privacy control for Linc beacon device done
 *
 * @apiExample {curl} Define
 * func getPrivacyControlDone(action: LBeaconConfigAction, error: NSError?) {
 * }
 *
 * @apiParam {LBeaconConfigAction} action action of beacon config
 * @apiParam {NSError} error if an error occurred, the cause of the failure
 *
 */
- (void)getPrivacyControlDone:(LBeaconConfigAction)action error:(NSError *)error;
/**
 * @api {Method} setPrivacyControlDone setPrivacyControlDone
 * @apiVersion 0.1.0
 * @apiGroup LBeaconControlDelegate
 *
 * @apiDescription
 * function for user implementation when set privacy control for Linc beacon device done
 *
 * @apiExample {curl} Define
 * func setPrivacyControlDone(action: LBeaconConfigAction, error: NSError?) {
 * }
 *
 * @apiParam {LBeaconConfigAction} action action of beacon config
 * @apiParam {NSError} error if an error occurred, the cause of the failure
 *
 */
- (void)setPrivacyControlDone:(LBeaconConfigAction)action error:(NSError *)error;
/**
 * @api {Method} getSecureControlDone getSecureControlDone
 * @apiVersion 0.1.0
 * @apiGroup LBeaconControlDelegate
 *
 * @apiDescription
 * function for user implementation when get secure control for Linc beacon device done
 *
 * @apiExample {curl} Define
 * func getSecureControlDone(action: LBeaconConfigAction, error: NSError?) {
 * }
 *
 * @apiParam {LBeaconConfigAction} action action of beacon config
 * @apiParam {NSError} error if an error occurred, the cause of the failure
 *
 */
- (void)getSecureControlDone:(LBeaconConfigAction)action error:(NSError *)error;
/**
 * @api {Method} setSecureControlDone setSecureControlDone
 * @apiVersion 0.1.0
 * @apiGroup LBeaconControlDelegate
 *
 * @apiDescription
 * function for user implementation when set secure control for Linc beacon device done
 *
 * @apiExample {curl} Define
 * func setSecureControlDone(action: LBeaconConfigAction, error: NSError?) {
 * }
 *
 * @apiParam {LBeaconConfigAction} action action of beacon config
 * @apiParam {NSError} error if an error occurred, the cause of the failure
 *
 */
- (void)setSecureControlDone:(LBeaconConfigAction)action error:(NSError *)error;

@end