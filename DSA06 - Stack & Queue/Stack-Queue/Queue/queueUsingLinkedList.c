#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int data;
    struct Queue *next;
} Queue;

Queue *front = NULL, *rear = NULL;

Queue *enqueue(Queue *queue, int data) {
    Queue *newNode = (Queue *)malloc(sizeof(Queue));
    newNode->data = data;
    newNode->next = NULL;
    
    if (queue == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    return front;
}

Queue *dequeue(Queue *queue) {
    if (front == NULL) {
        printf("\nQueue is Already Empty !!!!\n");
        return front;
    }

    Queue *temp = front;
    front = front->next;
    printf("\nDequeued data: %d\n", temp->data);
    free(temp);

    if (front == NULL) {
        rear = NULL;
    }

    return front;
}

void display(Queue *queue) {
    Queue *temp = queue;

    if (temp == NULL) {
        printf("\nQueue is Empty!\n");
        return;
    }

    printf("\nQueue Elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue *queue = NULL;
    int ch, data;

    while (1) {
        printf("\n\n----- Queue Menu -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                queue = enqueue(queue, data);
                break;

            case 2:
                queue = dequeue(queue);
                break;

            case 3:
                display(queue);
                break;

            case 4:
                printf("\nExiting...\n");
                exit(0);

            default:
                printf("\nInvalid Choice! Please try again.\n");
        }
    }

    return 0;
}
