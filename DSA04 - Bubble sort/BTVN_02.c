#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Hàm sinh mảng có ít nhất 2 phần tử trùng nhau
void taoMangTrung(int *arr, int n) {
    int dupValue = (rand() % 199) - 99; 
    // Gán vào 2 vị trí đầu tiên trùng nhau
    arr[0] = dupValue;
    arr[1] = dupValue; 
    // Điền các vị trí còn lại với giá trị ngẫu nhiên
    for (int i = 2; i < n; i++) {
        arr[i] = (rand() % 201) - 100; 
    }
    // Xáo ngẫu nhiên vị trí của 2 phần tử trùng nhau
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
void xoaPT(int *arr, int *n, int index) {
    for (int i=index; i<(*n)-1; i++) {
        arr[i] = arr[i+1];
    }
    (*n)--;
}
void xoaPTTln(int *arr, int *n, int *steps) {
    for (int i=0; i<*n; i++) {
        for (int j=i+1; j<*n;) {
            (*steps)++;
            if (arr[j] == arr[i]) {
                (*steps)++;
                xoaPT(arr, n, j);
            }
            else {
                j++;
            }
        }
    }
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int arr[], int n, int *steps) {
    for (int i=0; i<n; i++) {
        for (int j=n-1; j>i; j--) {
            (*steps)++;
            if (arr[j-1] > arr[j]) {
                (*steps)++;
                swap(arr+j-1, arr+j);
            }
        }
    }
}
void xoaPTTbbs(int *arr, int *n, int *steps) {
    int stepsbbs=0;
    bubbleSort(arr, *n, &stepsbbs);
    (*steps)+=stepsbbs;
    for (int i=1; i<*n;) {
        (*steps)++;
        if (arr[i] == arr[i-1]) {
            (*steps)++;
            xoaPT(arr, n, i);
        }
        else {
            i++;
        }
    }
}
int main() {
    time_t t;
    srand((unsigned)time(&t));
    int n=50, arr[100], b[100];
    float total_stepsln=0, total_stepsbbs=0;
    for (int j=0; j<1000; j++) {
        n=50;
        int stepsln=0, stepsbbs=0;
        taoMangTrung(arr, n);
        for (int i=0; i<n; i++) b[i] = arr[i];
        xoaPTTln(b, &n, &stepsln);
        total_stepsln+=stepsln;
        n=50;
        xoaPTTbbs(arr, &n, &stepsbbs);
        total_stepsbbs+=stepsbbs;
    }
    printf("Mean linear: %.2f\n", total_stepsln/1000);
    printf("Mean bubble sort: %.2f", total_stepsbbs/1000);
    printf("\nMac du ca hai cach deu co do phuc tap la O(n^2), phuong an dung linear search toi uu hon bubble sort");
    return 0;
}