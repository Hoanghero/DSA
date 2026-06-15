#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sinhMang(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

float trungBinhCong(int arr[], int n) {
    float tong = 0;
    for (int i = 0; i < n; i++) {
        tong += (float)(i * arr[i]);
    }
    return tong;
}

void linearSearch(int arr[], int n, int value, int *comps) {
    for (int i = 0; i < n; i++) {
        (*comps)++;
        if (arr[i] == value) break;
    }
}
int main() {
    time_t t;
    srand((unsigned)time(&t));
    int arr[100];
    int k[] ={100, 1000, 10000};
    
    for (int i = 0; i < 3; i++) {
        int danhDau[11] = {};
        for (int j=0; j<k[i]; j++) {
            int comps = 0;
            sinhMang(arr, 10, -1000, 1000);
            int value = arr[rand() % 10];
            linearSearch(arr, 10, value, &comps);
            danhDau[comps]++;
        }
        for (int l=1; l<=10; l++) {
            printf("So phep so sanh %d: %d lan\n", l, danhDau[l]);
        }
        printf("Mean: %.2f\n", trungBinhCong(danhDau, 11)/k[i]);
    }
    
    return 0;
}