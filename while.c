#include <stdio.h>

int main()
{
    printf("count up\n");
    int i = 1;

    while (i <= 5)
    {
        printf("%d\n", i);
        i++;
    }

   i = 5;
    printf("count down?\n");
    while (i > 0)
    {
        printf("%d\n", i);
        i--;
    }

    printf("loop does nothing\n");
    i = 5;
    printf("count down\n");
    while (i < 5)
    {
        printf("%d\n", i);
        i++;
    }
}