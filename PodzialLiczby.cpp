#include <iostream>

using namespace std;

void divider(int tab[],int wsk, int rest, int maks)
    {
        if(rest==0 && wsk==wsk)                               //tutaj ustawiasz na ile liczb
        {   if(wsk!=1) cout<<tab[1];
            for(int i=2; i<=wsk; i++)
            {
                cout<<"+"<<tab[i];
            }
            cout<<endl;
        }

        if(rest!=0)
        {
            wsk++;
            for(int i=min(rest,maks); i>=1; i--)
            {
                tab[wsk]=i;
                divider(tab, wsk, rest-i, i);
            }
        }
    }
void Divider(int n)
{
    int tab[n+1];

    divider(tab, 0, n, n);
}
int main()
{
    int n;
    cin>>n;
    Divider(n);
}
