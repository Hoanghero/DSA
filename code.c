#include <stdio.h>
#include <stdbool.h>
#define MAX 100

typedef struct Stack {
    int a[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

bool isFull(int top) {
    return top == MAX - 1;
}

bool isEmpty(int top) {
    return top == -1;
}

void display(Stack *s) {
    if (!isEmpty(s->top)) {
        printf("Stack Elements are:");
        for (int i = 0; i <= s->top; i++) {
            printf(" %d", s->a[i]);
        }
        printf("\n");
    } else {
        printf("Stack is Empty\n");
    }
    printf("\n");
}

void push(Stack *s, int v) {
    printf("pushs: %d\n", v);
    if (!isFull(s->top)) {
        s->top++;
        s->a[s->top] = v;
        display(s);
    } else {
        printf("Stack is Full\n");
    }
}

int pop(Stack *s) {
    printf("Popped: %d\n", s->a[s->top]);
    if (!isEmpty(s->top)) {
        s->top--;
        // return s->a[s->top--];
        display(s);
    }
    else printf("Stack is Empty\n");
    return -1;
}



int main() {
    Stack s;
    init(&s);
    int num[6] = {1, -2, 3, -4, 5, -6};
    for (int i = 0; i < 6; i++)
    {
        push(&s, num[i]);
    }
    pop(&s);
    return 0;
}
