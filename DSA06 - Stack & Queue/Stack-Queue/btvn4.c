#include <stdio.h>
typedef struct {
    int head, tail;
    int a[100];
} Queue;

void init(Queue* q) {
    q->head = 0;
    q->tail = -1;
}
int isEmpty(Queue *q) {
    return q->tail == -1;
}
void put(Queue* q, int value) {
    q->tail++;
    q->a[q->tail] = value;
}
int get(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue rong! Khong the lay phan tu.\n");
        return -1; 
    }
    int temp = q->a[q->head];
    q->head++;
    if (q->head > q->tail) {
        q->head = 0;
        q->tail = -1;
    }
    return temp;
}
int stt(Queue *q, int y) {
    for (int i=q->head; i<q->tail; i++) {
        if (q->a[i]==y) return i;
    }
    return -1;
}
void cancelRegistration(Queue *q, int index, int *t) {
    if (index==-1) {
        printf("Co imposter trong hang doi");
        return;
    }
    for (int i=index; i<*t-1; i++) {
        q->a[i] = q->a[i+1];
    }
    q->tail--;
    (*t)--;
}
void displayQueue(Queue*q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->head; i <= q->tail; i++) {
        printf("%d ", q->a[i]);
    }
    printf("\n");
}
int main() {
    Queue q;
    init(&q);
    int num[100], x=1, t=0;
    printf("Nhan 1 de dang ki moi, 2 de huy slot, 3 de xem thong tin nguoi dau danh sach, 0 de ket thuc.\n");
    while (x!=0) {
        scanf("%d", &x);
        if (x==1) {
            printf("So bao danh cua ban la: ");
            scanf("%d", &num[t]);
            put(&q,num[t]);
            displayQueue(&q);
            printf("\n");
            t++;
        }
        else if (x==2) {
            int y, z;
            printf("So bao danh cua ban: ");
            scanf("%d", &y);
            z = stt(&q, y);
            cancelRegistration(&q, z, &t);
            displayQueue(&q);
            printf("\n");
        }
        else if (x==3){
            printf("Nguoi dau tien: %d\n", get(&q));
            displayQueue(&q);
            printf("\n");
        }
        else return 0;
    }
}