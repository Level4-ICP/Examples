//see for and do_while examples for similar functionality
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

    //here a while is not going round a set number of times (we'd use a for loop for that)
    //It is being used to validate data (see do..while() example for a better version)
    printf("Enter data, 1 to 5 \n");
    char choice = getchar();

    while (choice < '1' || choice > '5')
    {
        printf("\nIncorrect!\n");
        printf("Enter data, 1 to 5 \n");
        choice = getchar();

    }
    printf("Processing...\n");
}