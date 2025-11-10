#include<stdio.h>
void select_k_elements(int arr[], int n, int k, int result[]) {
    for (int i = 0; i < k; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        result[i] = arr[i]; 
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11, 5, 78, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k ;
    printf( "Enter the value of k: "); 
    scanf("%d", &k);
    int result[k];

    select_k_elements(arr, n, k, result);

    printf("The %d smallest elements are: ", k);
    for (int i = 0; i < k; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}