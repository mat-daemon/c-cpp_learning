#include <iostream>

using namespace std;

struct point
{
    int x;
    int y;
    point* next;
};

struct linker
{
    point* wsk1;
    point* wsk2;
    point* wsk3;
    point* wsk4;
};

linker divide(point* beg)
{
    linker zwrot;
    zwrot.wsk1=NULL; zwrot.wsk2=NULL; zwrot.wsk3=NULL; zwrot.wsk4=NULL;
    point* tmp;
    while(beg != NULL)
    {
        tmp=beg->next;

        if(beg->x>0 && beg->y>0)
        {
            beg->next=zwrot.wsk1;
            zwrot.wsk1=beg;
        }
        if(beg->x<0 && beg->y>0)
        {
            beg->next=zwrot.wsk2;
            zwrot.wsk2=beg;
        }
        if(beg->x<0 && beg->y<0)
        {
            beg->next=zwrot.wsk3;
            zwrot.wsk3=beg;
        }
        if(beg->x>0 && beg->y<0)
        {
            beg->next=zwrot.wsk4;
            zwrot.wsk4=beg;
        }
        if(beg->x==0 || beg->y==0)
        {
                delete beg;
        }
        beg=tmp;
    }
    return zwrot;
}
point* creator()
{   cout<<"Uruchomiony zostal creator, wpisz po kolei wspolrzedne 5 punktow"<<endl;
    int a,b;
    point* first;
    point* p;
    first=NULL;
    for(int i=1; i<=5; i++)
    {
        cin>>a>>b;
        cout<<endl;
        p=new point;
        p->next=first;
        p->x=a; p->y=b;
        first=p;
    }
    return first;
}
void write(linker letthegamebegin)
{   cout<<"Pierwsza cwiartka: "<<endl;
    while(letthegamebegin.wsk1 != NULL)
    {
        cout<<letthegamebegin.wsk1->x<<" "<<letthegamebegin.wsk1->y<<endl;
        letthegamebegin.wsk1=letthegamebegin.wsk1->next;
    }
    cout<<"Druga cwiartka: "<<endl;
    while(letthegamebegin.wsk2 != NULL)
    {
        cout<<letthegamebegin.wsk2->x<<" "<<letthegamebegin.wsk2->y<<endl;
        letthegamebegin.wsk2=letthegamebegin.wsk2->next;
    }
    cout<<"Trzecia cwiartka: "<<endl;
    while(letthegamebegin.wsk3 != NULL)
    {
        cout<<letthegamebegin.wsk3->x<<" "<<letthegamebegin.wsk3->y<<endl;
        letthegamebegin.wsk3=letthegamebegin.wsk3->next;
    }
    cout<<"Czwarta cwiartka: "<<endl;
    while(letthegamebegin.wsk4 != NULL)
    {
        cout<<letthegamebegin.wsk4->x<<" "<<letthegamebegin.wsk4->y<<endl;
        letthegamebegin.wsk4=letthegamebegin.wsk4->next;
    }
}
int main()
{
    write(divide(creator()));
}
