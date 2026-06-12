#include <stdio.h>
int dequy(int *a, int l, int r, int value) {
    if (l>r) return -1;
    int mid = (l+r)/2;
    if (value > a[mid]) {
        return dequy(a, mid+1, r, value);
    }
    else if (value < a[mid]) {
        return dequy(a,l,r-1,value);
    }
    else return mid;
}
/*
BASE CASE: l>r hoac value = a[mid_1] voi mid_1 = (l_1+r_1)/2
OUTPUT BASE CASE: 
- l>r => khong tim thay phan tu
- value = a[mid_1] => tim thay index la mid_1, thoat ham de quy

BEFORE BASE CASE:
Gia su mid_2 = l_1-1:
    value > a[mid_2] => mid_2 = l_1-1. Khi do r_1 = r_2.
    value < a[mid_2] => mid_2 = r_1+1. Khi do l_1 = l_2.

BEFORE BEFORE BASE CASE: 
Gia su mid_3 = l_2-1:
    value > a[mid_3] => mid_3 = l_2-1. Khi do r_2 = r_3.
    value < a[mid_3] => mid_3 = r_2+1. Khi do l_2 = l_3.
*/
int main() {
    int a[100] = {1,2,3,5,7,9,12,14,16,20,23,34,35,37};
    if (dequy(a,0,13,45)!=-1) printf("%d", dequy(a, 0, 13, 45));
    else printf("Khong co phan tu");
    return 0;
}