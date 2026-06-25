#include <stdio.h>
int f(int a[], int left, int right, int *count) {
    if (left >= right) {
        (*count)++;
        return 0;
    }
    int middle = (left + right) / 2;
    (*count)++;
    return a[middle] + f(a, left, middle-1, count) + f(a, middle+1, right, count);
}  
/*
BASE CASE: left >= right
OUTPUT BASE CASE: 0
BEFORE BASE CASE:
left-1 <right hoac left < right+1
mid = (left+right)/2
output: a[mid] + f(a,left,mid-1) + f(a,mid+1,right)
BEFORE BEFORE BASE CASE: 
left-2 <right hoac left-1<right+1 hoac left<right+2
output: a[mid] + f(a,left,mid-1) + f(a,mid+1,right)
*/
int main() {
    int a[] = {1, 2, 3, 4, 5, 5, 7}, count = 0;
    printf("Ham tren co chuc nang tinh tong cac phan tu tu vi tri left sang right trong mang, ngoai tru cac index khi de quy nhi phan chay den left == right\n");
    printf("%d\n", f(a, 0, 6, &count));
    printf("So lan goi ham f: %d\n", count);
    return 0;
}