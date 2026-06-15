#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 100

// Dinh nghia stack
typedef struct {
    int data[MAX];
    int top;
} stack;

// Khoi tao stack
void initStack(stack *s) {
    s->top = -1;
}

// Kiem tra stack rong
int isEmpty(stack *s) {
    return s->top == -1;
}

// Kiem tra stack day
int isFull(stack *s) {
    return s->top == MAX - 1;
}

int top(stack *s) {
    if (isEmpty(s)) return -1;
    return s->data[s->top];
}

// Them phan tu (push)
void push(stack *s, int c) {
    if (isFull(s)) {
        printf("Stack da day, khong the them.\n");
        return;
    }
    s->top++;
    s->data[s->top] = c;
}

int pop(stack *s) {
    if (isEmpty(s)) {
        return -1;
    }
    int poppedChar = s->data[s->top];
    s->top--;
    return poppedChar;
}

int sinh(int min, int max) {
    return min + rand() % (max - min + 1);
}

void insertStack(stack *s, int *count, int k) {
    (*count)++; // Tang bien dem ngay khi vao ham
    
    // ĐIỀU KIỆN DỪNG: Stack rỗng hoặc Stack đã đầy không thể thao tác thêm
    if (isEmpty(s) || isFull(s)) {
        return;
    }

    // Truong hop k = 1 hoac k = 10: Xóa một nửa số phần tử hiện tại
    if (k == 1 || k == 10) {
        int so_luong_hien_tai = s->top + 1;
        int sl = so_luong_hien_tai / 2;
        if (sl == 0) sl = 1; // Đảm bảo có xóa ít nhất 1 phần tử nếu stack còn ít
        
        for (int t = 0; t < sl; t++) {
            pop(s);
        }
        
        k = sinh(1, 10);
        printf("Sinh lai k (do k=%d) -> k moi = %d\n", k, k); // Đã sửa lỗi printf
        return insertStack(s, count, k);
    }
    // Truong hop k le va k != 1
    else if (k % 2 != 0) {
        pop(s);
        k = sinh(1, 10);
        printf("Sinh lai k (do k le) -> k moi = %d\n", k); // Đã sửa lỗi printf
        return insertStack(s, count, k);
    }
    // Truong hop k chan va k != 10
    else {
        push(s, k);
        k = sinh(1, 10);
        printf("Sinh lai k (do k chan) -> k moi = %d\n", k); // Đã sửa lỗi printf
        return insertStack(s, count, k);
    }
}

int main() {
    srand((unsigned) time(NULL));
    int a[100] = {2, 5, 7}, count = 0;
    stack s;
    initStack(&s);
    
    // Nạp dữ liệu ban đầu vào stack
    for (int i = 0; i < 3; i++) {
        push(&s, a[i]);
    }
    
    int k = sinh(1, 10);
    printf("Gia tri k ban dau = %d\n", k);
    
    insertStack(&s, &count, k);
    
    printf("\n--- KET QUA ---\n");
    printf("So lan goi ham insertStack: %d\n", count);
    
    return 0;
}