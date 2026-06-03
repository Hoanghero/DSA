#include <stdio.h>
#define MAX 7

typedef struct {
    int head, tail, count;
    int a[MAX];
} CircleQueue;

void init(CircleQueue* q) {
    q->head = 0;
    q->tail = 0;
    q->count = 0;
}
int isFull(CircleQueue *q) {
    return q->count == MAX;
}
int isEmpty(CircleQueue *q) {
    return q->count == 0;
}
void put(CircleQueue* q, int value) {
    q->a[q->tail] = value;
    q->count++;
    q->tail = (q->tail + 1) % MAX;
}
int get(CircleQueue* q) {
    if (isEmpty(q)) {
        printf("Queue rong! Khong the lay phan tu.\n");
        return -1; 
    }
    int temp = q->a[q->head];
    q->head = (q->head + 1) % MAX;
    q->count--;
    if (q->head == q->tail) {
        q->head = 0;
        q->tail = 0;
        q->count = 0;
    }
    return temp;
}
void displayQueue(CircleQueue*q) {
    if (isEmpty(q)) {
        printf("CircleQueue is empty.\n");
        return;
    }
    printf("CircleQueue: ");
    for (int i = 0; i < q->count; i++) {
        int index = (q->head + i) % MAX;
        printf("%d ", q->a[index]);
    }
    printf("\n");
}
int main() {
    CircleQueue q;
    init(&q);
    int num[7] = {-5,2,4,-3,1,0,9};
    int num1[3] = {8,4,-3};
    // push
    printf("MAX = %d\n\n", MAX);
    printf("Queue is empty at the beginning\n");
    printf("PUT\n");
    for (int i = 0; i < 7; i++){
        printf("put %d: \n",num[i]);
        if(!isFull(&q)){
            put(&q,num[i]);
            displayQueue(&q);
            printf("\n");
        }
        else {
            printf("Queue is full. \n\n");
        }
    }
    // get
    printf("GET\n");
    for (int i=0; i<5; i++) {
        printf("get %d: %d\n",i, get(&q));
        displayQueue(&q);
        printf("\n");
    }
    printf("PUT\n");
    for (int i = 0; i < 3; i++){
        printf("put %d: \n",num1[i]);
        if(!isFull(&q)){
            put(&q,num1[i]);
            displayQueue(&q);
            printf("\n");
        }
        else {
            printf("Queue is full. \n\n");
        }
    }
    printf("GET\n");
    for (int i=0; i<3; i++) {
        printf("get %d: %d\n",i, get(&q));
        displayQueue(&q);
        printf("\n");
    }
    return 0;
}
