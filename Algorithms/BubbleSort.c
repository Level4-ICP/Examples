
#include <stdio.h>

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void printArray(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int size) 
{
    for (int j = 0; j < size-1; j++)
    {
        for (int i = 0; i < size-1; i++)
        {
            if (arr[i] > arr[i+1])
                swap(arr, i, i+1);
        }
    }
}
int main(void)
{
    int numbers[] = {82, 15, 4, 95, 36, 32, 29, 18, 95, 14, 87, 95, 70, 12, 76, 55, 5, 4, 12, 28, 30, 65, 78, 4, 72, 26, 92, 84, 90, 70, 54, 29, 58, 76, 36, 1, 98, 21, 90, 55, 44, 36, 20, 28, 98, 44, 14, 12, 49, 13, 46, 45, 78, 34, 6, 94, 59, 69, 16, 49, 11, 71, 38, 81, 80, 47, 74, 25, 91, 9, 6, 85, 30, 99, 38, 11, 30, 13, 49, 36, 59, 82, 47, 21, 48, 46, 27, 86, 35, 90, 88, 83, 10, 78, 82, 22, 69, 94, 32, 21};
    int size = sizeof(numbers)/sizeof(int);
    printf("unsorted");
    printArray(numbers,size);
    bubbleSort(numbers,size);
    printf("sorted");
    printArray(numbers, size);
}