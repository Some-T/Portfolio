#include <iostream>

using namespace std;

int doubleNumber(int iNumber)
{
	return iNumber + iNumber;


}




float doubleNumber(float iNumber)
{
	return iNumber + iNumber;
}

int main()
{


	int iNumber = doubleNumber(4);
	float fNumber = doubleNumber(4.3f);


	system("pause");
	return 0;

}





