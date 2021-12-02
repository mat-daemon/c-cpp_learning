#include <iostream>
#include <list>

using namespace std;

int counter;
bool eulerian;
void Metrogenerator(list<int> *G, list<int> *lines, int u)
{
    while(G[u].empty() != true)
    {
        int v = G[u].front();
        G[v].remove(u);
        G[u].pop_front();
        Metrogenerator(G, lines, v);
    }
    if(eulerian == false && u == 0)
    {
        counter++;
    }
    else
    {
        lines[counter].push_back(u);
    }
}

int main()
{
    int Z;
    cin>>Z;

    for(int i=1; i<=Z; i++)
    {
        int n,m;
        cin>>n;
        cin>>m;
        list<int> *G = new list<int>[n+2];
        list<int> *lines = new list<int>[n+2];

        for(int j=1; j<=m; j++)
        {
            int u,v;
            cin>>u;
            cin>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        eulerian = true;

        for(int j=1; j<=n; j++)
        {
            if(G[j].size()%2 != 0)
            {
                G[j].push_back(0);
                G[0].push_back(j);
                eulerian = false;
            }
        }
        counter = 0;
        if(eulerian) Metrogenerator(G, lines, 1);
        else Metrogenerator(G, lines, 0);

        int subway = 0;
        for(int j = 0; j <= counter; j++)
        {
            if(lines[j].size() > 1) subway++;
        }
        cout<<subway<<"\n";

        for(int j = 0; j <= counter; j++)
        {
            if(lines[j].size() > 1)
            {
                cout<<lines[j].size()<<" ";
                for(list<int>::iterator it = lines[j].begin(); it != lines[j].end(); it++)
                {
                    cout<<*it<<" ";
                }
                cout<<"\n";
            }
        }
        delete[] G;
        delete[] lines;
    }
}

