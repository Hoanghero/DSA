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
void swap(char* a, char* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void copyArray(char src[], char dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}
void normal(char *s, int n) {
    int l=0, r=n-1;
    while(l<r) {
        swap(&s[l], &s[r]);
        l++;
        r--;
    }
}
int main() {
    stack st;
    initStack (&st);
    char str[MAX], str1[MAX];
    scanf("%s", str);
    int len = strlen(str);
    copyArray(str, str1, len);
    normal(str1, len);
    for (int i=0; i<len; i++) {
        push(&st, str[i]);
    }
    for (int i=0; i<len; i++) {
        str[i] = pop(&st);
    }
    puts(str1);
    puts(str);
    printf("Cach dung stack toi uu bo nho hon thong thuong");
    return 0;
}
