#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int comps = 0;

void sinhMangTang(int arr[], int n, int min, int max){
    for (int i = 0; i < n; i++){
        arr[i] = min + rand() % (max - (n - i - 1) - min + 1);
        min = arr[i] + 1;
    }
}

int timCapsocong(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int d = a[j] - a[i];
            int value = a[j];
            for (int k = j + 1; k < n; k++) {
                comps++; 
                if (a[k] - value == d) {
                    value = a[k];
                    count++; 
                }
                else if (a[k] - value > d) {
                    comps++;
                    break; 
                }
            }
        }
    }
    return count;
}

float Mean(int arr[], int n, int m) {
    float tong = 0;
    for (int i = 0; i < n; i++) {
        tong += (float)(i * arr[i]);
    }
    return tong / m;
}

int main() {
    time_t t;
    srand((unsigned)time(&t));
    int a[20], danhDau[1200] = {}; 
    for (int i = 0; i < 1000; i++) {
        sinhMangTang(a, 20, -200, 200);
        comps = 0;
        timCapsocong(a, 20);
        danhDau[comps]++;
    }
    printf("Bang tan so\n");
    for (int l = 0; l < 1200; l++) {
        if (danhDau[l] != 0) printf("So sanh %d lan:\t%d\n", l, danhDau[l]);
    }
    printf("Mean so phep so sanh: %.2f\n", Mean(danhDau, 1200, 1000));
    printf("Big O: O(n^3) - Bao gom 2 vong lap chon phan tu i, j dau va 1 vong lap tim phan tu k tiep theo.\n");
    
    return 0;
}