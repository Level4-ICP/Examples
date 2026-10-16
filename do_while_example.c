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

    //here a while is not going round a set number of times (we'd use a for loop for that)
    //It is being used to validate data (see do..while() example for a better version)
    printf("Enter data, 1 to 5 \n");
    char choice;

    do
    {
        printf("Enter data, 1 to 5 \n");
        choice = getchar();

    }while (choice < '1' || choice > '5');
    printf("Processing...\n");
    //see while example, note that this one does not say "incorrect" but we could add that with an if.
}