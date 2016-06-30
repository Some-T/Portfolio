//Libraries relevant to this code are on the two lines below.
#include <iostream>
#include <cmath>

//Global namespace std.
using namespace std;

//Int main() contains the entirety of the program code inbetween { }
int main()
{
	/*Initiation of the variables for this program, all as float data type to allow for decimals, first
	Num1 to Num6 are almost like an array or sequence of numbers but it is not an array they are user defined variables to allow for easier calculation, 
	Mean is the variable used to store the calculated Mean value of the of the user defined Num1 to 6 and the same for StdDev variable.*/

	float Num1;
	float Num2;
	float Num3;
	float Num4;
	float Num5;
	float Num6;
	float Mean;
	float StdDev;

	/*All of the below that begins with cout prompts the user for a number input then adds two blank lines using endl, 
	then it adds such input to variables Num1 to Num6 via cin. */

	cout << "Please enter the first number of the sequence: " << endl << endl;
	cin >> Num1;

	cout << endl << endl << "Please enter the second number of the sequence: " << endl << endl;
	cin >> Num2;

	cout << endl << endl << "Please enter the third number of the sequence: " << endl << endl;
	cin >> Num3;

	cout << endl << endl << "Please enter the fourth number of the sequence: " << endl << endl;
	cin >> Num4;

	cout << endl << endl << "Please enter the fifth number of the sequence: " << endl << endl;
	cin >> Num5;

	cout << endl << endl << "Please enter the sixth number of the sequence: " << endl << endl;
	cin >> Num6;

	/*The below line here adds all the user defined variables together then divides by the elements, in total six to calculate the mean or average 
	overall defining the Mean variable.*/
	
	Mean = (Num1 + Num2 + Num3 + Num4 + Num5 + Num6) / 6;
	
	//The mean or average is then outputted to the user as per the below line.

	cout << endl << endl << "The Mean of the above sequence is: " << Mean << endl << endl;

	/*The below two lines define the variable StdDev through the calculation of standard deviation, it does this by taking
	each user input of Num1 to Num6 and subtracting the Mean variable and then squaring it to the power of 2 using the pow function from the cmath library,
	then overall it calculates the square root also using the sqrt function from the cmath library, and based on n-1 in the formula on the question document this divides by 5 
	based on bessels correction statistically speaking (starting from zero). */

	StdDev = sqrt((pow(Num1 - Mean, 2) + pow(Num2 - Mean, 2) + pow(Num3 - Mean, 2) +
			 pow(Num4 - Mean, 2) + pow(Num5 - Mean, 2) + pow(Num6 - Mean, 2)) / 5);

	//Overall in the below line it then prints out the StdDev which is the overall standard deviation calculation.

	cout << endl << endl << "The Standard Deviation of the above sequence is: " << StdDev << endl << endl;

	//The below stops the program from exiting automatically.

	system("pause");

	return 0;

}