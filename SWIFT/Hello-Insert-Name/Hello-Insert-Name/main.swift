//
//  main.swift
//  Hello-Insert-Name
//
//  Created by Jamie Cropley on 30/06/2016.
//  Copyright © 2016 Jamie Cropley. All rights reserved.
//

import Foundation

func input() -> String {
    let keyboard = NSFileHandle.fileHandleWithStandardInput()
    let data = keyboard.availableData
    return NSString(data: data, encoding: NSUTF8StringEncoding) as! String
}

var enteredName: String

print("Please enter your name: ")
enteredName = input()
print("Hello " + enteredName)