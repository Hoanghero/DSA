#include <stdio.h>
#include <string.h>
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
int isNC(char a) {
    return ((a==42 || a==47));
}
int isnumber(char a) {
    return (a>=48 && a<=57);
}
int caculate(char *s) {
    int len = strlen(s);
    // Dùng mảng để mô phỏng tạm Stack. Kích thước tối đa bằng chiều dài chuỗi.
    int *stack = (int *)malloc(len * sizeof(int)); 
    int top = -1; 
    int x = 0;
    char dau = '+'; // Dấu mặc định trước số đầu tiên
    // Duyệt đến len (bao gồm cả ký tự '\0' kết thúc chuỗi)
    for (int i = 0; i <= len; i++) {
        char c = s[i];
        if (isnumber(c)) {
            x = x * 10 + (c - '0');
        }
        // Nếu là toán tử hoặc là ký tự kết thúc chuỗi '\0'
        if ((!isnumber(c) && c != ' ') || c == '\0') {
            if (dau == '+') {
                stack[++top] = x; // Push
            } 
            else if (dau == '-') {
                stack[++top] = -x; // Push số âm
            } 
            else if (dau == '*') {
                stack[top] = stack[top] * x; // Lấy đỉnh stack nhân rồi ghi đè lại
            } 
            else if (dau == '/') {
                stack[top] = stack[top] / x; // Chia lấy nguyên theo chuẩn C
            }
            dau = c;
            x = 0;
        }
    }
    // Kết quả là tổng của tất cả phần tử trong stack
    int result = 0;
    for (int i = 0; i <= top; i++) {
        result += stack[i];
    }
    free(stack); 
    return result;
}
int main() {
    stack stdau, stkq;
    initStack (&stdau);
    initStack (&stkq);
    char str[MAX];
    fgets(str, MAX, stdin);
    //Xoa ki tu xuong dong \n
    str[strcspn(str,"\n")] = '\0';
    int len = strlen(str);
    for (int i=0; i<len; i++) {
        if (str[i]>=48 && str[i]<=57) {
            push(&stkq, str[i]);
        }
        else {
            if (isEmpty(&stdau)) push(&stdau, str[i]);
            else {
                if (!isNC(str[i])) {
                    while (!isEmpty(&stdau)) {
                        char x = pop(&stdau);
                        push(&stkq, x);
                    }
                    push(&stdau, str[i]);
                }
                else {
                    while (isNC(stdau.data[stdau.top])) {
                        char x = pop(&stdau);
                        push(&stkq, x);
                    }
                    push(&stdau, str[i]);
                }
            }
        }
        if ((i==len-1) && (!isEmpty(&stdau))) {
            while (!isEmpty(&stdau)) {
                char x = pop(&stdau);
                push(&stkq, x);
            }
        }
    }
    for (int i=0; i<len; i++) printf("%c", stkq.data[i]);
    printf("\n");
    printf("Result = %d", caculate(str));
}