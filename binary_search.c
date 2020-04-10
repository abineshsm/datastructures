#include <stdio.h>

int binarySearchIteration(int arr[], int len, int search)
{
    int start = 0;
    int end = len - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == search)
            return mid;
        else if (search < arr[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int binarySearchRecursion(int arr[], int search, int start, int end)
{
    int mid = (start + end) / 2;
    if(arr[mid] == search)
        return mid;
    else if(search < arr[mid])
        return binarySearchRecursion(arr, search, start, mid-1);
    else if(search > arr[mid])
        return binarySearchRecursion(arr, search, mid + 1, end);
}

int main()
{
    int arr[] = {17, 87, 98, 1023, 5098};
    int len = sizeof(arr) / sizeof(arr[0]);
    // printf("%d", binarySearchIteration(arr, len, 1023));
    printf("%d", binarySearchRecursion(arr, 17, 0, 4));
}