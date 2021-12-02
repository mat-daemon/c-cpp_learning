#include <iostream>

using namespace std;

struct wielomian
{
    int w;
    wielomian* next;
};

wielomian* odejmowanie(wielomian* wsk1, wielomian* wsk2)
{   wielomian* wskaznik;
    wielomian* zwrot;
    wskaznik=new wielomian;
    zwrot=wskaznik;
    if(wsk1==NULL && wsk2==NULL) {zwrot=NULL; return zwrot;}
    if(wsk1!=NULL && wsk2!=NULL)
    {
        wskaznik->w=(wsk1->w)-(wsk2->w);
        wsk1=wsk1->next;
        wsk2=wsk2->next;
    }
    while( wsk1!=NULL && wsk2!=NULL)
    {   wskaznik->next=new wielomian;
        wskaznik=wskaznik->next;
        wskaznik->w=(wsk1->w)-(wsk2->w);
        wsk1=wsk1->next;
        wsk2=wsk2->next;
    }
    if(wsk1==NULL)
    {
        while(wsk2!=NULL)
        {
            wskaznik->next=new wielomian;
            wskaznik=wskaznik->next;
            wskaznik->w=-wsk2->w;
            wsk2=wsk2->next;
        }
    }
    if(wsk2==NULL)
    {
        while(wsk1!=NULL)
        {
            wskaznik->next=new wielomian;
            wskaznik=wskaznik->next;
            wskaznik->w=wsk1->w;
            wsk1=wsk1->next;
        }

    }
    wskaznik->next=NULL;

    return zwrot;
}

int main()
{
    wielomian p1, p2, p3, p4, q1, q2, q3, q4,p5, p6, p7;
    p1.w=2; p2.w=4; p3.w=-8; p4.w=3; p5.w=69; p6.w=666; p7.w=128; p1.next=&p2; p2.next=&p3; p3.next=&p4; p4.next=&p5; p5.next=&p6; p6.next=&p7; p7.next=NULL;
    q1.w=-6; q2.w=7; q3.w=6; q4.w=-1;  q1.next=&q2; q2.next=&q3; q3.next=&q4; q4.next=NULL;

    wielomian* wsk=odejmowanie(&p1, &q1);

    while(wsk!=NULL)
    {
        cout<<wsk->w<<endl;
        wsk=wsk->next;
    }
}
