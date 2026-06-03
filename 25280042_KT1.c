#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void genRandArr(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
}
float Mean(int arr[], int n, int m) {
    float tong = 0;
    for (int i = 0; i < n; i++) {
        tong += (float)(i * arr[i]);
    }
    return tong/m;
}
int isPrime(int a) {
    if (a==1) return 0;
    for (int i=2; i<a; i++) {
        if (a%i == 0) return 0;
    }
    return 1;
}
void xoaPT(int arr[], int *n, int index, int *shifts) {
    for (int i=index; i<*n-1; i++) {
        (*shifts)++;
        arr[i] = arr[i+1];
    }
    (*n)--;
}
void sovle(int arr[], int *n, int *shifts) {
    for (int i=0; i<*n;) {
        if (isPrime(arr[i])) {
            xoaPT(arr, n, i, shifts);
        }
        else {
            i++;
        }
    }
} 
int main() {
    time_t t;
    srand((unsigned)time(&t));
    int arr[100];
    int danhDau1[1001] = {};
    for (int j=0; j<1000000; j++) {
        int shifts=0, n=10;
        genRandArr(arr, n, 1, 100);
        sovle(arr, &n, &shifts);
        danhDau1[shifts]++;
    }
    printf("n = %d, k = %d\n", 10, 1000000);
    for (int i=0; i<1000; i++) {
        if (danhDau1[i]!=0) printf("So shifts %d: %d\n", i, danhDau1[i]);
    }
    printf("Mean shifts = %.2f\n", Mean(danhDau1, 1001, 1000000));
    printf("So phep dich chuyen trong truong hop tot nhat la 0 (khong co so nguyen to nao)\n");
    printf("So phep dich chuyen trong truong hop xau nhat la 45 (toan bo mang la so nguyen to\n");
    printf("Big O: O(n^2)");
    return 0;
}