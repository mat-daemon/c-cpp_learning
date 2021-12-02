#include <iostream>
#include <cmath>
using namespace std;


void upper(int length, int width, int center1, int center2x, int center2y, int r)
{
    for(int y=0; y<length-4; y++)
    {
        for(int x=0; x<width; x++)
        {
            double dist1 = sqrt(pow(x-center1, 2) + pow(y-center1, 2));
            double dist2 = sqrt(pow(x-center2x, 2) + pow(y-center2y, 2));

            if(dist1 <= r || dist2 <= r) cout<<"?";
            else cout<<" ";
        }
        cout<<endl;
    }
}

void text()
{
    char text[23];
    int i = 0;
    for(i=0; i<3; i++) cout<<" ";
    for(i=0; i<7; i++) cout<<"?";
    for(i=0; i<23; i++) cout<<  "?";//text[i];
    for(i=0; i<5; i++) cout<<"?";
    cout<<endl;
}

void down(int space)
{
    int amount = 33;
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<space; j++) cout<<" ";
        for(int j=0; j<amount; j++) cout<<"?";
        space+=2;
        amount-=4;
        cout<<endl;
    }
}

int main()
{
    int center1 = 10;
    int center2x = 30;
    int center2y = 10;
    int width = 40;
    int length = 10;
    int r = 10;
    int space = 4;

    upper(length, width, center1, center2x, center2y, r);
    text();
    down(space);

    return 0;
}

