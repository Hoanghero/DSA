#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAXN 20

typedef struct Stack
{
    int a[MAXN];
    int top;
} stack;

stack s;

void createbox(stack* s)
{
    int v; 
    if (s->top == MAXN - 1) return;
    if (s->top == MAXN - 2) v = 1;
    else v = 1 + rand() % 10;
    if (s->top != MAXN - 1) 
    {
        printf("%d ", v);
        s->a[++s->top] = v;
    }
    if (v == 1) return;
    else createbox(s);
}

//BASE CASE 1: Xay ra khi s->top = MAXN - 1, tuc la khi hang doi da day
//OUTPUT OF BASE CASE 1: Dung qua trinh tao hop
//BASE CASE 2: Xay ra khi v = 1, tuc la khi xuat hien the danh so 1
//OUTPUT OF BASE CASE 2: Dung qua trinh tao hop
//BEFORE BASE CASE: Xay ra khi s->top = MAXN - 2, sinh ngau nhien phan tu roi day vao stack
//BEFORE BEFORE BASE CASE: Xay ra khi s->top = MAXN - 3, sinh ngau nhien phan tu sau do day vao stack

int sumbox(stack* s, int sum)
{
    if (s->top == -1) return sum;
    sum += s->a[s->top--];
    
    return sumbox(s, sum);
}

//BASE CASE: Xay ra khi s->top = -1
//OUTPUT OF BASE CASE: Tra ve sum la tong cua cac so trong hop
//BEFORE BASE CASE: Xay ra khi s->top = 0, Tra ve sum la tong cua cac so o vi tri thu 2 den vi tri cuoi cung
//BEFORE BASE CASE: Xay ra khi s->top = 1, Tra ve sum la tong cua cac so o vi tri thu 3 den vi tri cuoi cung trong hop

int main()
{
    time_t t;
    srand((unsigned) time (&t));
    s.top = -1;
    printf("Cac so trong hop: ");
    createbox(&s);
    printf("\nTong cac so trong hop: %d", sumbox(&s, 0));

    return 0;
}