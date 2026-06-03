#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int minIndex(float arr[], int n) {
    if (n <= 0) {
        return -1;
    }
    
    int min_idx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[min_idx]) {
            min_idx = i;
        }
    }
    return min_idx;
}
void minimum(float arr[], int n, int *comps) {
    (*comps) = 0;
    int min_idx = 0;
    for (int i = 1; i < n; i++) {
        (*comps)++;
        if (arr[i] < arr[min_idx]) {
            min_idx = i;
        }
    }
}
void sinhMang(float arr[], int n, int min, int max)
{
    for (int i = 0; i < n; i++)
        arr[i] = min + ((float)rand() / RAND_MAX) * (max - min);
}
float trungBinhCong(int arr[], int n) {
    float tong = 0;
    for (int i = 0; i < n; i++) {
        tong += (float)(i * arr[i]);
    }
    return tong;
}
int main() {
    time_t t;
    srand((unsigned)time(&t));
    float arr[100];
    int n=10;
    int k[] ={100, 1000};
    for (int i = 0; i < 2; i++) {
        int danhDau[11] = {};
        for (int j=0; j<k[i]; j++) {
            int comps;
            sinhMang(arr, n, (-2)*n, 2*n);
            minimum(arr,n,&comps);
            danhDau[comps]++;
        }
        for (int l=0; l<10; l++) {
            printf("So phep so sanh %d: %d lan\n", l, danhDau[l]);
        }
        printf("Mean: %.2f\n", trungBinhCong(danhDau, 10)/k[i]);
    }
    return 0;
}