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
void sortGiamDan(int a[], int n) // insertion sort
{
    for (int i = 1; i < n; i++) //duyet qua tung phan tu trong mang
    {
        int tmp = a[i]; // gan bien tam 
        int id = 0; // khai bao chi so
        for (int j = i - 1; j >= 0; j--) // duyet qua cac phan tu truoc do de tim vi tri thich hop
        {
            if (a[j] < tmp) a[j+1] = a[j]; //so sanh va hoan doi vi tri neu phan tu truoc do nho hon phan tu dang xet
            else //xac dinh vi tri thich hop
            {
                id = j + 1; 
                break;
            }
        }
        a[id] = tmp; //chen phan tu
    }
}
int minIndex(int sum[], int k) {
    int mini = sum[0], index=0;
    for (int i=0; i<k; i++) {
        if (sum[i]<mini) {
            mini = sum[i];
            index = i;
        }
    }
    return index;
}
int maxi(int sum[], int k) {
    int bebu = sum[0];
    for (int i=0; i<k; i++) {
        if (sum[i]>bebu) bebu = sum[i];
    }
    return bebu;
}
/*
Ý tưởng:
1. Đầu tiên sắp xếp cho mảng thời gian qua cầu của mỗi người theo thứ tự giảm dần, mục đích cho những người đi chậm
đi chung đầu tiên để tối ưu thời gian qua cầu.
2. Thiết lập k Queue, mỗi Queue quy định thứ tự khi một người trước đó vừa đi xong thì người tiếp theo là ai. Mỗi Queue
tương ứng có một sum thể hiện tổng thời gian qua cầu của Queue đó.
Ví dụ: Queue ban đầu có người 9 phút, phải đợi hết 9 phút này đi qua thì người 3 phút mới lên cầu. Lúc này sum là 9+3=12
3. Duyệt từng phần tử trong mảng thời gian qua cầu, xem Queue nào có sum nhỏ nhất thì put vào. Vì khi k người cùng đi
trên cầu thì người có thời gian đi ít nhất sẽ xong trước, sau đó phải cho người có thời gian đi có giá trị kế tiếp đó lên cầu
Ví dụ: Mảng sau khi xếp giảm là [9,7,6,5,3,3,2,1]. Cho 9 7 6 lên cầu tương ứng 9 vào Queue 1, 7 Queue 2, 6 Queue 3,
sau 6 phút thì cho người 5 lên, tức là Queue 3 đang có sum nhỏ nhất nên cho 5 vào. Sau đó thì Queue 2 đang có sum là 7 là
nhỏ nhất (9,7,11) thì put 3 vào. Cứ tiếp tục quá trình.
*/
int main() {
    int num[100], k, n;
    scanf("%d", &k);
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &num[i]);
    sortGiamDan(num, n);
    Queue q[10];
    int sum[10] = {0};
    for (int i=0; i<k; i++) init(&q[i]);
    for (int i=0; i<n; i++) {
        int x = minIndex(sum, k);
        put(&q[x], num[i]);
        sum[x] += num[i];
    }
    printf("%d\n", maxi(sum, k));
    for (int i=0; i<k; i++) {
        int j=0;
        while (q[i].a[j] != 0) {
            printf("%d ", q[i].a[j]);
            j++;
        }
        printf("=> %d\n", sum[i]);
    }
    return 0;
}