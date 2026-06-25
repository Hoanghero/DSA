#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(float *a, float *b){
    float temp=*a;
    *a=*b;
    *b=temp;
}
void sort(float *arr, int n, int *comps) {
    (*comps) = 0;
    for (int i=0; i<n; i++) {
        int min_idx = i;
        for (int j=i+1; j<n; j++) {
            (*comps)++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) swap(&arr[min_idx],&arr[i]);
    }
}
void sinhMang(float arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min + rand() % (max - min + 1);
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
    float arr[100];
    int n=40;
    int k[] ={100, 1000};
    for (int i = 0; i < 2; i++) {
        int danhDau[1000] = {};
        for (int j=0; j<k[i]; j++) {
            int comps = 0;
            sinhMang(arr, n, 0, 10);
            sort(arr,n,&comps);
            danhDau[comps]++;
        }
        printf("n = %d, k = %d\n", n, k[i]);
        printf("Mean: %.2f\n", trungBinhCong(danhDau, 1000, k[i]));
        printf("-------------------\n");
    }
    return 0;
}