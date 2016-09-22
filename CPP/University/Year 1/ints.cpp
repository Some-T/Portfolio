#include <iostream>

using namespace std;

int max(int i1, int i2)
{
	if (i1 > i2)
	{
		return i1;
	}
	else
	{
		return i2;
	}
}


int max(int i1, int i2, int i3)

{
	if (i1 > i2)
	{
		return max(i1, i3);
	}
	else
	{
		return max(i2, i3);
	}
}


int main()
{


	int i1 = max(3, 5);
	int i2 = max(5, 2, 8);



	system("pause");
	return 0;

}