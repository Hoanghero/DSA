#include <stdio.h>
#include <stdlib.h>
typedef struct NodeType {
    int data;
    struct NodeType* next;
} Node;
typedef struct LinkedListType {
    Node* head;
} LinkedList;
//Check list rong
int isEmpty(LinkedList *list) {
    if (list == NULL || list->head == NULL) return 1;
    return 0;
}
void insert(LinkedList *list, int data) {
    if (isEmpty(list)) {
        //Khoi tao node new
        Node *new = (Node*)malloc(sizeof(Node));
        //Phan tu head o list la new
        new->data = data;
        new->next = NULL;
        list->head = new;
        return;
    }
    //Truong hop: data nho hon hoac bang data cua head => chen o dau list
    if (list->head->data <= data) {
        Node *temp = (Node*)malloc(sizeof(Node));
        temp->data = data;
        temp->next = list->head;
        list->head = temp;
        return;
    }
    //Khoi tao node p la node dau list
    Node *p = list->head;
    while (p->next != NULL && p->next->data > data) p=p->next; //Duyet tung phan tu cua list, gap phan tu <= data thi stop
    if (p->next != NULL) {
        Node *temp = (Node*)malloc(sizeof(Node));
        temp->data = data;
        temp->next = p->next;
        p->next = temp;
        return;
    }
    else {
        Node *new = (Node*)malloc(sizeof(Node));
        new->data = data;
        new->next = NULL;
        p->next = new;
        return;
    }
}
void deleteDequy(Node **head1, int value) {
    if (*head1 == NULL) return;
    if ((*head1)->data > value) return;
    if ((*head1)->data == value) {
        Node *temp = *head1;
        (*head1) = (*head1)->next;
        free(temp);
        return;
    }
    deleteDequy(&(*head1)->next, value);
}
void delete(LinkedList *list, int value) {
    if (isEmpty(list)) return;
    deleteDequy(&(list->head), value);
}
void printList(LinkedList *q) {
    Node *p = q->head;
    while(p!=NULL) {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}
int main() {
    int data, value = 11;
    int v[100] = {1,4,7,9,11,15,22,45,46,59};
    LinkedList h;
    h.head = NULL; // List rong ban dau
    //insert
    printf("Input: ");
    for (int i=0; i<5; i++) {
        scanf("%d", &data);
        insert(&h, data);
    }
    //delete
    LinkedList q;
    q.head = NULL; // List rong ban dau
    q.head = (Node*)malloc(sizeof(Node));
    q.head->data = v[0];
    q.head->next = NULL;
    Node *p = q.head;
    for (int i=1; i<10; i++) {
        Node *new = (Node*)malloc(sizeof(Node));
        new->data = v[i];
        new->next = NULL;
        p->next = new;
        p=p->next; // dich chuyen p len mot vi tri
    }
    delete(&q, value);
    printf("Linked List giam dan: ");
    printList(&h);
    printf("Linked List tang dan: ");
    printList(&q);
    return 0;
}