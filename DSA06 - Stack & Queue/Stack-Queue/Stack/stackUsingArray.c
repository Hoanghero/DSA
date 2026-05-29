#include <stdio.h>
#define MAX 100

int Stack[MAX], top;

void intialize() {
    top = -1;
}

int isFull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int data) {
    if (!isFull()) {
        Stack[++top] = data;
    } else {
        printf("Stack is Full. Cannot Insert.\n");
    }
}

int pop() {
    if (!isEmpty()) {
        return Stack[top--];
    } else {
        printf("Stack is Empty. Cannot Pop.\n");
        return -1;
    }
}

void display() {
    if (isEmpty()) {
        printf("Stack is Empty.\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", Stack[i]);
    }
    printf("\n");
}

int main() {
    intialize();
    int choice, data;

    while (1) {
        printf("\n\n--- Stack Menu ---");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data to push: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            data = pop();
            if (data != -1)
                printf("Popped: %d\n", data);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
