#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

typedef struct Node {
    int data;
    struct Node* next;// Cần có chữ 'struct' ở đây vì đang báo đệ quy; Node bao gom du lieu va tro vao Node ke tiep
} Node;

// Struct đại diện cho cấu trúc Queue
typedef struct Queue {
    Node* front;
    Node* back;
} Queue;

// 1. Hàm khởi tạo Queue rỗng
void initQueue(Queue* q) {
    q->front = NULL;
    q->back = NULL;
}
// 2. Hàm kiểm tra Queue rỗng
bool isEmpty(Queue* q) {
    return (q->front == NULL);
}
// 3. Hàm thêm phần tử (Enqueue)
void enqueue(Queue* q, int value) {
    // Cấp phát bộ nhớ cho node mới bằng malloc
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Loi cap phat bo nho!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    // Nếu Queue rỗng
    if (isEmpty(q)) {
        q->front = newNode;
        q->back = newNode;
        return;
    }
    // Nếu Queue đã có phần tử
    q->back->next = newNode;
    q->back = newNode;
}

// 4. Hàm lấy và xóa phần tử (Dequeue)
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue rong! Khong the lay phan tu.\n");
        return -1; // Giá trị trả về khi lỗi
    }

    Node* temp = q->front;
    int data = temp->data;

    q->front = q->front->next;

    if (q->front == NULL) {
        q->back = NULL;
    }

    free(temp); // Giải phóng bộ nhớ trong C bằng free
    return data;
}

// 5. Hàm xem phần tử ở đầu hàng (Peek)
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue rong!\n");
        return -1;
    }
    return q->front->data;
}
int main() {
    int a[100], n, k;
    printf("Nhap n: ");
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Nhap so k: ");
    scanf("%d", &k);
    Queue hangdoi;
    initQueue(&hangdoi);
    for (int i=0; i<n; i++) {
        enqueue(&hangdoi, a[i]);
    }
    for (int i=0; i<k; i++) {
        int b = dequeue(&hangdoi);
        enqueue(&hangdoi, b);
    }
    while (!isEmpty(&hangdoi)) {
        int c = peek(&hangdoi);
        printf("%d ", c);
        dequeue(&hangdoi);
    }
    return 0;
}
