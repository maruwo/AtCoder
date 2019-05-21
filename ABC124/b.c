#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, void **arg)
{
    int n;
    int h[20];
    int count = 1;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &h[i]);
    }

    for (int i = 1; i < n; i++)
    {
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if( h[i] < h[j] ) break;
        }
        
        if( j < 0 ) count++;
    }
    

    printf("%d\n", count);

    return 0;
}
