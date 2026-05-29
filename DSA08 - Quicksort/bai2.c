#include <stdio.h>
// Hàm đổi chỗ (swap) hai phần tử
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}
void selectionSort(int arr[], int n, int *step) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i; 
        for (int j = i + 1; j < n; j++) {
            (*step)++; 
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(&arr[min_idx], &arr[i]);
            (*step)++;
        }
    }
}
void insertionSort (int arr[],int n,int *step) {
    int key;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        int j = i - 1;

        while (j >= 0) {
            (*step)++;
            if (arr[j] > key) {
                (*step)++;
                arr[j+1] = arr[j];
                j--;
            }
            else {
                break;
            }    
        }
        arr[j+1] = key;
    }
}
void bubbleSort(int arr[], int n, int *step) 
{
    for (int i=0; i<n; i++) {
        for (int j=n-1; j>i; j--) {
            (*step)++;
            if (arr[j-1] > arr[j]) {
                (*step)++;
                swap(arr+j-1, arr+j);
            }
        }
    }
}
int partition(int arr[], int low, int high, int *step) {
    int pivot = arr[high]; 
    int i = (low - 1); 
    for (int j = low; j < high; j++) {
        (*step)++; // Đếm phép so sánh arr[j] <= pivot
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
            (*step)++; // Đếm phép hoán đổi
        }
    }
    swap(&arr[i + 1], &arr[high]);
    (*step)++; // Đếm phép hoán đổi pivot
    return (i + 1);
}
void quickSort(int arr[], int low, int high, int *step) {
    if (low < high) {
        int pi = partition(arr, low, high, step);
        quickSort(arr, low, pi - 1, step);
        quickSort(arr, pi + 1, high, step);
    }
}
int main() {
    int arr[100], goc[100], n, stepsel=0, stepins=0, stepbb=0, stepqs=0;
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &goc[i]);
    copyArray(goc, arr, n);
    selectionSort(arr, n, &stepsel);
    copyArray(goc, arr, n);
    insertionSort(arr, n, &stepins);
    copyArray(goc, arr, n);
    bubbleSort(arr, n, &stepbb);
    copyArray(goc, arr, n);
    quickSort(arr, 0, n - 1, &stepqs);
    printf("Selection sort: %d\nInsertion sort: %d\nBubble sort: %d\nQuick sort: %d\n",stepsel, stepins, stepbb, stepqs);
    return 0;
}