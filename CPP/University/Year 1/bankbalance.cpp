//Created by Jamie Cropley.

#include <iostream>
#include <string>
#include <cstdlib>
 

using namespace std;


int main() {

    float withdraw;
    string currency = "£";
    float balance = 792.86;

    cout << "Your current balance is: " << currency <<  balance << endl;
    cout << "Enter the amount you would like to withdraw: ";
    cout << currency;
    cin >> withdraw;
    
    if (balance < withdraw) {
        cout << "INSUFFICENT FUNDS" << endl;
    } else {
        cout << "EJECTING CASH" << endl;
    }

    balance = balance - withdraw;

    cout << "Your new balance is: " << currency << balance << endl;

    
system("pause");
}