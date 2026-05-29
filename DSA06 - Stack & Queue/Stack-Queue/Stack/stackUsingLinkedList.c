#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int data;
    struct Stack *next;
} Stack;

Stack* push(Stack *stack, int data) {
    Stack *newNode = (Stack*) malloc(sizeof(Stack));
    newNode->data = data;
    newNode->next = stack;
    return newNode;
}

Stack* pop(Stack *stack) {
    if (stack == NULL) {
        printf("Stack is Empty !!!\n");
        return stack;
    }
    Stack *temp = stack;
    stack = stack->next;
    printf("\nPopped element : %d\n", temp->data);
    free(temp);
    return stack;
}

void display(Stack *stack) {
    if (stack == NULL) {
        printf("Stack is Empty\n");
        return;
    }
    Stack *temp = stack;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack *stack = NULL;
    int choice, data;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                stack = push(stack, data);
                break;
            case 2:
                stack = pop(stack);
                break;
            case 3:
                display(stack);
                break;
            case 4:
                printf("Exiting...\n");
                // Free remaining stack nodes before exit (optional)
                while (stack != NULL) {
                    stack = pop(stack);
                }
                return 0;
            default:
                printf("Invalid choice, try again.\n");
        }
    }
}
