//Libraries relevant to this code are on the two lines below.
#include <iostream>

//Global namespace std.
using namespace std ;
 
 //Int main() contains the entirety of the program code inbetween { }
int main()
{

bool a=true;
bool b=false;
bool c=true;

bool result1 = a && !b;
bool result2 = a || b;
bool result3 = b && (a || c);
bool result4 = !a || (b != c);

cout<<result1<<endl;
cout<<result2<<endl;
cout<<result3<<endl;
cout<<result4<<endl;

bool d = 3; 
bool e = 5;
bool f = 7;

bool result5 = d > e;
bool result6 = d == e;
bool result7 = d < e && e < f;
bool result8 = d > e;
bool result9 = d > b;



cout<<result5<<endl;
cout<<result6<<endl;
cout<<result7<<endl;
cout<<result8<<endl;
cout<<result9<<endl;




system("pause");

return 0;
}