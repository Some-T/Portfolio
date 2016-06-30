#include<iostream> 

using namespace std; 

//Question 2

void printBoard()
{
	for(int i =1; i<=8; i++)
	{
		if(i%2){cout<<"";}
		else{cout<<" ";}

		for(int j =1; j<=8; j++)
		{
			if(j%2){cout<<"*";}
			else{cout<<" ";}

		}

		cout<<endl;

	}

}
// Question 3

void printBoard2(int x, int y)
{
	for (int i =1; i<=8; i++)
	{
		for (int j =1; j<=8; j++)
		{

			if(i%2){
				if(j%2){
					if(i==y && j==x){cout<<"X";}
					else{cout<<"*";}}

				else{if(i==y && j==x){cout<<"X";}
				else{cout<<" ";}}
			}
			else{

				if(j%2){
					if(i==y && j==x){cout<<"X";}
					else{ cout<<" ";}}

				else{if(i==y && j==x){cout<<"X";}
				else{cout<<"*";}}}
		}

		cout<<endl;
	}
}
void main()
{
	int x,y;
	printBoard();
	cout<<endl<<endl<<endl;
	cout<<"Please enter the value of X: ";
	cin>>x;
	cout<<"Please enter the value of Y: ";
	cin>>y;
	printBoard2(x,y);
	cout<<endl<<"A capital x character is shown at position ("<<x<<", "<<y<<")"<<endl;
	system("pause");
}