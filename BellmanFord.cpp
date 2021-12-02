#include <iostream>
#include <list>
#include <limits.h>

using namespace std;

typedef struct edge
{
    int b;
    int wage;
}edge;

void Relax(int j, edge it, int* d)
{
    if(d[j] != INT_MAX && d[it.b] > d[j] + it.wage)
    {
        d[it.b] = d[j] + it.wage;
    }
}

bool Bellman_Ford( list<edge> *G, int N, int* d)
{
    for(int i=1; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            for(list<edge>::iterator it = G[j].begin(); it != G[j].end(); it++)
            {
                Relax(j,*it,d);
            }
        }
    }

    for(int i=0; i<N; i++)
        {
            for(list<edge>::iterator it = G[i].begin(); it != G[i].end(); it++)
            {
                if( d[i] != INT_MAX && d[it->b] > (d[i] + it->wage)) return false;
            }
        }

    return true;
}

int main()
{
    int N,K,p,k,a,b,s;
    cin>>N>>K;
    cin>>p>>k;

    list<edge> *G;
    G = new list<edge>[N];

    int *d = new int[N];
    for(int i=0; i<N; i++) d[i] = INT_MAX;
    d[p] = 0;

    for(int i=1; i<=K; i++)
    {
        cin>>a>>b>>s;
        edge *e = new edge;
        e->b = b;
        e->wage = s;
        G[a].push_back(*e);
    }

    if(!Bellman_Ford(G,N,d)) cout<<"CYCLE";
    else if(d[k] < INT_MAX) cout<<d[k];
    else cout<<"NO";
    delete[] G;
    delete[] d;
    return 0;
}
