//Created by Jamie Cropley.

#include <iostream> //I/O stream library.
#include <string> //Main library that is relevant to this code in order to manipulate the strings.


using namespace std;


int main() {

	string sMainString; //The main variable that holds the user entered string throughout the program.
	//The three below variables increment each time, each relevant while loop is run as per below.
	int iPuncCount = 0;
	int iHyphen = 0;
	int iLineBreak = 0;

	static bool sbOnceIntro = true; //This variable uses boolean as a switch to display an intro message once to the user.
	//The below code utilises the above variable to display an introduction message to the user.
	if (sbOnceIntro == true)
	{
		cout << "This program will clean up your entered text so that it removes the majority of punctuation (,.;:!`'\"?), changes hyphens (-) into spaces and spaces into line breaks." << endl;
		sbOnceIntro = false;
	}

	/*The first line of code below outputs text asking the user for a string based user input,
	the second line of code assigns this user inputted string to the variable sMainString,
	I used 'getline' rather than 'cin >>' because it basically allows spaces to be read that are inputted by the user
	therefore the whole string on such line.*/
	cout << endl << "Type the text below that you would like to clean up, then press the ENTER key: " << endl << endl;
	getline(cin, sMainString);

	//The below line outputs the inputted sentence.
	cout << endl << "Your sentence is: " << sMainString << endl;

	/*Whilst the user inputted sMainString variable contains the punctuation of ,.;:!`'\"?
	the while loop will keep running, finding and deleting them from the string.*/
	while (sMainString.find_first_of(",.;:!`'\"?") != string::npos) {
		size_t sPunctuation = sMainString.find_first_of(",.;:!`'\"?");
		sMainString.erase(sPunctuation, 1);
		iPuncCount++;
		/*The above line of code increments upon each run of the while loop therefore counting how much punctuation
		is in the sMainString variable.*/
	}
	//The below line shows the inputted sentence without punctuation marks.
	cout << endl << "Your sentence without punctuation marks: " << sMainString << endl;

	/*Whilst the user inputted sMainString variable contains an hyphen('s) which looks like a dash -
	the while loop will keep running, finding and replacing the hyphen('s) in the string with a space.*/
	while (sMainString.find_first_of("-") != string::npos) {
		size_t sHyphen = sMainString.find_first_of("-");
		sMainString.replace(sHyphen, 1, " ");
		iHyphen++;
		/*The above line of code increments upon each run of the while loop therefore counting how many hyphen('s)
		is in the sMainString variable.*/
	}
	//The below line shows the inputted sentence without hyphens and punctuation marks.
	cout << endl << "Your sentence without punctuation marks and hyphens: " << sMainString << endl;

	/*Whilst the user inputted sMainString variable contains a space the while loop will keep running,
	finding and replacing the space('s) in the string with a line break.*/
	while (sMainString.find_first_of(" ") != string::npos) {
		size_t sLineBreak = sMainString.find_first_of(" ");
		sMainString.replace(sLineBreak, 1, "\n");
		iLineBreak++;
		/*The above line of code increments upon each run of the while loop therefore counting how many space('s)
		which are now line breaks are in the sMainString variable.*/
	}
	/*The below line of code outputs the overall result with punctuation removed, hyphens changed to spaces
	and spaces changed to line breaks.*/
	cout << endl << "With line breaks added the words in this sentence are: " << endl << endl << sMainString << endl << endl << endl;

	//The below line just indicates the initiation of the below if statements:
	cout << "Below is a summary of the actions completed above: " << endl;

	//The below code outputs to the user the amount of occurrences of punctuation that were in the entered string of text.
	if (iPuncCount >= 0)
	{
		cout << endl << "- Removed " << iPuncCount << " occurrences of punctuation." << endl;
	}
	//The below code outputs to the user the amount of occurrences of hyphen('s) that were in the entered string of text.
	if (iHyphen >= 0)
	{
		cout << endl << "- Removed " << iHyphen << " occurrences of hyphen('s)." << endl;
	}
	//The below code outputs to the user the amount of occurrences of line break('s) that were in the entered string of text.
	if (iLineBreak >= 0)
	{
		cout << endl << "- Added " << iLineBreak << " Line Break('s)." << endl;
	}

	/*The below if statement checks if the user has entered any text, using the empty member function,
	if they have not it outputs an error message and restarts the program.*/
	if (sMainString.empty())
	{
		cout << endl << endl << "You did not enter any text!" << endl << endl;
		main();
	}

	cout << endl << endl;
	//The two below lines of code initiate the end of the program.
	system("pause");
	return 0;

}