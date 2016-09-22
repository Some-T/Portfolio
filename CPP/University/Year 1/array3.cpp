#include <iostream>
#include <cstdlib> 


using namespace std;


int main() {
    int iArray[13][13];
    int input = 0;
    
    while(true)
    {
        cout<<"Please enter number: ";
        cin>>input;
        
        if(input > 12 || input < 0) {
            cout << "Outside limits" << endl;
            break;
        }
        
        
        for (int j=1; j<= 12; j++)
        {
            iArray[input][j]=input*j;
            cout<<iArray[input][j]<<" ";
        }
        cout<<endl;
        
        
    }
    
    system("pause");
    return 0;
}