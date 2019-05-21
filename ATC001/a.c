#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char **maze;
char **reached;
int H, W;

void search(int i, int j)
{

    if( i < 0  || H <= i     ) return;
    if( j < 0  || W <= j     ) return;
    if( maze[i][j] == '#'    ) return;
    if( reached[i][j] == '1' ) return;

    reached[i][j] = (char)'1';

    search(i + 1, j    );
    search(i - 1, j    );
    search(i    , j + 1);
    search(i    , j - 1);
}

int main(int argc, void **arg)
{
    int i;
    int si, sj;
    int gi, gj;

    scanf("%d %d", &H, &W);

    maze    = (char**)malloc(H * sizeof(char**));
    reached = (char**)malloc(H * sizeof(char**));

    for (i = 0; i < H; i++)
    {
        int j;

        maze[i]    = (char*)malloc((W + 1) * sizeof(char*));
        reached[i] = (char*)malloc((W + 1) * sizeof(char*));
        memset(maze[i]   , '\0', W + 1);
        memset(reached[i], '\0', W + 1);

        scanf("%s", maze[i]);
        strcpy(reached[i], maze[i]);

        for (j = 0; j < W; j++)
        {
            if( maze[i][j] == 's' )
            {
                si = i;
                sj = j;
            }
            if (maze[i][j] == 'g')
            {
                gi = i;
                gj = j;
            }
        }
    }

    search(si, sj);

    if( reached[gi][gj] == '1' )
        puts("Yes");
    else
        puts("No");

    return 0;
}
