#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue
{
    int sec;
    int sec2;
    char number[16];
    struct queue* next;

}queue;


int extract(char* line)
{
    int i = 2;
    int sec=0;
    while(line[i] != 32)
    {
        sec*=10;
        sec=sec+(line[i]-'0');
        i++;
    }
return sec;
}


void write(char* number, char* number2)
{

}



int main()
{
    int n=0;
    int sec=0;
    int sec2=0;
    char type;
    char space;
    char number[16];
    scanf("%d", &n);

    queue* warrior = (queue*)malloc(sizeof(queue));
    warrior->next=NULL;
    queue* start = warrior;
    queue* end = start;


    for(int i=1; i<=n; i++)
    {
        printf("iteracja: %d", i);
        for(int j=0; j<50; j++) number[j]="\0";
        printf("wpisz type: ");
        scanf("%c %d %s", &type, &sec, &number);


        if(type == 'a')
        {
            end->next = (queue*)malloc(sizeof(queue));
            end = end->next;
            end->next=NULL;
            end->sec=sec;
            end->sec2=-1;
            write(end->number, number);
        }

        else if(type == 'r')
        {   scanf("%d", &sec2);
            start = start->next;
            start->sec2 = sec2;

        }
    }


    queue* wsk=warrior;
    warrior = warrior->next;
    free(wsk);



    while(warrior != NULL && warrior->sec2!=-1)
    {

    }

    return 0;
}
