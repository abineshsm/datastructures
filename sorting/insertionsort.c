#include <stdio.h>

int main()
{
    int arr[] = {8, 2, 6, 5, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]) - 1;
    for (int i = 1; i <= n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    for(int i = 0; i <= n; i++)
    {
        printf("%d, ", arr[i]);
    }
}