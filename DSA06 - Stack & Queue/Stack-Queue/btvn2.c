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
int fitchar(char a, char b) {
    if (a==40 && b==41) return 1;
    else if (a==91 && b==93) return 1;
    else if (a==123 && b==125) return 1;
    return 0;
}
int main() {
    stack st;
    initStack (&st);
    char str[MAX];
    fgets(str, MAX, stdin);
    //Xoa ki tu xuong dong \n
    str[strcspn(str,"\n")] = '\0';
    int count = 0, b[100]={0};
    int len = strlen(str);
    for (int i=0; i<len; i++) {
        if (str[i]==40 || str[i]==91 || str[i]==123) {
            push(&st, str[i]);
        }
        else if (str[i]==41 || str[i]==93 || str[i]==125) {
            if (isEmpty(&st)) {
                printf("Khong hop le\n");
                return 0;
            }
            char topChar = pop(&st);
            if (!fitchar(topChar, str[i])) {
                count++;
                b[count-1] = i;
                if (topChar==40) {
                    str[i] = 41;
                }
                else if (topChar==91) {
                    str[i] = 93;
                }
                else if (topChar==123) {
                    str[i] = 125;
                }
            }
        }
    }
    if (count==0 && isEmpty(&st)) {
        printf("No error.\n");
        return 0;
    }
    printf("Error at");
    for (int i=0; i<count; i++) printf(" %d", b[i]);
    printf("\n");
    for (int i=0; i<len; i++) printf("%c", str[i]);
    return 0;
}
