//
//  main.swift
//  Count-Characters//
//  Created by Jamie Cropley on 02/07/2016.
//  Copyright © 2016 Jamie Cropley. All rights reserved.
//

import Foundation

extension String {
    var isBlank: Bool {
        if self.isEmpty { return true }
        
        return stringByTrimmingCharactersInSet(.whitespaceCharacterSet()) == ""
    }
}

print("Please enter your name: ")

let input = readLine(stripNewline: true) ?? ""
switch input.isBlank {
case true:
    print("You did not enter anything")
default:
    print(input)
    print("Your name contains: \(input.characters.count) characters")
}