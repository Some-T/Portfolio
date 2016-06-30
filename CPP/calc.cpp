#include<iostream> //Library used throughout this program.

using namespace std;  //Global namespace std.

int iMenu; //Variable for the purpose of menu selection.
float iNum1; //First variable for use in the calculation as per selected menu option, note that it is float so that it avoids divide by zero errors.
float iNum2; //Second variable for use in the calculation as per selected menu option, note that it is float so that it avoids divide by zero errors.
char cExit = 'n'; //Character value to not exit the program upon menu option 5 being selected, 'n' makes it easy to understand that it is for no.


//The below is each function for each menu option and its relevant coden therein.

void Menu1()
{
	cout << "Please enter first number: ";
	cin >> iNum1;
	cout << "Please enter second number: ";
	cin >> iNum2;
	cout << iNum1 << " + " << iNum2 << " = " << iNum1 + iNum2 << endl << endl;
}

void Menu2()
{
	cout << "Please enter first number: ";
	cin >> iNum1;
	cout << "Please enter second number: ";
	cin >> iNum2;
	cout << iNum1 << " - " << iNum2 << " = " << iNum1 - iNum2 << endl << endl;
}

void Menu3()
{
	cout << "Please enter first number: ";
	cin >> iNum1;
	cout << "Please enter second number: ";
	cin >> iNum2;
	cout << iNum1 << " * " << iNum2 << " = " << iNum1 * iNum2 << endl << endl;
}

void Menu4()
{
	cout << "Please enter first number: ";
	cin >> iNum1;
	cout << "Please enter second number: ";
	cin >> iNum2;
	cout << iNum1 << " / " << iNum2 << " = " << iNum1 / iNum2 << endl << endl;
}

void Menu5()
{
	cout << "Are you sure you want to exit the program? [Y/N] ";
	cin >> cExit;
}


void vExit() { //Defined function here so that if the user does not exit it goes back to the beginning of the program


			   //All of the below 5 lines are to output a string based menu for selection, this is then selected on the 6th line and assigned to variable iMenu therein.
	cout << "1.) Add two numbers together" << endl << endl;
	cout << "2.) Subtract one number from another" << endl << endl;
	cout << "3.) Multiply two numbers together" << endl << endl;
	cout << "4.) Divide one number by another" << endl << endl;
	cout << "5.) Exit program" << endl << endl;
	cout << "Please select option 1,2,3,4 or 5 then press the enter key: ";
	cin >> iMenu;


	//The below is the switch statement that is relative to what menu option is selected, so if 1 is selected it begins the addition of two numbers sub program.
	switch (iMenu)
	{
	case 1:
		Menu1();
		break;
	case 2:
		Menu2();
		break;
	case 3:
		Menu3();
		break;
	case 4:
		Menu4();
		break;
		/*This final option allows the user to input whether they want to exit the program, if they input any single one character
		the program will start from the beginning, but 'n' was used as a easy reference to the word no,  else if 'y' or 'Y' is
		inputted it assigns to variable cExit and if it detects the y or Y character is in that variable the program terminates and closes down.*/
	case 5:
		Menu5();
		break;
	}
	if (cExit != 'Y' && cExit != 'y') vExit();
}


//This is the main part of the program to initiate the void function (or my program as above) and exit when necessary based on user input.
int main()
{
	vExit();

	return 0;

}