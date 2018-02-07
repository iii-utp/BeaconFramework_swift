//
//  BeaconData.swift
//  BeaconFramework_demo
//
//  Created by ccHsieh on 2018/2/6.
//  Copyright © 2018年 cchsieh. All rights reserved.
//

import Foundation
import BeaconFramework

class Message {
    var message: message?
    var uuid: String?
}

class BeaconData: NSObject {
    
    var id:String?
    var major:String?
    var minor:String?
    
    init(id:String?, major:String?, minor:String?) {
        super.init()
        self.id = id
        self.major = major
        self.minor = minor
    }
}
