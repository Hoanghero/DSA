#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void sinhMang(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
}
void swap(int *a, int *b) {
    int temp = *a;
    *a=*b;
    *b=temp;
}
void selectionSort(int arr[], int n) {
    int min, j1;
    for (int i=0; i<n; i++) {
        min = arr[i];
        for (int j=i+1; j<n; j++) {
            if (arr[j] < min) {
                min = arr[j];
                j1=j;
            }
        }
        if (min!=arr[i]) swap(&arr[j1], &arr[i]);
    }
}
int main() {
    time_t t;
    srand((unsigned)time(&t));
    int arr[100];
    printf("Before: ");
    sinhMang(arr,10,0,50);
    for (int i=0; i<10; i++) printf("%d ", arr[i]);
    printf("\n");
    selectionSort(arr,10);
    printf("After: ");
    for (int j=0; j<10; j++) printf("%d ", arr[j]);
    printf("\n");
    return 0;
}