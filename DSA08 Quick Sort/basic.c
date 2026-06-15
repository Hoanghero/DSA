#include <stdio.h>
// Hàm đổi chỗ (swap) hai phần tử
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
// Hàm Partition: Chia mảng và trả về vị trí của chốt
int vi_tri(int a[], int l, int r){
    int pivot = a[r];
    int i = l - 1;
    for(int j = l; j < r; j++){
        if(a[j] <= pivot){
            i++;
            swap(&a[i], &a[j]);
        }
    }
    i++;
    swap(&a[i], &a[r]);
    return i;
}
// Hàm Quick Sort đệ quy
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi (partition index) là vị trí chốt đã nằm đúng chỗ
        int pi = vi_tri(arr, low, high);
        // Gọi đệ quy để sắp xếp tiếp nhánh bên trái và nhánh bên phải của chốt
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
// Hàm tiện ích để in mảng ra màn hình
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    // Mảng ví dụ mà chúng ta đã mô phỏng
    int arr[] = {8, 3, 1, 7, 0, 10, 2, 13, 5, 15, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Mang ban dau: \n");
    printArray(arr, n);
    // Gọi hàm Quick Sort, truyền vào chỉ số bắt đầu (0) và kết thúc (n-1)
    quickSort(arr, 0, n - 1);
    printf("Mang sau khi sap xep bang Quick Sort: \n");
    printArray(arr, n);
    return 0;
}