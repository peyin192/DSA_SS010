#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* create(int index) {
    Node* temp = malloc(sizeof(Node));
    temp -> data = index;
    temp -> next = NULL;
    return temp;
}
int main() {
    Node* a = create(1);
    Node* b = create(2);
    Node* c = create(3);
    Node* d = create(4);
    Node* e = create(5);
    a -> next = b;
    b -> next = c;
    c -> next = d;
    d -> next = e;
    e -> next = NULL;
}