//
//  ViewController.swift
//  BeaconFramework_demo
//
//  Created by ccHsieh on 2018/2/6.
//  Copyright © 2018年 cchsieh. All rights reserved.
//

import UIKit
import BeaconFramework

class MainTableViewController: UIViewController, IIIBeaconDetectionDelegate {
    var tableView:UITableView!
    
    // Beacon var
    var notification = BeaconFramework.IIINotification()
    var detection = IIIBeaconDetection()
    var iiibeacon = IIIBeacon()

    //Data
    var beaconList:[BeaconData] = []
    var messageList: [Message] = []
        
    override func viewDidLoad() {
        super.viewDidLoad()
        beaconInit()
        createTableView()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func createTableView(){
        tableView = UITableView(frame: CGRect(x: 0, y: 20, width: view.frame.width, height: self.view.frame.height - 20))
        tableView.register(UITableViewCell.self, forCellReuseIdentifier: "cell")
        tableView.tableFooterView = UIView(frame:CGRect.zero)
        tableView.separatorStyle = .singleLine
        tableView.delegate = self
        tableView.dataSource = self
        self.view.addSubview(tableView)
    }
    
    func beaconInit(){
        iiibeacon.get_beacons_withkey_security(server: "ideas.iiibeacon.net", key: "app key", completion: { (beacon_info: IIIBeacon.BeaconInfo, Sucess: Bool) in
            if(Sucess){
                print("beacon; \(beacon_info)")
                
                DispatchQueue.main.async(execute: {
                    self.detection = IIIBeaconDetection(beacon_data: beacon_info)
                    self.detection.delegate  = self
                    self.detection.Start()
                })
            }
        })
    }
    
    func BeaconDetectd() {
        if (detection.ActiveBeaconList?.count)! > 0 {  //有偵測到beacon
            for item in detection.ActiveBeaconList! {
                if self.insertData(item: item) == true{ //取得Beacon對應推播內容
                    notification.get_push_message_security(
                        security_server:"ideas.iiibeacon.net",
                                  major: Int(item.major!)!,
                                  minor: Int(item.minor!)!,
                                    key: "app key" ){ (completion,success)  -> () in
                        if(success){
                            //建立推播內容物件
                            let value = Message()
                            value.message = completion
                            value.uuid = item.id
                            self.messageList.append(value)
                        }
                    }
                }
            }
        }
    }
    
    func insertData(item:ActiveBeacon) -> Bool{
        if beaconList.contains(where: {$0.id == item.id!}) == false{ // 無重複
            let data = BeaconData(id: item.id, major: item.major, minor: item.minor)
            beaconList.append(data)
            self.tableView.reloadData()
            return true
        }
        return false
    }
    
}

extension MainTableViewController: UITableViewDelegate, UITableViewDataSource{
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return beaconList.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell{
        
        let cell:UITableViewCell = UITableViewCell(style: UITableViewCellStyle.default, reuseIdentifier: "cell")
        let beaconLabel = cell.textLabel
        beaconLabel?.text = "id: \(beaconList[indexPath.row].id!)  ,Major: \(beaconList[indexPath.row].major!) ,Minor: \(beaconList[indexPath.row].minor!)"
        beaconLabel?.textColor = UIColor.brown
        
        return cell;
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: false)
        print("\(messageList[indexPath.row].message?.content.products[0].sellerName)")
        print("\(messageList[indexPath.row].message?.content.products[0].photoUrl)")
        print("\(messageList[indexPath.row].message?.content.products[0].originPrice)")
    }
    
    func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        return "BEACON列表"
    }
    
    func tableView(_ tableView: UITableView, heightForHeaderInSection section: Int) -> CGFloat {
        return 50
    }
    
}

