//now lets see if we can swap the whole list
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    int temp2 =arr[j];
    arr[i] = temp2;
    arr[j] = temp;
}
int main()
{
    int numbers[] = {7,4,8,9,55,99,33,3,54,2};
    int size = sizeof(numbers)/sizeof(int);


    for (int i=0; i<size-1; i++)
    {
        if (numbers[i] > numbers[i+1])
            swap(numbers,i,i+1);
    }
}
//that only swaps then once, so 2 only moves up one place, when it needs to move all the way up to the top