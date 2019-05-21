#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, void **arg)
{
    int n, k;
    char s[100000+1];
    char t[100000+1];
    int tw = 0;
    int max = 0;
    int w, old;

    scanf("%d %d", &n, &k);
    scanf("%s", s);

    t[tw++] = 0;
    for (int i = 0; i < n; )
    {
        char c;
        int count;

        c = s[i];
        count = 0;
        while( s[i] != '\0' && s[i] == c )
        {
            count++;
            i++;
        }

        t[tw++] = count;
    }

    for (int i = 0; i < tw; i++)
    {
        printf("%d ", t[i]);
    }
    puts("");
    

    w = 2 * k + 1;
    old = 0;
    for (int i = 0; i < n-w; i++)
    {
        int m;

        m = 0;
        if( old != 0 )
        {
            for (int j = 0; j < w; j++)
            {
                m += t[i+j];
            }
        }
        else
        {
            m = old - t[i-1] + t[i+w-1];
        }

printf("m = %d\n", m);

        if( m > max ) max = m;
    }
    

    printf("%d\n", max);

    return 0;
}
