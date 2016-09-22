#include <iostream>
#include <fstream>
#include <string>

using namespace std;
 
enum State { CROSS, CIRCLE, NONE };
 
State board[3][3];
 
int main() {
	// initialise the board
	for(int column = 0; column < 3; ++column)
	{
		for(int row = 0; row < 3; ++row)
		{
			board[row][column] = NONE;
		}
	}
 
	//set some values
	board[0][0] = CIRCLE;
	board[1][1] = CIRCLE;
	board[2][2] = CIRCLE;
	board[0][1] = CROSS;
	board[1][0] = CROSS;


	string circle = "O";
	string ex = "X";
	string hyphen = "-";
 
ofstream file_out("output.txt");

	//print the board
	for(int column = 0; column < 3; ++column)
	{
		for(int row = 0; row < 3; ++row)
		{
			State value = board[row][column];
			if(value == NONE)
			    file_out << "-";
			else if(value == CIRCLE)
				file_out << "O";
			else if(value == CROSS)
				file_out << "X";
		}
		//a row is over, so we can make a new line
		file_out <<"\n";

	}
	return 0;
}