#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sinhMang(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
}
void bubbleSort(int arr[], int n, int *comps, int *swaps) 
{
    for (int i=0; i<n; i++) {
        for (int j=n-1; j>i; j--) {
            (*comps)++;
            if (arr[j-1] > arr[j]) {
                (*swaps)++;
                swap(arr+j-1, arr+j);
            }
        }
    }
}
float trungBinhCong(int arr[], int n, int m) {
    float tong = 0;
    for (int i = 0; i < n; i++) {
        tong += (float)(i * arr[i]);
    }
    return tong/m;
}
int main() {
    time_t t;
    srand((unsigned)time(&t));
    int k[] ={100, 1000, 10000};
    int arr[100];
    for (int i=0; i<3; i++) {
        int danhDaucomps[1001] = {};
        int danhDauswaps[1001] = {};
        for (int j=0; j<k[i]; j++) {
            int comps=0, swaps=0;
            sinhMang(arr, 10, -1000, 1000);
            bubbleSort(arr, 10, &comps, &swaps);
            danhDaucomps[comps]++;
            danhDauswaps[swaps]++;
        }
        printf("n = %d, k = %d\n", 10, k[i]);
        printf("Mean comps = %.2f\n", trungBinhCong(danhDaucomps, 1001, k[i]));
        printf("Mean swaps = %.2f\n", trungBinhCong(danhDauswaps, 1001, k[i]));
        printf("-----------------\n");
    }
    return 0;
}