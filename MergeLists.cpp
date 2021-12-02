#include <iostream>

using namespace std;


struct node
{
    int w;
    node *next;
};

node *scal(node *wsk1, node *wsk2)
{   node *zwrot, *tmp;


    if(wsk1->w <= wsk2->w)
    {
        zwrot=wsk1;
        tmp=wsk1;
        wsk1=wsk1->next;
    }
    else
    {
        zwrot=wsk2;
        tmp=wsk2;
        wsk2=wsk2->next;
    }

    while(wsk1!=NULL && wsk2!=NULL)
    {
      if(wsk1->w <= wsk2->w)
      {
          tmp->next=wsk1;
          tmp=wsk1;
          wsk1=wsk1->next;
      }
      else
      {
          tmp->next=wsk2;
          tmp=wsk2;
          wsk2=wsk2->next;
      }
    }
    if(wsk1==NULL)
    {
        while(wsk2!=NULL)
        {
            tmp->next=wsk2;
            tmp=wsk2;
            wsk2=wsk2->next;
        }
    }
    else
    {
        while(wsk1!=NULL)
        {
            tmp->next=wsk1;
            tmp=wsk1;
            wsk1=wsk1->next;
        }
    }
    tmp->next=NULL;
    return zwrot;
}



void wypisz(node *wsk)
{
    while(wsk!=NULL)
    {
        cout<<wsk->w<<" ";
        wsk=wsk->next;
    }
    cout<<endl;
}
int main()
{
    node han, nah, mon, tan, nahxd, mata;
han.w=120; nah.w=123; mon.w=124; han.next=&nah; nah.next=&mon; mon.next=NULL;
tan.w=123; nahxd.w=456; mata.w=457; tan.next=&nahxd; nahxd.next=&mata; mata.next=NULL;
    node *wsk1=&han; node *wsk2=&tan;
    wypisz(wsk1);
    wypisz(wsk2);
    wypisz(scal(wsk1, wsk2));

}
