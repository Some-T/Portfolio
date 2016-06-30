#include <iostream>

using namespace std ;

int main()
{
/* int iCounter		// Declare our variable
iCounter = 1;		// Initialise our variable
while(iCounter < 11) 	// Test our condition
{
	cout << iCounter << endl; //Write to the screen
	iCounter = iCounter + 1;  // Increment the counter
}

system("pause");*/

char iInput;			// Declare our variable
cout << "Enter a letter: ";	// Write to screen
cin >> iInput;			// Get input
do
{
	cout << "Enter a letter: ";	// Write to screen
	cin >> iInput;			// Get input
}
while (iInput != 'x');			// Test out condition

cout << "You entered x, goodbye	." << endl;	//Next statement

system("pause");

return 0;
}