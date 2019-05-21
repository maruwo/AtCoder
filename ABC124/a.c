#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, void **arg)
{
    int a,b;
    int coin = 0;

    scanf("%d %d", &a, &b);

    for (int i = 0; i < 2; i++)
    {
        coin += a >= b ? a-- : b--;
    }
    
    printf("%d\n", coin);

    return 0;
}
