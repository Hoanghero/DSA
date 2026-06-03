#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct Queue {
    Node* front;
    Node* back;
} Queue;
void iniQueue(Queue* q) {
    q->back = NULL;
    q->front = NULL;
}
int isEmpty(Queue* q) {
    return (q->front == NULL);
}
void push(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Loi cap phat bo nho!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = newNode;
        q->back =newNode;
    }
    else {
        q->back->next = newNode;
        q->back = newNode;
    }
}
void pop(Queue* q) {
    if(isEmpty(q)) {
        return;
    }
    Node* temp = q->front;
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->back = NULL;
    }
    free(temp); 
}
int peek(Queue* q) {
    if(isEmpty(q)) {
        printf("Queue rong!\n");
        return -1;
    }
    return q->front->data;
}
int main() {
    int a[1000], n, k, count=0;
    int b[100005] = {0};
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &k);
    Queue hangdoi;
    iniQueue(&hangdoi);

    push(&hangdoi, a[0]);
    b[a[0]]+=1;
    count++;
    if (n==1) {
        int d=peek(&hangdoi);
        printf("%d", d);
        pop(&hangdoi);
    }
    else {
        for (int i=1; i<n; i++) {
            if (b[a[i]]==0) {
                if (count==k) {
                    b[peek(&hangdoi)]-=1;
                    pop(&hangdoi);
                    push(&hangdoi, a[i]);
                    b[a[i]]+=1;
                }
                else {
                    push(&hangdoi, a[i]);
                    b[a[i]]+=1;
                    count++;
                }
            }
            
        }
        while (!isEmpty(&hangdoi)) {
            int c = peek(&hangdoi);
            printf("%d ", c);
            pop(&hangdoi);
        }
    }
    return 0;
}