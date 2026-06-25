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
void bubbleSort(int arr[], int n) {
    for (int i=0; i<n; i++) {
        for (int j=n-1; j>i; j--) {
            if (arr[j-1] > arr[j]) swap(arr+j-1, arr+j);
        }
    }
}
int main() {
    time_t t;
    srand((unsigned)time(&t));
    int n, arr[100];
    scanf("%d", &n);
    sinhMang(arr,n,-100,100);
    bubbleSort(arr, n);
    for (int j=0; j<n; j++) printf("%d ", arr[j]);
    return 0;
}