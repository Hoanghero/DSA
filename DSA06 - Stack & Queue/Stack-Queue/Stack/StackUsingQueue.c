#include<stdio.h>
#define MAX 100
typedef struct Queue{
    int arr[MAX];
    int rear , front;
}Queue;

void intialize(Queue *queue){
    queue->rear = queue->front = -1;
}


int isFull(Queue *queue){
    return queue->rear == MAX - 1;
}

int isEmpty(Queue *queue){
    return queue->front == -1;
}

void enqueue(Queue *queue , int data){
    if(!isFull(queue)){
        if(queue->rear == -1){
            queue->rear = queue->front = 0;
            queue->arr[queue->rear] = data;
            return ;
        }
        queue->rear++;
        queue->arr[queue->rear] = data;
        return;
    }

}

int dequeue(Queue *queue){
    int data;
    if(!isEmpty(queue)){
        if(queue->rear == queue->front){
            data = queue->arr[queue->front];
            queue->rear = queue->front = -1;
            return data;
        }
        data =  queue->arr[queue->front];
        queue->front++;
        return data;
    }
}

void display(Queue *queue){
    if(isEmpty(queue)) {
        printf(" is Emtpty !!!");
        return;
    }
    for(int i = queue->front ; i <= queue->rear ; i++){
        printf("%d ", queue->arr[i]);
    }
}

void push(Queue *queue1, Queue *queue2 , int data){ 
    if(isFull(queue1)){
        printf("\nStack is Full !!! Cannot Push the Elements !!!");
        return;
    }
    while(!isEmpty(queue1)){
        enqueue(queue2, dequeue(queue1));
    }
    if(isEmpty(queue1)){
        enqueue(queue1,data);
    }
    while(!isEmpty(queue2)){
        enqueue(queue1,dequeue(queue2));
    }
    return;
}

void pop(Queue *queue){

    if(isEmpty(queue)){
        printf("\nStack is Empty !!! Cannot Popped the Elements !!!");
        return;
    }
    int popped = dequeue(queue);
    printf("\nPopped element is : %d", popped);
    return;
}



int main(){

    Queue queue1,queue2;
    int ch, data ;
    intialize(&queue1);
    intialize(&queue2);



    while(1){
        printf("\n1. Push Element");
        printf("\n2. Pop element ");
        printf("\n3.print Element ");
        printf("\n4. Exit");

        printf("\n\nEnter Your Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the data to push into stack : ");
            scanf("%d",&data);
            push(&queue1,&queue2,data);
            break;

        case 2 : 
            pop(&queue1);
            break;
        case 3:
            printf("\nStack : ");
            display(&queue1);
            break;
        case 4 : 
            return 0;

        default:
            printf("Enter the Valid Choice !!!!!");
            break;
        }
    }


}