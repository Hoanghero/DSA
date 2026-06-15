#include <stdio.h>
void insertArray(int a[], int *n, int value, int index) {
    (*n)++;
    for (int i=*n-1;i>=index;i--) {
        a[i+1]=a[i];
    }
    a[index]=value;
}

int main() {
    int n = 5;
    int array[10] = { 3, 1, 5, 7, 4 };
    int value;
    int index = 2;
    value = 8;
    insertArray(array, &n, value, index);  
    for (int i=0; i<n; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}