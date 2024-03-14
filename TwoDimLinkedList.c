// Two dimensional linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    float data;
    struct Node* next;
    struct Node* child;
};

struct Node* createNode(float data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->child = NULL;
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

void addChild(struct Node* parent, float data) {
    struct Node* new_child = createNode(data);
    parent->child = new_child;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%f -> ", node->data);
        if (node->child != NULL) {
            printf("Child: ");
            printList(node->child);
        }
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;

    append(&head, 1);
    append(&head, 2);

    addChild(head, 11);
    append(&(head->child), 12);

    printf("Linked List: ");
    printList(head);

    return 0;
}
