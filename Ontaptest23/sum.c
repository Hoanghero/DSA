#include <stdio.h>
int f(int *a, int low, int high) {
    if (low > high) return 0;
    int mid = (low+high)/2;
    return a[mid] + f(a,low,mid-1) + f(a,mid+1,high);
}
/*
BASE CASE: low > high
OUTPUT BASE CASE: 0
BEFORE BASE CASE:
- low == high:
    mid = (low+high)/2
    a[mid] = a[left]
    output: a[left]
- low < high:
mid = (low+high)/2
    output: a[mid] + f(a,left,mid-1) + f(a,mid+1,right)
BEFORE BEFORE BASE CASE: low<high
output: a[mid] + f(a,left,mid-1) + f(a,mid+1,right)
*/
int main() {
    int a[100] = {1,2,3,4,5,6,7};
    int c = f(a,2,5);
    printf("%d", c);
    return 0;
}