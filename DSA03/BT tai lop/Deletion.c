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
        tong += (float)(i* arr[i]);
    }
    return tong;
}

void delete(int arr[], int* n, int index, int *assignment) {
    *assignment = 0;
    for (int i = index; i < *n-1; i++) {
        arr[i] = arr[i+1];
        (*assignment)++;
    }
    (*n)--;
}

int main() {
    time_t t;
    srand((unsigned)time(&t));
    int arr[20];
    int k[] = {100, 1000, 10000};
    printf("Bang tan so");
    for (int i = 0; i < 3; i++) {
        int danhDau[11] = {};
        for (int j=0; j<k[i]; j++) {
            int assignment = 0, n=10;
            sinhMang(arr, n, -1000, 1000);
            int index = rand() % n;
            delete(arr, &n, index, &assignment);
            danhDau[assignment]++;
        }
        printf("\nXoa index cuoi cua mang: %d lan\n", danhDau[0]);
        for (int l = 1; l <= 9; l++) {
            printf("So buoc gan lan %d: %d lan\n", l, danhDau[l]);
        }
        printf("Mean: %.2f\n", trungBinhCong(danhDau, 10)/k[i]);
    }
    return 0;
}