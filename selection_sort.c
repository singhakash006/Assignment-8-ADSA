#include <stdio.h>

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
           
        }
         printf("Sorted array after %d iteration:", i, "\n");
            for (int i = 0; i < n; i++)
            {
                 printf("%d ", arr[i]);
            }
            printf("\n");
        // Swap the found minimum element with the first element
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }

    return 0;
}