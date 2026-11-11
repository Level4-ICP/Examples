//
// Created by Duncan on 11/11/2026.
//
#include <stdio.h>

int main()
{
    char name[] = "Neil Armstrong";
    printf("%s\n", name);
    name[1] = 'i';
    name[2] = 'a';
    printf("%s\n", name);
    name[-1] = 'a'; //yikes! out of bounds but C does not bounds check, could be changing a different variable, blank memory, or another program!
    fflush(stdout);

    int numbers[10];
    for (int i = 0; i < sizeof(numbers)/sizeof(int); i++) //to find the size of an array we call sizeof (which returns its size in bytes) then / by size of the variable type
    {
        numbers[i] = i*99;
    }
    numbers[100]=999; //out of bounds!
    int grid[4][5] = { {1,2,3,4,5}, {1,4,9,16,25} }; //think of it as grid[row][column]
    printf("");


}
