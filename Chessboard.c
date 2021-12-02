#include <stdio.h>
#include <stdlib.h>


int jump_bastard(int** board, int a, int b, int x, int y)
{
    if(a == x && b == y)
    {
        if(board[a][b]) return 1;
        else return 0;
    }
    if(a>x || b>y || board[a][b] == 0) return 0;
    return jump_bastard(board, a+1,b,x,y) + jump_bastard(board, a, b+1,x,y) + jump_bastard(board, a+1, b+1,x,y);
}
int main()
{
    int N, a, b, x, y;
    scanf("%d", &N);
    scanf("%d %d", &a, &b);
    scanf("%d %d", &x, &y);
    int** board = malloc(sizeof(int*)*N);
    for(int i=0; i<N; i++) board[i] = malloc(sizeof(int));
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++) scanf("%d", &board[i][j]);
    }
    int count = jump_bastard(board, a,b,x,y);
    printf("%d", count);
}
