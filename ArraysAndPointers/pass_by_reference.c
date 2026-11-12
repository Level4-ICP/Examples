#include <stdio.h>
// A function which takes a 'pointer' to an int
void sqr_num_by_reference(int *num)
{
    *num = (*num) * (*num); // square the actual value passed
}

// The equivalent function using pass by value, where a new variable is created and the value is copied into it
int sqr_num_by_value(int num)
{
    num = num * num; // square the actual value passed
    return num;
}

int main()
{
    // call the function, passing the address of the variable 'total'
    int total = 10;
    sqr_num_by_reference(&total);
    printf("\nThe value of total is: %d", total);
    int total2 = 10;
    /*total2 = */sqr_num_by_value(total2); //remove the comment block to see this working properly
    printf("\nThe value of total2 is: %d", total2);
    // 'total' will now be set to 100
}