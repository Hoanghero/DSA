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


void insertHead(int data, LinkedList* list){
    Node* new = makeNode(data);
    new->next = list->head;
    list->head = new;
    return;
}
void insertTail(int data, LinkedList* list) {
    Node* p = list->head;
    while (p->next->next != NULL) {
        p = p->next;
    }
    Node* new = makeNode(data);
    p->next = new;
}
void deleteHead(LinkedList *list) {
    Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
}
void deleteTail(LinkedList *list) {
    Node* p = list->head;
    while (p->next->next != NULL) {
        p = p->next;
    }
    p->next = NULL;
}

void pr(LinkedList *list) {
    Node* p = list->head;
    while (p != NULL) {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}
void add(LinkedList* list, Node* p, int id, int *a, int n) {
    if (id >= n) 
        return;
    
    Node *temp = makeNode(a[id]);
    p->next = temp;
    add(list, p->next, id+1, a, n);
}
int main(){
    LinkedList list;
    init(&list);
    int a[100] = {2,12,9,0,11,3,4,8};

    list.head = makeNode(2); // Head la 2
    Node* p = list.head;
    add(&list, p, 1,a,8);

    printf("Chen so 19 vao dau danh sach: ");
    insertHead(19, &list);
    pr(&list);
    printf("Chen so -3 o cuoi danh sach: ");
    insertTail(-3, &list);
    pr(&list);
    printf("Xoa so 19: ");
    deleteHead(&list);
    pr(&list);
    printf("Xoa so -3: ");
    deleteTail(&list);
    pr(&list);
    return 0;
}
