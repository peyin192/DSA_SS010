#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node*next;
}Node;
Node*creatNode(int value) {
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
void printList(Node*head) {
    Node*current=head;
    while (current!=NULL) {
        printf("data=%d \n", current->data);
        current=current->next;
    }
}
int main(){
    Node*node1=creatNode(5);
    Node*node2=creatNode(4);
    Node*node3=creatNode(3);
    Node*node4=creatNode(2);
    Node*node5=creatNode(1);
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    node5->next=NULL;
    Node*head=node1;
    Node*temp=head;
    while (temp!=NULL) {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
    printList(head);

    return 0;
}