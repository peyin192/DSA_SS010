#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create(int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

void push(Node** head, int value) {
    Node* newNode = create(value);
    newNode->next = *head;
    *head = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf("->");
        temp = temp->next;
    }
    printf("->NULL");
}

void findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    int count = 1;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        if (fast != NULL) {
            slow = slow->next;
            count++;
        }
    }
    printf("Node %d: %d\n", count, slow->data);
}

int main() {
    Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    printList(head);
    findMiddle(head);
    push(&head, 6);
    printList(head);
    findMiddle(head);
}