#include <iostream>

using namespace std;

int main()
{   int spacja=20;
    for(int i=1; i<=40; i+=2)
    {
       for(int j=spacja; j>=0; j--)
       {
           cout<<" ";
       }

       spacja--;
       for(int j=i; j>0; j--)
       {
           cout<<"*";
       }
       if(i==21) cout<<"      <- christmas tree";
       cout<<endl;
    }
    for(int i=6; i>=0; i--)
    {
        for(int j=20; j>0; j--)
        {
            cout<<" ";
        }
        for(int i=3; i>0; i--)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
