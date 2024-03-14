#include <stdio.h>
#include <stdlib.h>

struct Node {
    float data;
    struct Node* next;
};

struct Node* createNode(float data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, float data) {
    struct Node* new_node = createNode(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct Node* last_node = *head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%f -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    append(&head, 0);
    append(&head, 1.23);
    append(&head, -0.2321);

    printf("Linked List: ");
    printList(head);

    return 0;
}
