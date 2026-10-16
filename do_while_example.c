#include <stdio.h>

int main()
{
    printf("count up\n");
    int i = 1;

    do
    {
        printf("%d\n", i);
        i++;
    }while (i <= 5);

    i = 5;
    printf("count down\n");

    do
    {
        printf("%d\n", i);
        i--;
    } while (i > 0);


    i = 5;
    printf("count down?\n");

    {
        printf("%d\n", i);
        i++;
    } while (i < 5);
}