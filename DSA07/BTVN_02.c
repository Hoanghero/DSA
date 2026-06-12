#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAXN 20

const int MIN = -1e2;
const int MAX = 1e2;

void Irandom(int a[], int n, int min, int max){
    for (int i=0; i<n;i++){
        a[i]= min + rand() % (max - (n - i - 1) - min + 1);
        min = a[i]+1;
    }
}

typedef struct Stack
{
    int a[MAXN];
    int top;
} stack;

typedef struct Queue
{
    int a[MAXN];
    int head, tail;
} queue;

void ham1(int a[], int n, int id)
{
    if (id == n) return;
    printf("%d ", a[id]);
    ham1(a, n, id + 1);
}

void check1(int a[], int n)
{
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

int ham2(int a[], int n, int id, int x)
{
    if (id == n) return -1;
    if (a[id] == x) return id;
    return ham2(a, n, id + 1, x);
}

int check2(int a[], int n, int x)
{
    for (int i = 0; i < n; i++) if (a[i] == x) return i;
    return -1;
}

stack s;

void ham3a(stack* s)
{
    if (s->top == -1) return;
    printf("%d ", s->a[s->top--]);
    ham3a(s);
}

void check3a(stack* s)
{
    while(s->top != -1) printf("%d ", s->a[s->top--]);
}

queue q;

void ham3b(queue* q)
{
    if (q->head >= q->tail) return;
    printf("%d ", q->a[q->head++]);
    ham3b(q);
}

void check3b(queue *q)
{
    while(q->head < q->tail) printf("%d ", q->a[q->head++]);
}

int ham4(int a[], int l, int r, int x)
{
    if (l > r) return -1;
    int m = (l + r) / 2;
    if (a[m] == x) return m;
    else if (a[m] > x) return ham4(a, l, m - 1, x);
    else return ham4(a, m + 1, r, x);
}

int check4(int a[], int n, int x)
{
    int l = 0, r = n - 1;
    while(l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] == x) return m;
        else if (a[m] > x) r = m - 1;
        else l = m + 1;
    }
    return -1;
}
void insertionSort (int arr[],int n) {
    int key;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        int j = i - 1;

        while (j >= 0) {
            if (arr[j] > key) {
                arr[j+1] = arr[j];
                j--;
            }
            else {
                break;
            }    
        }
        arr[j+1] = key;
    }
}
int main()
{
    time_t t;
    srand((unsigned) time (&t));
    int n; scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    //Bai1
    printf("Bai 1\n");
    printf("In mang bang de quy:\n");
    ham1(a, n, 0);
    printf("\n");
    printf("In mang bang vong lap for:\n");
    check1(a, n);
    printf("\n");
    //Bai2
    printf("Bai 2\n");
    int x; scanf("%d", &x);
    printf("Chi so cua phan tu bang de quy: ");
    printf("%d\n", ham2(a, n, 0, x));
    printf("Chi so cua phan tu bang vong lap for: ");
    printf("%d\n\n", check2(a, n, x));
    //Bai3a
    printf("Bai 3a\n");
    s.top = -1;
    for (int i = 1; i <= MAXN; i++) s.a[++s.top] = i;
    printf("Phan tu duoc xoa bang de quy: ");
    ham3a(&s);
    printf("\n");
    for (int i = 1; i <= MAXN; i++) s.a[++s.top] = i;
    printf("Phan tu duoc xoa vong lap: ");
    check3a(&s);
    printf("\n\n");
    //Bai3b
    printf("Bai 3b\n");
    q.head = q.tail = -1;
    for (int i = 1; i <= MAXN; i++) q.a[q.tail++] = i;
    printf("Phan tu duoc xoa bang de quy: ");
    ham3b(&q);
    printf("\n");
    q.head = q.tail = -1;
    for (int i = 1; i <= MAXN; i++) q.a[q.tail++] = i;
    printf("Phan tu duoc xoa bang vong lap: ");
    check3b(&q);
    printf("\n\n");
    //Bai4
    printf("Bai 4\n");
    insertionSort(a, n);
    int v; scanf("%d", &v);
    printf("Mang ban dau la: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    printf("Phan tu can tim la: %d\n", v);
    printf("Chi so cua phan tu can tim bang de quy: ");
    printf("%d\n", ham4(a, 0, n, v));
    printf("Chi so cua phan tu can tim bang vong lap: ");
    printf("%d\n", check4(a, n, v));
    return 0;
}