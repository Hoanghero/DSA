#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void sinhMang(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
}
int countInverse(int a[], int n, int *count) {
    if (n == 1)
        return 0;
    if (a[n-1] < a[n-2]) {
        (*count)++;
        return 1 + countInverse(a, n-1, count);
    }
    else
        return countInverse(a, n-1, count);
}
float trungBinhCong(int arr[], int n, int m) {
    float tong = 0;
    for (int i = 0; i < n; i++) {
        tong += (float)(i * arr[i]);
    }
    return tong/m;
}
/*
BASE CASE: n = 1
OUTPUT BASE CASE: 0
BEFORE BASE CASE: n = 2 => neu a[2-1] = a[1] < a[0] = a[2-2] thi return 1 + countInverse(a,1) = 1+0
else return countInverse(a,1) = 0
BEFORE BEFORE BASE CASE: n = 3 => neu a[3-1] = a[2] < a[1] = a[3-2] thi return 1 + countInverse(a,2)
else return countInverse(a,2)
*/
int main() {
    int a[] = {10,9,8, 7, 6, 5, 4, 3, 2, 1}, count = 0;
    printf("%d\n", countInverse(a, 10, &count));
    printf("%d\n", count);
    return 0;
}
