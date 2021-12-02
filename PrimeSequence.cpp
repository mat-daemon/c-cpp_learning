#include <iostream>
#include <math.h>
using namespace std;

int tab[5][5]={6, 8, 2, 4, 9, 10, 5, 11, 17, 23, 67, 45, 23, 1, 89, 56, 24, 66, 56, 22, 7, 99, 24, 88, 46};
const int n=5;
bool czypierwsza(int x)
{   if( x==1 ) return false;
    for(int i=2; i<=sqrt(x); i++)
    {
        if(x%i==0) return false;
    }
    return true;
}

int ciagaryt(int tab[n][n])
{   int r;

    for(int i=0; i<n; i++)
    {

        int licz=1;

        for(int j=0; j<n-1; j++)
        {

            if(czypierwsza(tab[i][j]) && czypierwsza(tab[i][j+1]))
            {   cout<<tab[i][j]<<" ";
                if(licz>=2)
                {
                    if((tab[i][j+1]-tab[i][j])==r)
                    {
                        licz++;
                    }
                    else
                    {
                        if(licz>2) return licz;
                        if(licz==2) licz=1;
                    }
                }
                else
                {
                    r=tab[i][j+1]-tab[i][j];
                    licz++;

                }
            }

        }
        if(licz>2) return licz;
        else licz=1;
    }
}
int main()
{
    cout<<ciagaryt(tab);
}
