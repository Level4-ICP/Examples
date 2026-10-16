//see do_while and while examples for similar functionality
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
// the real power of a loop comes because we can access something different each time around the loop or use the loop control varaible in a calculation (say to define the size of a circle, which could get bigger each time circle = i*size).
    char sentence[] = "I'm as serious as cancer when I say rhythm is a dancer";
    for (int i=0; i<sizeof(sentence);i++)
    {
        printf("*%c", sentence[i]); //here we are accessing a different letter each time around the loop
    }
}