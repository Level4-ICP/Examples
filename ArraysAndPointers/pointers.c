#include <stdio.h>
//note %p	Pointer address (usually prints in hexadecimal like 0x7fff...)

int main()
{
    int num1 = 10;
    int* ptr = &num1;

    printf("The value of num1 is: %d (num1)\n", num1); //nothing special there
    printf("The address of num1 is %p (&num1)\n", &num1); //the memory address where it is stored
    // now using the pointer ptr
    printf("Address stored inside ptr:  %p (ptr)\n", ptr);
    printf("Value stored at ptr: %d (*ptr)\n", *ptr);

    printf("\n\n");

    int numbers[] = {5,8,4,2,9,7,3,6,1};
    int* arrayPtr;
    arrayPtr = numbers; //note the array is already a (nearly) a pointer, so no need for &
    int* basePtr = arrayPtr; //a copy of the array pointer that we will not increment
    for (int i=0; i<sizeof(numbers)/sizeof(int); i++)
    {
        printf("numbers[%d] = %d\n", i,numbers[i]);
        printf("*arrayPtr = %d\n", *arrayPtr);
        printf("*(basePtr+i) + %d = %d\n", i, *(basePtr+i)); //how many integer sizxe cells to add on to the address
        arrayPtr++; //increment the pointer to the next integer
    }


}