#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

struct Node* merge_sorted_lists(struct Node* l1, struct Node* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    struct Node* merged_head = NULL;

    if (l1->data < l2->data) {
        merged_head = l1;
        l1 = l1->next;
    } else {
        merged_head = l2;
        l2 = l2->next;
    }

    struct Node* current = merged_head;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data < l2->data) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    if (l1 != NULL) {
        current->next = l1;
    } else {
        current->next = l2;
    }

    return merged_head;
}

void print_list(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

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

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    append(&list1, 1);
    append(&list1, 3);
    append(&list1, 5);

    append(&list2, 2);
    append(&list2, 4);
    append(&list2, 6);

    printf("List 1: ");
    print_list(list1);
    printf("List 2: ");
    print_list(list2);

    struct Node* merged_list = merge_sorted_lists(list1, list2);
    printf("Merged Sorted List: ");
    print_list(merged_list);

    return 0;
}