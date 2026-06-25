#include <stdio.h>

#include <time.h>

#include <stdlib.h>

#define MAX 100

// Dinh nghia stack

typedef struct {

    int data[MAX];

    int top;

} stack;


//Khoi tao stack

void initStack(stack *s) {

    s->top=-1;

}


//Kiem tra stack rong

int isEmpty(stack *s) {

    return s->top==-1;

}


//Kiem tra stack day

int isFull(stack *s) {

    return s->top == MAX-1;

}

int top(stack *s) {

    int stacktop = s->data[s->top];

    return stacktop;

}

//Them phan tu (push)

void push(stack *s, int c) {

    if (isFull(s)) {

        printf("Stack da day, khong the them.\n");

        return;

    }

    s->top++;

    s->data[s->top]=c;

}

int pop(stack *s) {

    if (isEmpty(s)) {

        return -1;

    }

    int poppedChar = s->data[s->top];

    s->top--;

    return poppedChar;

}

int gen(int min, int max) {

    int k = (int) (min + rand() % (max - min + 1));

    return k;

}

void insertStack(stack *s, int *count, int k) {

    if (isEmpty(s)) {

        (*count)++;

        return;

    }

    if (k%2!=0 && k!=1) {

        pop(s);

        k = gen(1,10);

        printf("k = %d\n", k);

        (*count)++;

        return insertStack(s, count, k);

    }

    if (k%2==0 && k!=10) {

        push(s, k);

        k = gen(1,10);

        printf("k = %d\n", k);

        (*count)++;

        return insertStack(s, count, k);

    }

    if (k==1 || k==10) {

        int sl;

        if ((s->top+1)%2==0) sl = (s->top+1)/2;

        else sl = (s->top-1)/2;

        for (int t=0; t<sl; t++) pop(s);

        k = gen(1,10);

        printf("k = %d\n", k);

        (*count)++;

        return insertStack(s, count, k);

    }

}

int main() {

    srand((unsigned) time(NULL));

    int a[100] = {2,5,7}, count = 0;

    stack s;

    initStack (&s);

    for (int i=0; i<3; i++) {

        push(&s, a[i]);

    }

    int k = gen(1,10);

    printf("k = %d\n", k);

    insertStack(&s, &count, k);

    printf("So lan goi ham insertStack: %d\n", count);

    return 0;

}