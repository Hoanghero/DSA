#include <stdio.h>
#define MAX 100

typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

void intialize(Stack *s) {
    s->top = -1;
}

int isFull(int top) {
    return top == MAX - 1;
}

int isEmpty(int top) {
    return top == -1;
}

void push(Stack *s, int data) {
    if (!isFull(s->top)) {
        s->top++;
        s->arr[s->top] = data;
    } else {
        printf("Stack is Full\n");
    }
}

int pop(Stack *s) {
    if (!isEmpty(s->top)) {
        return s->arr[s->top--];
    }
    printf("Stack is Empty\n");
    return -1;
}

void display(Stack *s) {
    if (!isEmpty(s->top)) {
        printf("\nStack Elements are:");
        for (int i = 0; i <= s->top; i++) {
            printf(" %d", s->arr[i]);
        }
        printf("\n");
    } else {
        printf("Stack is Empty\n");
    }
}

int main() {
    Stack s;
    intialize(&s);
    int choice, data, popped;

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
            push(&s, data);
            break;
        case 2:
            popped = pop(&s);
            if (popped != -1)
                printf("Popped element is: %d\n", popped);
            break;
        case 3:
            display(&s);
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
