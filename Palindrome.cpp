#include <iostream>

using namespace std;


const int N=15;
int tabq[N]={1, 2, 7, 9, 7, 6};
int tab[N]={1, 2, 7, 5, 9, 5, 3, 3, 5, 9, 5, 7, 9, 7, 6};
int palindrom(int t[], int n)
{
    int pomoc[n];
    int licz=0;
    for(int i=0; i<n; i++)
    {
        for(int k=0; k<n; k++) pomoc[k]=0;


        int dl=0;
        for(int j=i; j<n&t[j]%2==1; j++)
        {
            pomoc[dl]=t[j];
            dl++;
        }
        for(int j=0; j<(dl-2)/2; j++)
        {
            if(pomoc[j]!=pomoc[dl-1-j])
            {
                j=0;
                dl--;
            }
            if(dl==0) break;
        }
        if(licz<dl&dl>1) licz=dl;

    }
    return licz;
}

int main()
{
    cout<<palindrom(tab, N);
    return 0;
}
