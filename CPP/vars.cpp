//Libraries used throughout program.
#include <iostream>
#include <string>
//#include <cstdlib>

//Make names from std visible without std
using namespace std; 

//int main contains the program that is to be run.
int main()
{
//The below 7 lines are variables that 'declare' each different data type (integer,short,float,double,char,bool,string) of the memory block as an integer type variable.
	int iNumBytesInt = sizeof(int);
	int iNumBytesShort = sizeof(short);
	int iNumBytesFloat = sizeof(float);
	int iNumBytesDouble = sizeof(double);
	int iNumBytesChar = sizeof(char);
	int iNumBytesBool = sizeof(bool);
	int iNumBytesString = sizeof(string);


/* The below 7 lines out put the above 7 lines which are variables and there relevant data type of the memory block therein, 
additionally it adds a string in front of each variable out to indicate what it is out putting, overall in format : output + string based description of output + Variable */
	cout << "Size of Integer block: "<< iNumBytesInt << endl;
	cout << "Size of Short block: "<< iNumBytesShort << endl;
	cout << "Size of float block: "<< iNumBytesFloat << endl;
	cout << "Size of Double block: "<< iNumBytesDouble << endl;
	cout << "Size of Char block: "<< iNumBytesChar << endl;
	cout << "Size of Bool block: "<< iNumBytesBool << endl;
	cout << "Size of String block: "<< iNumBytesString << endl;

//The below code ensures the program does not exit automatically.
	system("pause");

	return 0;
}