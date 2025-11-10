#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

void selection_sort_linked_list(struct Node* head) {
    struct Node* i, * j, * min;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        min = i;
        for (j = i->next; j != NULL; j = j->next) {
            if (j->data < min->data) {
                min = j;
            }
        }
        // Swap data
        temp = i->data;
        i->data = min->data;
        min->data = temp;
    }
}

void print_list(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    append(&head, 64);
    append(&head, 25);
    append(&head, 12);
    append(&head, 22);
    append(&head, 11);

    printf("Linked list before sorting: \n");
    print_list(head);

    selection_sort_linked_list(head);

    printf("Linked list after sorting: \n");
    print_list(head);

    return 0;
}