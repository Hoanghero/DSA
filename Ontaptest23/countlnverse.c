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
    time_t t;
    srand((unsigned) time (&t));
    int a[11], danhDau[101] = {};
    for (int t=0; t<100000; t++) {
        int count = 0;
        sinhMang(a,10,-1000, 1000);
        countInverse(a, 10, &count);
        danhDau[count]++;
    }
    for (int i=0; i<101; i++) {
        if (danhDau[i] != 0) printf("So lan so sanh dung %d: %d\n", i, danhDau[i]);
    }
    float c = trungBinhCong(danhDau,101,100000);
    printf("Mean: %.2f", c);
    return 0;
}
