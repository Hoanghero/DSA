#include<stdio.h>
#define MAX 100

typedef struct Queue {
    int arr[MAX];
    int front, rear;
} Queue;

void initalize(Queue *queue) {
    queue->front = queue->rear = -1;
}

int isFull(Queue *queue) {
    return queue->rear == MAX - 1;
}

int isEmpty(Queue *queue) {
    return queue->front == -1;
}

void enqueue(Queue *queue, int data) {
    if (!isFull(queue)) {
        if (queue->rear == -1) {
            queue->rear = queue->front = 0;
            queue->arr[queue->rear] = data;
            return;
        }
        queue->rear++;
        queue->arr[queue->rear] = data;
    } else {
        printf("Queue is Full. Cannot insert element.\n");
    }
}

void dequeue(Queue *queue) {
    if (!isEmpty(queue)) {
        printf("\nDequeued Element: %d", queue->arr[queue->front]);
        if (queue->rear == queue->front) {
            queue->rear = queue->front = -1;
        } else {
            queue->front += 1;
        }
    } else {
        printf("\nQueue is Empty. Cannot dequeue.");
    }
}

void display(Queue *queue) {
    if (isEmpty(queue)) {
        printf("\nQueue is Empty.");
        return;
    }

    printf("\nQueue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
}

int main() {
    Queue queue;
    initalize(&queue);
    int choice, data;

    while (1) {
        printf("\n\n--- Queue Menu ---");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data to enqueue: ");
            scanf("%d", &data);
            enqueue(&queue, data);
            break;
        case 2:
            dequeue(&queue);
            break;
        case 3:
            display(&queue);
            break;
        case 4:
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
