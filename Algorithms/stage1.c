//implementing a sort stage 1
//lets just get it so that it can swap two elements if they need swapping
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

    if (numbers[0] > numbers[1])
        swap(numbers,0,1);
}