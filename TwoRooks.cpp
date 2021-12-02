#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
const int N=5;
int t[N][N];

void generator(int t[][N])
{
    srand(time(NULL));
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            t[i][j]=rand()%10;
        }
    }
}
struct struktura
    {
      int w1, w2;
      int k1, k2;
    };

int t1[N], t2[N];
struktura dwiewieze(struktura &wieza)
{
    t1[N], t2[N];
    for(int i=0; i<N; i++)
    {   int sum1=0, sum2=0;
        for(int j=0; j<N; j++)
        {
            sum1+=t[i][j];
            sum2+=t[j][i];
        }
        t1[i]=sum1;  //wiersze
        t2[i]=sum2;  //kolumny
    }
    int sum1=0, sum2=0;
    wieza.w1=0; wieza.k1=0; wieza.w2=0; wieza.k2=0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            int sum=t1[i]+t2[j]-2*t[i][j];
            if(sum>sum1)
            {
                sum1=sum;
                wieza.w1=i; wieza.k1=j;
            }
        }
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            int sum=t1[i]+t2[j]-2*t[i][j];
            if(sum>sum2&(i!=wieza.w1&j!=wieza.k1))
            {
                sum2=sum;
                wieza.w2=i; wieza.k2=j;
            }
        }
    }
    return wieza;
}

int main()
{
    struktura wieza;
    generator(t);
    dwiewieze(wieza);
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<t[i][j]<<" ";
        }
        cout<<" suma: "<<t1[i];
        cout<<endl;
    }
    for(int i=0; i<N; i++) cout<<t2[i]<<" ";
    cout<<endl;
    cout<<wieza.w1<<" "<<wieza.k1<<endl<<wieza.w2<<" "<<wieza.k2;
}
