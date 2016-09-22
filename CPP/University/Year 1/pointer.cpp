#include <iostream>

using namespace std;


char * pcMyCharacterPointer = "Hello World";



int main()
{


	while (*pcMyCharacterPointer != '\0')
	{
		cout << *pcMyCharacterPointer << endl;
		pcMyCharacterPointer++;
	}



	system("pause");
	return 0;

}