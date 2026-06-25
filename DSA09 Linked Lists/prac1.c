#include <stdio.h>
#include <stdlib.h>

//Định nghĩa node
typedef struct NodeType {
    int data;
    struct NodeType* next;
}Node;

//Định nghĩa Linked list
typedef struct LinkedListType{
    Node* head;
}LinkedList;

//Khởi tạo linked list
void init(LinkedList* list) {
    list->head = NULL;
}

//Hàm tạo node mới
Node* makeNode(int data){
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    return new;
}

//Hàm chèn node mới vào đầu danh sách
void insertHead(int data, LinkedList* list){
    Node* new = makeNode(data);
    if (list->head == NULL) {
        list->head = new;
        return;
    }
    new->next = list->head;
    list->head = new;
    return;
}

void deleteHead(LinkedList *list) {
    Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
}

//Hàm in linked list
void printList(LinkedList* list){
    Node* node = list->head;
    while (node != NULL) {
        printf("Node address: %p | ", &(node->data));
        printf("data = %d| ", node->data);
        printf("next node address = %p\n ", node->next);
        node = node->next;
    }
    printf("\n");
}
void pr(LinkedList *list) {
    Node* p = list->head;
    while (p != NULL) {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}
//Hàm main
int main(){
    LinkedList list;
    init(&list);
    //Tạo danh sách tự động
    for(int i = 0; i < 10; i++)
       insertHead(i, &list); 
    //In danh sách
    printList(&list);
    insertHead(15, &list);
    pr(&list);
    deleteHead(&list);
    pr(&list);
    return 0;
}
