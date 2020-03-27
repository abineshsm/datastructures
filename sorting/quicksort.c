#include <stdio.h>

int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int pIndex = start;
    for (int i = start; i < end; i++)
    {
        if (arr[i] <= pivot)
        {
            int temp = arr[i];
            arr[i] = arr[pIndex];
            arr[pIndex] = temp;
            pIndex++;
        }
    }
    int temp = arr[end];
    arr[end] = arr[pIndex];
    arr[pIndex] = temp;
    return pIndex;
}

int quicksort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pIndex = partition(arr, start, end);
        quicksort(arr, start, pIndex - 1);
        quicksort(arr, pIndex + 1, end);
    }
}

int main()
{
    int arr[] = {7, 2, 9, 1, 8, 3, 6};
    int end = sizeof(arr) / sizeof(arr[0]) - 1;
    quicksort(arr, 0, end);
    for (int i = 0; i <= end; i++)
    {
        printf("%d, ", arr[i]);
    }
}