#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
Node* createNode(int value) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
void printList(Node* head) {
    Node*current=head;
    while(current!=NULL) {
        printf("%d -> ",current->data);
        current=current->next;
    }
    printf("NULL\n");
}
int main() {
    Node* head=NULL;
    int values[]={3,5,7};
    int n=sizeof(values)/sizeof(values[0]);
    for(int i=0;i<n;i++) {
        Node* newNode=createNode(values[i]);
        newNode->next=head;
        head=newNode;
    }
    printf("Danh sach ban dau:");
    printList(head);
    Node* i=head;
    while(i!=NULL) {
        Node* j=i->next;
        while(j!=NULL) {
            if (i->data > j->data) {
                int temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
            j=j->next;
        }
        i=i->next;
    }
    printList(head);
}