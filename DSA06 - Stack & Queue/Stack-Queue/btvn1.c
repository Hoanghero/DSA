#include <stdio.h>
#include <string.h>
// Nhap vao mot chuoi ki sau do in ra reverse cua no
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

//Them phan tu (push)
void push(stack *s, char c) {
    if (isFull(s)) {
        printf("Stack da day, khong the them.\n");
        return;
    }
    s->top++;
    s->data[s->top]=c;
}
char pop(stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    char poppedChar = s->data[s->top];
    s->top--;
    return poppedChar;
}
int main() {
    stack st;
    initStack (&st);
    char str[MAX];

    printf("Nhap vao chuoi: ");
    fgets(str, MAX, stdin);
    //Xoa ki tu xuong dong \n
    str[strcspn(str,"\n")] = '\0';

    int len = strlen(str);
    for (int i=0; i<len; i++) {
        push(&st, str[i]);
    }
    for (int i=0; i<len; i++) {
        str[i] = pop(&st);
    }

    printf("Chuoi dao nguoc: ");
    puts(str);
    
    return 0;
}
