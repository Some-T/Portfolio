#include <iostream>

using namespace std;


int main() 
{
	cout << "1|2|3|4|5|6|7|8|9|10|11|12|" << endl;
for (int c = 1; c < 13; c++)
{
	cout << c << "|";
	for (int i = 1; i < 13; i++)
	{
		cout << i * c << "|";
	}
	cout << endl;
	}
	system("pause");
	return 0;
}