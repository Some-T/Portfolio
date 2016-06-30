#include <iostream>
using namespace std;

int main()
{
	int i=1;
	cout<<"-----------------------------------------------------"<<endl;
	
	while(i<=12){
		if(i==1){cout<<"|"<<i<<" ";}
		if(i<10){cout<<"|"<<i<<"  ";}
		else{
		cout<<"|"<<i<<" "; }
		i++;
	}
	cout<<"|"<<endl;

	for(int x=1; x<=12;x++)
	{
		
		cout<<"-----------------------------------------------------"<<endl;
		if(x<10){cout<<"|"<<x<<"  ";}
		else{
			cout<<"|"<<x<<" ";}
		
		
		for(int y=1; y<=12; y++)
		{
			
            if(y*x<10)
			{
			cout<<"|"<<x*y<<"  ";
			}
			else if(y*x>=100)
			{
              cout<<"|"<<x*y;
			}
			else
			{
               cout<<"|"<<x*y<<" ";
			}
			

		}
		cout<<"|"<<endl;
		

	}
	cout<<"-----------------------------------------------------"<<endl;
	system("pause");
}
