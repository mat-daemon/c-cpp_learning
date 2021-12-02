#include <stdio.h>
#include <stdlib.h>


typedef struct Pancake
{
    int* tab;
    int size;
    int top;

}Pancake;

int pop(Pancake* stack)
{
    stack->top--;
    return stack->tab[stack->top+1];
}

void push(Pancake* stack, int value)
{
    stack->top++;
    stack->tab[stack->top]=value;
}

int convert(char* element, int k)
{
    int i=0;
    int result=0;
    while(element[i]!='\0' && i<k)
    {
        result*=10;
        result+=(element[i]-'0');
        i++;
    }

    return result;
}


Pancake* newstack(int size)
{
    Pancake* stack = malloc(sizeof(int*)+2*sizeof(int));
    stack->size = size;
    stack->tab = malloc(size*sizeof(int));
    stack->top = -1;
    return stack;
}

int main()
{
    int n,k;
    scanf("%d %d", &n, &k);

    Pancake* stack = newstack(n);


    char* element = malloc(sizeof(char)*(k+1));

    while(n>0 || stack->top > 0)
    {

        for(int i=0; i<k; i++) element[i]='\0';

        scanf("%s", element);

        if(element[0]=='+')
        {
            int x = pop(stack);
            int y = pop(stack);
            int tmp = y+x;
            push(stack, tmp);


        }
        else if(element[0]=='-')
        {
            int x = pop(stack);
            int y = pop(stack);
            int tmp = y-x;
            push(stack, tmp);

        }
        else if(element[0]=='*')
        {
            int x = pop(stack);
            int y = pop(stack);
            int tmp = y*x;
            push(stack, tmp);

        }
        else if(element[0]=='/')
        {
            int x = pop(stack);
            int y = pop(stack);
            int tmp = y/x;
            push(stack, tmp);

        }
        else
        {
            push(stack, convert(element, k));
            n--;
        }
    }
    int wynik = stack->tab[0];
    free(stack->tab);
    free(stack);
    free(element);
    printf("%d", wynik);
    return 0;
}