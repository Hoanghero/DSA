#include <stdio.h>
void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(float arr[], int n) {
    for (int i=0; i<n; i++) {
        for (int j=n-1; j>i; j--) {
            if (arr[j-1] > arr[j]) swap(arr+j-1, arr+j);
        }
    }
}
int main() {
    int n; float arr[100];
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%f", &arr[i]);
    }
    bubbleSort(arr, n);
    for (int j=0; j<n; j++) printf("%.2f ", arr[j]);
    return 0;
}