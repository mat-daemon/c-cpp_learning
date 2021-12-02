#include <iostream>

using namespace std;

struct node
{
    int w;
    node *next;
};

void reversal(node *&wsk)
{

    node *tmp; node *prev; node *curr;
    tmp=wsk->next;
    prev=wsk;
    wsk->next=NULL;
    while(tmp!=NULL)
    {   curr=prev;
        prev=tmp;
        tmp=tmp->next;
        prev->next=curr;
    }
    wsk=prev;
}

void write(node *wsk)
{
    while(wsk!=NULL)
    {
        cout<<wsk->w<<" ";
        wsk=wsk->next;
    }
    cout<<"---------------------------------";
}
int main()
{
    node han;node nah;node mont;node anah;
    han.w=75; han.next=&nah;

    nah.w=6746; nah.next=&mont;

    mont.w=7658569; mont.next=&anah;

    anah.w=45748; anah.next=NULL;

    node *wsk=&han;

    write(wsk);

    reversal(wsk);

    write(wsk);
}
