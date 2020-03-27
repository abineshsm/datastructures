#include <stdio.h>

int merge(int arr[], int left[], int right[], int leftLen, int rightLen)
{
    int i = 0, j = 0, k = 0;
    while (i < leftLen && j < rightLen)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < leftLen)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < rightLen)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

int divide(int arr[], int len)
{
    if (len > 1)
    {
        int mid = len / 2;
        int left[mid], right[len - mid];
        for (int i = 0; i < mid; i++)
        {
            left[i] = arr[i];
            // printf("%d, ", left[i]);
        }
        // printf("\n");
        for (int j = 0; j < len - mid; j++)
        {
            right[j] = arr[mid + j];
            // printf("%d, ", right[j]);
        }
        // printf("\n");
        divide(left, mid);
        divide(right, len - mid);
        merge(arr, left, right, mid, len - mid);
    }
}

int main()
{
    int arr[] = {2, 4, 1, 6, 8, 5, 3, 7, 11};
    int len = sizeof(arr) / sizeof(arr[0]);
    divide(arr, len);
    for (int i = 0; i < len; i++)
        printf("%d, ", arr[i]);
}