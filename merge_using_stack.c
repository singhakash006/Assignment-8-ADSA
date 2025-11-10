#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int top;
    int items[MAX][2];
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int left, int right) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    s->items[++s->top][0] = left;
    s->items[s->top][1] = right;
}

void pop(Stack *s, int *left, int *right) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return;
    }
    *left = s->items[s->top][0];
    *right = s->items[s->top--][1];
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

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
}

void mergeSortIterative(int arr[], int n) {
    Stack s;
    initStack(&s);

    push(&s, 0, n - 1);

    int left, right, mid;

    while (!isEmpty(&s)) {
        pop(&s, &left, &right);

        if (left < right) {
            mid = (left + right) / 2;

            push(&s, mid + 1, right);
            push(&s, left, mid);
            merge(arr, left, mid, right);
        }
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[MAX], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nOriginal Array:\n");
    display(arr, n);

    mergeSortIterative(arr, n);

    printf("\nSorted Array using Stack-based Merge Simulation:\n");
    display(arr, n);

    return 0;
}
