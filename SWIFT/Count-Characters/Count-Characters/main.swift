//
//  main.swift
//  Count-Characters//
//  Created by Jamie Cropley on 02/07/2016.
//  Copyright © 2016 Jamie Cropley. All rights reserved.
//

import Foundation

var enteredName: String = "";
var lgnth:Int = 0;



print("Please enter your name: ")

if let enteredName = readLine() {
    print("Hello " + enteredName)
    lgnth = enteredName.characters.count;
    print("Your name contains: \(lgnth) characters")
}

if lgnth <= 0{
    print("You did not enter anything!")
}