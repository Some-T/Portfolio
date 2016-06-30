#include <iostream>
#include <string> //library to to utilise a string throughout the program.

using namespace std;

int main() // the program itself is stored here.
{
	int iScore = 0; //the 'integer' variable is set to zero and named iScore

	char cIn; //is the initial string/character variable that is character based named cIn, not to be confused with the cin object.

	cout<<"Welcome to the are you a programmer program!"<<endl<<endl; //outputs strings via endl at the end of this line also as per below lines.
	cout<<"This program tests your suitability to be a programmer."<<endl<<endl;
	cout<<"The maximum score is 100."<<endl<<endl;
	cout<<"Your favourite food is:"<<endl;
	cout<<"A - Steamed vegetables."<<endl;
	cout<<"B - Pizza."<<endl;
	cout<<"C - Foie gras."<<endl;
	cout<<"D - Curry."<<endl;
	cout<<"Your answer: "; //This line does not have endl at the end so it is awaiting user input.

	cin >> cIn; //cin object Shifts right to cIn string

	if(cIn == 'b' || cIn == 'B') iScore = iScore + 20; //if variable cIn = b OR(||) B then variable iScore = + 25

	cout<<endl<<endl<<"Your favourite kind of light is:"<<endl;
	cout<<"A - Natural light."<<endl;
	cout<<"B - Energy efficent LED spotlights."<<endl;
	cout<<"C - The warm glow of an LED monitor."<<endl;
	cout<<"D - LED Torch"<<endl;
	cout<<"Your answer: ";

	cin >> cIn;

	if(cIn == 'c' || cIn == 'C') iScore = iScore + 20;

	cout<<endl<<endl<<"What is outfit is the most suitable workwear:"<<endl;
	cout<<"A - T-shirt and jeans."<<endl;
	cout<<"B - Suit and tie."<<endl;
	cout<<"C - Fancy dress costume."<<endl;
	cout<<"D - Nude"<<endl;
	cout<<"Your answer: ";

	cin >> cIn;

	if(cIn == 'a' || cIn == 'A') iScore = iScore + 20;

	cout<<endl<<endl<<"Your favourite browser is:"<<endl;
	cout<<"A - Safari."<<endl;
	cout<<"B - Internet explorer."<<endl;
	cout<<"C - None of the above."<<endl;
	cout<<"D - Chrome"<<endl;
	cout<<"Your answer: ";

	cin >> cIn;

	if(cIn == 'c' || cIn == 'C') iScore = iScore + 20; 

	cout <<endl<<endl<<"Your score was: "<<iScore<<endl<<endl; // at end of program output / print score.

	if (iScore == 100) //if score = 100 print the below
	{
		cout <<"Congratulations, you are destined to be a programmer!"<<endl;
	}

	else if (iScore >= 60) //else if score is greater than 60 print the below
	{
		cout <<"Congratulations, you have clear nerd tendencies!"<<endl;
	}

	else //else print the below messages
	{
		cout <<"Ooh, bad luck. Time for you to take nerd 101!"<<endl;
	}

	cout<<endl<<"Goodbye"<<endl; //at end of the program output / print the below

	system("pause");

	return 0;
}