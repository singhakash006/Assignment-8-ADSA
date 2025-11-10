#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void selectionSort(int arr[], int start, int end) {
    int i, j, minIdx, temp;
    for (i = start; i <= end; i++) {
        minIdx = i;
        for (j = i + 1; j <= end; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

void hybridSort(int arr[], int n, int chunkSize) {
    int i;

    for (i = 0; i < n; i += chunkSize) {
        int end = i + chunkSize - 1;
        if (end >= n)
            end = n - 1;
        selectionSort(arr, i, end);
    }

    int size;
    for (size = chunkSize; size < n; size = 2 * size) {
        for (i = 0; i < n - size; i += 2 * size) {
            int mid = i + size - 1;
            int right = i + 2 * size - 1;
            if (right >= n)
                right = n - 1;
            merge(arr, i, mid, right);
        }
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[MAX], n, chunkSize;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter chunk size: ");
    scanf("%d", &chunkSize);

    printf("\nOriginal Array:\n");
    display(arr, n);

    hybridSort(arr, n, chunkSize);

    printf("\nSorted Array (Hybrid Selection + Merge):\n");
    display(arr, n);

    return 0;
}
