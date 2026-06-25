#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Plane {
    float a;
    float b;
    float c;
    float d;
} Plane;
//Định nghĩa node
typedef struct NodeType {
    float x;
    float y;
    float z;
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
Node* makeNode(float x, float y, float z){
    Node* new = (Node*)malloc(sizeof(Node));
    new->x = x;
    new->z = z;
    new->y = y;
    new->next = NULL;
    return new;
}
Node *add(Node* p, float x, float y, float z) {
    Node *temp = makeNode(x,y,z);
    p->next = temp;
    return temp;
}
float gttd(float a) {
    if (a>0) return a;
    else return (-a);
}
float distance(Node *points, Plane P) {
    float d = gttd(P.a*points->x + P.b*points->y + P.c*points->z + P.d)/(sqrt(P.a*P.a + P.b*P.b + P.c*P.c));
    if (d == 0) return 0;
    return d;
}
void printList(Node* p) {
    while(p!=NULL) {
        printf("[%.2f %.2f %.2f] ", p->x, p->y, p->z);
        p=p->next;
    }
    printf("\n");
}
int main() {
    LinkedList list;
    LinkedList list1;
    init(&list);
    init(&list1);
    Node *p = list.head;
    Plane P;
    scanf("%f %f %f %f", &P.a, &P.b, &P.c, &P.d);
    float x,y,z;
    while (1) {
        scanf("%f %f %f", &x, &y, &z);
        if (list.head==NULL) {
            list.head = makeNode(x,y,z);
            p = list.head;
        }
        else p = add(p,x,y,z);
        if (x == 0 && y == 0 && z == 0) break;
    }
    Node *p1 = list.head;
    
    while (p1 != NULL) {
        if (list1.head == NULL) {
            Node *new = (Node*)malloc(sizeof(Node));
            new->x = p1->x;
            new->y = p1->y;
            new->z = p1->z;
            new->next = NULL;
            list1.head = new;
        }
        else {
            if (distance(p1, P) <= distance(list1.head, P)) {
                Node *new = (Node*)malloc(sizeof(Node));
                new->x = p1->x;
                new->y = p1->y;
                new->z = p1->z;
                new->next = list1.head;
                list1.head = new;
            }
            else {
                Node *p2 = list1.head;
                while (p2->next != NULL && distance(p1, P) > distance(p2->next, P)) {
                    p2 = p2->next;
                }
                Node *new = (Node*)malloc(sizeof(Node));
                new->x = p1->x;
                new->y = p1->y;
                new->z = p1->z;
                new->next = p2->next;
                p2->next = new;
            }
        }
        p1 = p1->next;
    }
    //Output
    printList(list1.head);
    Node* temp;
    while (list.head != NULL) { 
        temp = list.head; 
        list.head = list.head->next;
        free(temp); 
    }
    while (list1.head != NULL) { 
        temp = list1.head; 
        list1.head = list1.head->next;
        free(temp); 
    }
    return 0;
}