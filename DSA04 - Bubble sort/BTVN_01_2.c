#include <stdio.h>
#include <time.h>
#include <stdlib.h>
// Hàm đổi giá trị
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}
// Hàm sinh chuỗi ngẫu nhiên bao gồm các chữ hoa và thường
void sinhChuoi(char arr[], int n, int min1, int max1, int min2, int max2) {
    for (int i = 0; i < n; i++) {
        int a = (rand() % 2) + 1;
        if (a==1) {
            arr[i] = min1 + rand() % (max1 - min1 + 1); // Sinh kí tự thường ngẫu nhiên
        }
        else {
            arr[i] = min2 + rand() % (max2 - min2 + 1); // Sinh kí tự hoa ngẫu nhiên
        }
    }
}
// hàm bubble sort sap xep ki tu
void bubbleSort(char arr[], int n) {
    for (int i=0; i<n; i++) {
        for (int j=n-1; j>i; j--) {
            char b=arr[j], c=arr[j-1];
            if (b>96) b-=32;
            if (c>96) c-=32;
            if (c >= b) {
                if (c==b && arr[j]<arr[j-1]) swap(arr+j-1, arr+j);
                if (c>b) swap(arr+j-1, arr+j);
            }
        }

    }
}
int main() {
    time_t t;
    srand((unsigned)time(&t));
    int n; // khai báo độ dài chuỗi
    char arr[100]; // khai báo chuỗi
    scanf("%d", &n); // Nhập độ dài chuỗi
    sinhChuoi(arr,n,97,122, 65, 90); // Tạo chuỗi ngẫu nhiên gồm cả chữ hoa và thường
    printf("Chuoi truoc khi sap xep: %s\n", arr);
    bubbleSort(arr, n); // Sắp xếp bằng bubble sort
    arr[n]='\0'; // Kết thúc chuỗi để tránh in giá trị rác
    printf("Chuoi sau khi sap xep: %s", arr);
    return 0;
}