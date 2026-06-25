#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Hàm Bubble Sort
void bubbleSort(int arr[], int n, long long *comps) {
    *comps = 0;
    for(int i = 0; i < n; i++) {
        for(int j = n - 1; j > i; j--) {
            (*comps)++; // Đếm số lần thực hiện phép so sánh
            if(arr[j-1] > arr[j]) {
                swap(arr + j - 1, arr + j); // Đổi chỗ
            }
        }
    }
}
// Hàm sinh mảng ngẫu nhiên
void genRandArr(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Random giá trị từ 0 - 999
    }
}
int main() {
    srand(time(NULL)); // Khởi tạo seed cho hàm random
    long long comps = 0;
    printf("Cau 1: Test mang kich thuoc 20\n");
    int arr[20];
    genRandArr(arr, 20);
    printf("Mang ban dau: \n");
    for(int i = 0; i < 20; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bubbleSort(arr, 20, &comps);
    printf("Mang sau khi sap xep tang dan: \n");
    for(int i = 0; i < 20; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("So lan so sanh: %lld\n", comps);

    printf("Cau 2: Khao sat so lan comps (n=20)\n");
    int k[] = {10, 20, 50, 100, 1000, 10000};
    for(int i = 0; i < 6; i++) {
        long long total_comps = 0;
        for(int t = 0; t < k[i]; t++) {
            int temp_arr[20];
            genRandArr(temp_arr, 20);
            bubbleSort(temp_arr, 20, &comps);
            total_comps += comps;
        }
        printf("Voi n = %d, Mean: %.2f\n", k[i], (double)total_comps / k[i]);
    }
    printf("Nhan xet: So lan comps trung binh bang n*(n-1)/2 voi n la kich thuoc mang\n");
    printf("Cau 3: Khao sat voi kich co mang thay doi\n");
    int h[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    for(int i = 0; i < 10; i++) {
        int n = h[i];
        long long total_comps = 0;
        for(int t = 0; t < 1000; t++) { // Thử nghiệm 1000 lần cho mỗi n để lấy trung bình
            // Cấp phát mảng động theo kích thước n
            int *temp_arr = (int*)malloc(n * sizeof(int)); 
            genRandArr(temp_arr, n);
            bubbleSort(temp_arr, n, &comps);
            total_comps += comps;
            free(temp_arr); // Giải phóng bộ nhớ
        }
        printf("Kich thuoc n = %3d => Mean: %.2f\n", n, (double)total_comps / 1000);
    }
    printf("Mean comps = n*(n-1)/2 => Do phuc tap: O(n^2)");
    return 0;
}