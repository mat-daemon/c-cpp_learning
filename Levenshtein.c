#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 200

int min(int a, int b, int c)
{
    if(a <= b)
    {
        if(a <= c) return a;
        else return c;
    }
    else
    {
        if(b <= c) return b;
        else return c;
    }
}
int** initialize_tab(int a, int b)
{
    int** tab;
    tab = malloc(sizeof(int*)*(a+1));
    for(int i=0; i<=a; i++) tab[i] = malloc(sizeof(int)*(b+1));
    for(int i=0; i<=a; i++) tab[i][0] = i;
    for(int i=1; i<=b; i++) tab[0][i] = i;
    return tab;

}
int Levenshtein(int** tab, char* sentence1, char* sentence2)
{
    int count;
    int a = strlen(sentence1);
    int b = strlen(sentence2);
    for(int i=1; i<=a; i++)
    {
        for(int j=1; j<=b; j++)
        {
            if(sentence1[i-1] == sentence2[j-1]) count = 0;
            else count = 1;

            tab[i][j] = min(tab[i-1][j]+1, tab[i][j-1]+1, tab[i-1][j-1]+count);
        }
    }
    return tab[a][b];
}

int main()
{
    char sentence1[N];
    char sentence2[N];
    int a,b, count;
    int** tab;

    gets(sentence1);
    gets(sentence2);
    a = strlen(sentence1);
    b = strlen(sentence2);
    tab = initialize_tab(a,b);

    count = Levenshtein(tab, sentence1, sentence2);
    printf("%d", count);
}