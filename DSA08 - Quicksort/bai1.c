#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int count = 0;
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
// Hàm đổi chỗ (swap) hai phần tử
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
// Hàm Partition: Chia mảng và trả về vị trí của pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low-1;
    for (int j=low; j<high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}
// Hàm Quick Sort đệ quy
void quickSort(int arr[], int low, int high, int *count) {
    if (low < high) {
        // pi (partition index) là vị trí pivot đã nằm đúng chỗ
        int pi = partition(arr, low, high);
        (*count)++;
        // Gọi đệ quy để sắp xếp tiếp nhánh bên trái và nhánh bên phải của pivot
        quickSort(arr, low, pi - 1, count);
        quickSort(arr, pi + 1, high, count);
    }
}
int main() {
    time_t t;
    srand((unsigned)time(&t));
    int k[] ={10, 100, 1000, 10000};
    int arr[100];
    for (int i=0; i<4; i++) {
        int danhDau1[1001] = {};
        for (int j=0; j<k[i]; j++) {
            int count = 0;
            genRandArr(arr, 10, -1000, 1000);
            quickSort(arr, 0, 9, &count);
            danhDau1[count]++;
        }
        printf("n = %d, k = %d\n", 10, k[i]);
        printf("Mean a1 = %.2f\n", Mean(danhDau1, 1001, k[i]));
        printf("-----------------\n");
    }
    return 0;
}