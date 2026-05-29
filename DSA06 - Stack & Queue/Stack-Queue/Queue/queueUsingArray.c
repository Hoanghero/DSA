#include<stdio.h>
#define MAX 100

int queue[MAX], front, rear;

void intialize() {
    front = rear = -1;
}

int isEmpty() {
    return front == -1;
}

int isFull() {
    return rear == MAX;
}

void enqueue(int data) {
    if (!isFull()) {
        if (rear == -1) {
            front = rear = 0;
            queue[rear] = data;
            return;
        }
        queue[++rear] = data;
    } else {
        printf("\nQueue is Full!\n");
    }
}

int dequeue() {
    if (!isEmpty()) {
        int val = queue[front];
        if (rear == front) {
            rear = front = -1;
        } else {
            front++;
        }
        return val;
    }
    return -1;
}

void display() {
    if (isEmpty()) {
        printf("\nQueue is Empty!\n");
        return;
    }

    printf("\nQueue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    intialize();
    int choice, data, result;

    while (1) {
        printf("\n\n----- Queue Menu -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data to enqueue: ");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            result = dequeue();
            if (result != -1)
                printf("Dequeued data: %d\n", result);
            else
                printf("Queue is Empty!\n");
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
