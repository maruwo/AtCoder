#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, void **arg)
{
    char s[100000+1];
    int count = 0;

    scanf("%s", s);

    for (int i = 1; s[i] != '\0'; i++)
    {
        if( s[i-1] == s[i] )
        {
            s[i] = s[i] == '0' ? '1' : '0';
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
