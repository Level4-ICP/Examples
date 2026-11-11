/*pointer.c
demonstrates the concepts behind pointers
run in the debugger to see
D Mullier 11/2026
*/


#include <stdio.h>
//note %p	Pointer address (usually prints in hexadecimal like 0x7fff...)

int main()
{
    int num1 = 10;  //a normal variable
    int* ptr = &num1;   //a pointer holds the address pf the variable
    *ptr =999;  //accessing the variable via its pointer (see in the debugger)
    num1 = sizeof(int);
    printf("An integer takes up %d bytes of memory.\n", num1);
    printf("The value of num1 is: %d (num1)\n", num1); //nothing special there
    printf("The address of num1 is %p (&num1)\n", &num1); //the memory address where it is stored
    // now using the pointer ptr
    printf("Address stored inside ptr:  %p (ptr)\n", ptr);
    printf("Value stored at the address held by ptr: %d (*ptr)\n", *ptr);

    printf("\n\n");
    fflush(stdout); //otherwise we won't see the console output in the debugger
    int numbers[] = {5,8,4,2,9,7,3,6,1};
    int* arrayPtr;
    arrayPtr = numbers; //note the array is already a (nearly) a pointer, so no need for &
    int* basePtr = arrayPtr; //a copy of the array pointer that we will not increment
    for (int i=0; i<sizeof(numbers)/sizeof(int); i++)
    {
        printf("numbers[%d] = %d\n", i,numbers[i]);
        printf("*arrayPtr (%p) = %d\n", arrayPtr, *arrayPtr);
        printf("*(basePtr+i) + %d = %d\n\n", i, *(basePtr+i)); //how many integer sized cells to add on to the address
        arrayPtr++; //increment the pointer to the next integer
        fflush(stdout); //otherwise we won't see the console output in the debugger
    }


}