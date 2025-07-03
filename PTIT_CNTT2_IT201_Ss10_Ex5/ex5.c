#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
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
    Node*head=NULL;
    // Tạo danh sách
    int values[ ] = {5, 4, 3, 5, 2, 1, 5};
    int n = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < n; i++) {
        Node* newNode = createNode(values[i]);
        newNode->next = head;
        head = newNode;
    }
    printf("Danh sach ban dau la:\n");
    printList(head);

    // Nhập giá trị cần xóa
    int x;
    printf("\nNhap so muon xoa: ");
    scanf("%d", &x);

    //Xoá x
    Node* current = head;
    Node* prev = NULL;

    // Xóa các node đầu trùng x
    while (current != NULL && current->data == x) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    head = current;

    // Xóa các node ở giữa/cuối trùng x
    while (current != NULL) {
        if (current->data == x) {
            Node* temp = current;
            prev->next = current->next;
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
    printf("\nDanh sach sau khi xoa %d:\n", x);
    printList(head);
    return 0;
}