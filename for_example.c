#include <stdio.h>

int main()
{
    printf("count up\n");

    for (int i=1; i <= 5; i++)
    {
        printf("%d\n", i);
    }

    printf("count down\n");
    for (int i=5; i > 0; i--)
    {
        printf("%d\n", i);
    }



    printf("count down in steps of 2\n");
    for (int i=10; i > 0; i=i-2)
    {
        printf("%d\n", i);
    }
}