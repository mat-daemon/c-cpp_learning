#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void CountingSort(char **ptrondigits, int n, int k)
{

    int tmp[10];
    char **sdigits = &ptrondigits[n];

    for (int i=0; i<=9; i++)
    {
        tmp[i] = 0;
    }

    for (int i=0; i<n; i++)
    {
        tmp[ptrondigits[i][k]-'0']++;
    }

    for (int i=1; i<=9; i++)
    {
        tmp[i] += tmp[i - 1];
    }

    for (int i=n-1; i>=0; i--)
    {

        int digit = ptrondigits[i][k] - '0';

        tmp[digit]--;
        sdigits[tmp[digit]] = ptrondigits[i];
    }

    for (int i=0; i<n; i++)
    {
        ptrondigits[i] = sdigits[i];
    }
}

void RadixSort(char **ptrondigits, int n, int k)
{
    for(int i=k-1; i>=0; i--)
    {
        CountingSort(ptrondigits, n, i);
    }
}

int main()
{
    int Z;
    scanf("%d", &Z);

    for(int x=Z; x>=1; x--)
    {
        int n;
        int k;
        scanf("%d %d", &n, &k);


        char **ptrondigits = malloc(2 * n * sizeof(*ptrondigits));
        char *digits = malloc(n * (k + 1) * sizeof(*digits));

        for (int i=0; i<n; i++)
        {
            ptrondigits[i] = digits + i*(k + 1);
        }

        for (int i=0; i<n; i++)
        {
            scanf("%s", ptrondigits[i]);
        }

        RadixSort(ptrondigits, n, k);

        for (int i=0; i<n; i++)
        {
            printf("%s\n", ptrondigits[i]);
        }
        free(digits);
        free(ptrondigits);

    }
}
