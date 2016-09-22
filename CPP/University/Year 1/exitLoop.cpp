#include <iostream>
#include <cstdlib> //temp for g++ compiler

using namespace std;


int main() {
    bool exitBool = false;
    
    exitBool = false;
    char exitQ = 'N';
    

    while (exitBool == false) {
        cout << "THE GAME/PROGRAM IS RUNNING!" << endl;
        cout << "Would you like to exit the program? [Y/N]" << endl;
        cin >> exitQ;
        if (exitQ == char('Y') || exitQ == char('y')) {
            exitBool = true;
        } else {
            exitBool = false;

        }         
    }
    system("pause");
    return 0;
}