#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

//Queue dung linked lists
typedef struct Queue {
    Node* front;
    Node* back;
} Queue;
void iniQueue(Queue* q) {
    q->back = NULL;
    q->front = NULL;
}
int isEmptyQ(Queue* q) {
    return (q->front == NULL);
}
void put(Queue* q, int value) {
    //Tao node moi
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Loi cap phat bo nho!\n");
        return;
    }
    //Cap nhat value cho node moi
    newNode->data = value;
    newNode->next = NULL;

    //Queue rong thi gan node moi vao node front dong thoi cung la node back
    //Khong rong thi gan vao cuoi list
    if (isEmptyQ(q)) {
        q->front = newNode;
        q->back =newNode;
    }
    else {
        q->back->next = newNode;
        q->back = newNode; //Cap nhat back
    }
}
void get(Queue* q) {
    if(isEmptyQ(q)) {
        return;
    }
    Node* temp = q->front; //tro temp vao node front
    q->front = q->front->next; //Cap nhat front

    //Neu xoa het node thi node front va node back deu tro NULL
    if (q->front == NULL) {
        q->back = NULL;
    }
    free(temp); //Xoa node front
}

//Stack dung linked lists
typedef struct Stack {
    Node* top;
} Stack;
void iniStack(Stack* s) {
    s->top = NULL;
}
int isEmptyS(Stack* s) {
    return (s->top == NULL);
}
void push(Stack* s, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Loi cap phat bo nho!\n");
        return;
    }
    newNode->data = value; //Cap nhat gia tri cua newNode
    newNode->next = s->top; //Moc newNode tren node top cua Stack
    s->top = newNode; //Cap nhat top
}
void pop(Stack* s) {
    if(isEmptyS(s)) {
        return;
    }
    Node *temp = s->top; //temp tro vao node top
    s->top = s->top->next; //Cap nhat top la node ngay ben duoi
    free(temp); //Xoa node top cu
}
int main() {
    Queue q;
    iniQueue(&q);
    put(&q, 10);
    put(&q, 20);
    put(&q, 30);
    get(&q);

    printf("Queue: ");
    while (!isEmptyQ(&q)) {
        printf("%d ", q.front->data);
        get(&q);
    }
    printf("\n");

    Stack s;
    iniStack(&s);
    push(&s, 100);
    push(&s, 200);
    push(&s, 300);
    pop(&s);

    printf("Stack: ");
    while (!isEmptyS(&s)) {
        printf("%d ", s.top->data);
        pop(&s);
    }
    printf("\n");
    return 0;
}
