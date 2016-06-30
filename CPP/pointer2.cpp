#include <iostream>

using namespace std;


char acMyCharArray[12] = { 'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '\0' };
char * pcMyCharacterPointer = acMyCharArray;



int main()
{
	
	

	while (*pcMyCharacterPointer != '0')
	{
		cout << *pcMyCharacterPointer << endl;
		pcMyCharacterPointer++;
	}




	system("pause");
	return 0;

}