//
// Demonstrating the use of the command line
// Go to the terminal and run this program with ./commandLine
// experiment with typing things after the program name
// e.g ./commandLine one two three
#include <stdio.h>
int main(int argc, char *argv[])
{
    printf("Program name: %s\n",argv[0]);
    printf("There are %d parameters.", argc-1); //-1 because it counts the program name
    for (int i=1; i<argc; i++)
    {
        printf("\nParameter %d : %s",i,argv[i]);
    }

}
