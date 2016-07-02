//
//  main.swift
//  Count-Characters
//
//  Created by Jamie Cropley on 02/07/2016.
//  Copyright © 2016 Jamie Cropley. All rights reserved.
//

import Foundation

func input() -> String {
    let keyboard = NSFileHandle.fileHandleWithStandardInput()
    let data = keyboard.availableData
    return NSString(data: data, encoding: NSUTF8StringEncoding) as! String
}

var enteredName: String = ""



print("Please enter your name: ")
enteredName = input()
print("Hello " + enteredName)

var lgnth = enteredName.characters.count
print("Your name contains: \(lgnth) characters")


//I can not figure out why the below is not detecting no input / empty string?

if enteredName.isEmpty {
    print("You did not enter anything!")
}