#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
}Node;
Node* createNode(int value) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Khong hop le");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void printList(Node* head) {
    Node*current=head;
    while (current!=NULL) {
        printf("%d ->",current->data);
        current=current->next;
    }
    printf("NULL\n");
}
void createNodeToEnd(Node** head,int value) {
    Node* newNode=createNode(value);
    if(*head==NULL) {
        *head=newNode;
    }else {
        Node*current=*head;
        while (current->next!=NULL) {
            current=current->next;
        }
        current->next=newNode;
    }
}
void freeList(Node* head) {
    Node*temp;
    while(head!=NULL) {
        temp=head;
        head=head->next;
        free(temp);
    }
}
int main() {
    Node*head=NULL;
    createNodeToEnd(&head,1);
    createNodeToEnd(&head,2);
    createNodeToEnd(&head,3);
    createNodeToEnd(&head,4);
    createNodeToEnd(&head,5);
    int value;
    printf("Nhap gia tri muon them vao cuoi danh sach:");
    scanf(" %d",&value);
    createNodeToEnd(&head,value);
    printf("Danh sach sau khi them la:");
    printList(head);

    freeList(head);
    return 0;
}