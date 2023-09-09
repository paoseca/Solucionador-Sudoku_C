#include <stdio.h>
#include <stdbool.h>
int grid[9][9] =    {{5,3,0,0,7,0,0,0,0},
                     {6,0,0,1,9,5,0,0,0},
                     {0,9,8,0,0,0,0,6,0},
                     {8,0,0,0,6,0,0,0,3},
                     {4,0,0,8,0,3,0,0,1},
                     {7,0,0,0,2,0,0,0,6},
                     {0,6,0,0,0,0,2,8,0},
                     {0,0,0,4,1,9,0,0,5},
                     {0,0,0,0,8,0,0,7,9}};
void imprime()
{   int x, y;
    for(x=0; x<9; x++)
    {   for(y=0; y<9; y++)
            printf("%3d", grid[x][y]);
        printf("\n");
    }
}
bool possivel(int x, int y, int n)
{   int i, j, x0, y0;
    for(i=0; i<9; i++)
        if(grid[i][y] == n)
            return false;
    for(j=0; j<9; j++)
        if(grid[x][j] == n)
            return false;
    x0 = (x/3)*3;
    y0 = (y/3)*3;
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            if(grid[x0+i][y0+j] == n)
                return false;
    return true;
}
void resolva()
{   int x, y, n;
    char entrada[50];
    for(x=0; x<9; x++)
        for(y=0; y<9; y++)
            if(grid[x][y] == 0) //vazio
            {   for(n=1; n<=9; n++)  //testo as 9 possibilidades
                    if(possivel(x, y, n))
                    {   grid[x][y] = n;
                        resolva();
                        grid[x][y] = 0;
                    }
                return; //fracasso: não consegui resolver
            }
    imprime();
    printf("Mais alguma resposta? ");
    gets(entrada);
}
int main()
{
    printf("Sudoku\n\n");
    resolva();
    return 0;
}