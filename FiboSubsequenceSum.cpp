#include <iostream>

using namespace std;


int main()
{
    int n;
    cin>>n;
    int a1=1, a2=1, sum=n, tmp;
    int t[1000];
    int licz=0;
    for(int i=0; a1<n; i++)
    {
        t[i]=a1;
        a2=a2+a1;
        a1=a2-a1;
        licz++;
    }
    for(int i=0; i<licz-1; i++)
    {   tmp=0;
        int j=i;
        for(j; tmp<n; j++)
        {
          tmp+=t[j]; cout<<t[j]<<" ";
        }
        if(i==0) sum=tmp;
        if(sum>tmp) sum=tmp;

    }
    cout<<sum;

}
