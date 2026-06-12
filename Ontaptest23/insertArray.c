#include <stdio.h>
void insertArray(int a[], int n, int value, int index) {
    if (n <= index) {
        a[index] = value;
        return;
    }
    a[n] = a[n-1];
    insertArray(a,n-1,value,index);
}
/*
BASE CASE: n <= index
OUTPUT BASE CASE:
n == index: a[index] = value
n < index => chen phan tu o ngoai mang: a[index] = value
BEFORE BASE BASE:  
n == index + 1
a[index+1] = a[index];
BEFORE BEFORE BASE CASE: 
n == index + 2
a[index+2] = a[index+1]
*/
int main() {
    int a[12] = {0,1,2,3,4,5,6,7,8,9};
    insertArray(a,10,24,0);
    for (int i=0; i<11; i++) printf("%d ", a[i]);
    return 0;
}