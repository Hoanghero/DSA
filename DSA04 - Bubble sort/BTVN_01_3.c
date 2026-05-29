#include <stdio.h>
#include <time.h>
#include <stdlib.h>
typedef struct boBa
{
    float x;
    float y;
    float z;
} boBa;
void swap(boBa *a, boBa *b) {
    boBa temp = *a;
    *a = *b;
    *b = temp;
}
float F(boBa a) {
    return a.x-2*a.y+3*a.z;
}
void sinhMang(boBa *a, int n, float min, float max) {
    for (int i = 0; i < n; i++) {
        a[i].x = min + ((float)rand() / RAND_MAX) * (max - min);
        a[i].y = min + ((float)rand() / RAND_MAX) * (max - min);
        a[i].z = min + ((float)rand() / RAND_MAX) * (max - min);
    }
}
void bubbleSort(boBa *arr, int n) {
    for (int i=0; i<n; i++) {
        for (int j=n-1; j>i; j--) {
            if (F(arr[j-1]) > F(arr[j])) swap(&arr[j-1], &arr[j]);
        }
    }
}
int main() {
    time_t t;
    srand((unsigned)time(&t));
    int n;
    scanf("%d", &n);
    boBa a[100];
    sinhMang(a, n, -200, 200);
    printf("Mang ban dau:\n");
    for (int i=0; i<n; i++) {
        printf("[%.2f,  %.2f,  %.2f]\n", a[i].x, a[i].y, a[i].z);
    }
    printf("\n");
    bubbleSort(a, n);
    printf("Sau khi sap xep:\n");
    for (int i=0; i<n; i++) {
        printf("[%.2f,  %.2f,  %.2f] tuong ung F la %.2f\n", a[i].x, a[i].y, a[i].z, F(a[i]));
    }
    return 0;
}
