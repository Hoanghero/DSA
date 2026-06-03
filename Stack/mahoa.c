#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct {
    int data[MAX];
    int top;
} Stack;
void initiStack(Stack *s) {
    s->top=-1;
}
int isEmpty(Stack *s) {
    return s->top == -1;
}
char top(Stack *s) {
    int stacktop = s->data[s->top];
    return stacktop;
}
void push(Stack *s, char c) {
    s->top++;
    s->data[s->top] = c;
}
void pop(Stack *s) {
    s->data[s->top] = '\0';
    s->top--;
}
int main() {
    Stack st;
    initiStack(&st);
    char s[100];
    fgets(s, 99, stdin);
    s[strcspn(s,"\n")] = '\0';
    int len = strlen(s);
    char str[100];
    for (int i=0; i<=len; i++) {
        if (isEmpty(&st)||top(&st)==s[i]) {
            push(&st, s[i]);
        }
        else {
            //Nhap thong tin vao chuoi xuat man hinh
            int count = 0;
            int u=0;
            while (str[u]!='\0') {
                u++;
            }
            str[u] = top(&st);
            str[u+1] = '\0';
            while (!isEmpty(&st)) {
                count++;
                pop(&st);
            }
            char c = count +'0';
            int j=0;
            while(str[j] != '\0') {
                j++;
            }
            str[j] = c;
            str[j+1] = '\0';
            //tiep tuc push doan moi
            push(&st, s[i]);
        }
    }
    puts(str);
    return 0;
}