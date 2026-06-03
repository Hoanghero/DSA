#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct Queue {
    Node* front;
    Node* back;
} Queue;
void iniQueue(Queue* q) {
    q->front = NULL;
    q->back = NULL;
}
int isEmpty(Queue* q) {
    return (q->front == NULL);
}
void push(Queue* q, int value) {
    // Cấp phát bộ nhớ cho node mới bằng malloc
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Loi cap phat bo nho!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    // Nếu Queue rỗng
    if (isEmpty(q)) {
        q->front = newNode;
        q->back = newNode;
        return;
    }
    q->back->next = newNode;
    q->back = newNode;
}
int pop(Queue* q) {
    if (isEmpty(q)) {
        return -1;
    }
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->back = NULL;
    }
    free(temp);
    return data;
}

int isPrime(int a) {
    if (a < 2) return 0;
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) {
            return 0; 
        }
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    Queue hangdoi;
    iniQueue(&hangdoi);
    if (n<8) {
        for (int i=2; i<=n; i++) {
            if (isPrime(i)) {
                printf("%d ", i);
            }
        }
    }
    else {
        push(&hangdoi, 2);
        push(&hangdoi, 3);
        push(&hangdoi, 5);
        push(&hangdoi, 7);
        while (!isEmpty(&hangdoi)) {
            int a = pop(&hangdoi);
            for (int i=1; i<=9; i+=2) {
                int k = a*10+i;
                if (isPrime(k) && k<=n) {
                    push(&hangdoi, k);
                }
            }
            printf("%d ", a);
            
        }
    }
    return 0;
}








