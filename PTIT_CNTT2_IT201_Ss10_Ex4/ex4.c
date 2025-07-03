#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node*next;
}Node;
Node* createNode(int value) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
void printList(Node* head) {
    Node* current=head;
    while(current!=NULL) {
        printf("%d -> ",current->data);
        current=current->next;
    }
    printf("NULL\n");
}
int main() {
    Node* head=NULL;
    for(int i=1;i<= 5;i++) {
        Node* newNode=createNode(i);
        newNode->next=head;
        head=newNode;
    }
    printList(head);
    if(head==NULL) {
        return 0;
    }
    if(head->next==NULL) {
        free(head);
        head=NULL;
    }else {
        Node* current=head;
        while(current->next->next!=NULL) {
            current=current->next;
        }
        free(current->next);
        current->next=NULL;
    }
    printList(head);
    return 0;
}