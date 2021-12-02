#include <stdio.h>
#include <stdlib.h>



void BuildHeap(int **arr, int x, int length)
{
    for(int i=length/2; i>=1; i--)
    {
        Heapify(arr, x, i, length);
    }
}

void Heapify(int **arr, int x, int i, int length)
{
    int left=i*2;
    int right=i*2+1;
    int largest=i;
    if(left<=length && arr[x][left]>arr[x][largest]) largest=left;
    if(right<=length && arr[x][right]>arr[x][largest]) largest=right;

    if(largest != i)
    {
        int tmp=arr[x][i];
        arr[x][i]=arr[x][largest];
        arr[x][largest]=tmp;
        Heapify(arr, x, largest, length);
    }
}

void Heapsort(int **arr, int x, int length)
{
    BuildHeap(arr, x, length);
    for(int i=length; i>=2; i--)
    {
        int tmp=arr[x][i];
        arr[x][i]=arr[x][1];
        arr[x][1]=tmp;
        length=length-1;
        Heapify(arr, x, 1, length);
    }
}

int main()
{
    int **arr;
    int Z=0;
    scanf("%d", &Z);
    arr = malloc( (Z+1) * sizeof( int * ) );
    for(int i=1; i<=Z; i++)
    {
        int n=0;
        scanf("%d", &n);
        arr[i] = malloc( (n+1) * sizeof( int ) );
        arr[i][0]=n;
        for(int j=1; j<=n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i=1; i<=Z; i++)
    {
            Heapsort(arr, i, arr[i][0]);

    }
    for(int i=1; i<=Z; i++)
    {

        for(int j=1; j<=arr[i][0]; j++)
        {
            printf("%d\n", arr[i][j]);
        }
    }

}
