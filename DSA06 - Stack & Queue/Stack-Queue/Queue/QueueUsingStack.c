#include<stdio.h>
#define MAX 100
typedef struct Stack {
    int arr[MAX];
    int top;
}Stack;

void initialize(Stack *stack){
    stack->top = -1;
}

int isEmpty(Stack *stack){
    return stack->top == -1;
}

int isFull(Stack *stack){
    return stack->top == MAX - 1;
}

void push(Stack *stack , int data){
    if(!isFull(stack)){
        stack->top ++;
        stack->arr[stack->top] = data;
        return;
    }
    // printf("\n\nStack is Empty ....");
}


int pop(Stack *stack){
    if(!isEmpty(stack)){
        return stack->arr[stack->top--];
    }
    return -1;
    // printf("\n\nStack is Empty");
}

void display(Stack *stack){
    printf("\nQueue (Front to Rear): ");
    for(int i = 0; i <= stack->top ; i++){
        printf("%d ", stack->arr[i]);
    }
}


void enqueue(Stack *stack1 , Stack *stack2 , int data){

    if(isFull(stack1)){
        printf("Queue is Full !!! Cannot enqueue Element !!!");
        return;
    }
    while(!isEmpty(stack1)){
        push(stack2,pop(stack1));
    }
    if(isEmpty(stack1)){
        push(stack1,data);
    }
    while(!isEmpty(stack2)){
        push(stack1,pop(stack2));
    }
    return;
}

void dequeue(Stack *stack){
    if(isEmpty(stack)) {
        printf("\n Queue is Empty !!!! Cannot dequeue the element !!");
        return;
    }
    int popped = pop(stack);
    printf("\ndequeued Element : %d", popped);
    return;
}

int main(){

    Stack stack1, stack2;
    initialize(&stack1);
    initialize(&stack2);

    int ch , data;

    while(1){
        printf("\n1. Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Display");
        printf("\n4.Exit");

        printf("\nEnter Your Choice : ");
        scanf("%d",&ch);
        

        switch (ch)
        {
        case 1:
            printf("\nEnter data to Enquue : ");
            scanf("%d",&data);
            enqueue(&stack1, &stack2 , data);
            break;
        
        case 2:
            dequeue(&stack1);
            break;
        case 3:
            printf("\nQueue : ");
            display(&stack1);
            break;
        case 4:
            return 0;
        default:
            break;
        }
    }
    return 0;
}