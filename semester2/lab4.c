#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node* next;
};

void append(struct Node** head_ref, int new_data) {

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    
    struct Node* result = NULL;
    struct Node** tail = &result;

    while (list1 != NULL || list2 != NULL) {
        
        if (list1 != NULL && list2 != NULL) {
            if (list1->data < list2->data) {
                *tail = list1;
                list1 = list1->next;
            } else if (list2->data < list1->data) {
                *tail = list2;
                list2 = list2->next;
            } else {
                *tail = list1;
                list1 = list1->next;
                list2 = list2->next;
            }
        } else if (list1 != NULL) {
            *tail = list1;
            list1 = list1->next;
        } else {
            *tail = list2;
            list2 = list2->next;
        }
        tail = &((*tail)->next);
    }

    return result;
}

int main() {

    struct Node* list1 = NULL;
    append(&list1, 1);
    append(&list1, 3);
    append(&list1, 5);

    struct Node* list2 = NULL;
    append(&list2, 2);
    append(&list2, 3);
    append(&list2, 4);

    printf("List1: ");
    printList(list1);

    printf("List2: ");
    printList(list2);

    struct Node* mergedList = mergeLists(list1, list2);

    printf("Result: ");
    printList(mergedList);

    struct Node* temp;
    
    while (mergedList != NULL) {
        temp = mergedList;
        mergedList = mergedList->next;
        free(temp);
    }

    return 0;
}