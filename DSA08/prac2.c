#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int left, int right) {
    int pivot = right;
    right -= 1;
    while (left <= right) {
        while (arr[left] < arr[pivot]) {
            left++;
        }
        while (left <= right && arr[pivot] < arr[right]) {
            right--;
        }
        if (left <= right) {
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }
    swap(&arr[left], &arr[pivot]);
    return left;
}
void quickSort(int arr[], int left, int right) {
    if (left < right) {
        // pi (partition index) là vị trí pivot đã nằm đúng chỗ
        int pi = partition(arr, left, right);
        for (int i=left; i<=right; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        // Gọi đệ quy để sắp xếp tiếp nhánh bên trái và nhánh bên phải của pivot
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}
// BASE CASE: xay ra khi right = left
// OUTPUT BASE CASE: ket thuc ham de quy
// BEFORE BASE CASE: left+1 = right
int main() {
    int a[1000] = {3, 1, 2, -4, 5, 10, 6, -4, 11, 9, -2};
    quickSort(a, 0, 10);
    printf("Mang sau khi da sap xep: ");
    for (int i=0; i<11; i++) printf("%d ", a[i]);
    return 0;
}