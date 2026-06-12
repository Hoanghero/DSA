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
    value > a[mid_2] => mid_2 = l_1-1
    value < a[mid_2] => mid_2 = r_1+1 
Ta co: mid_2 = (l_2+r_2)/2
TH1: mid_2 = l_1-1. Khi do r_1 = r_2. Viet lai: l_1-1 = (l_2+r_1)/2 => l_2 = 2*l_1-r_1-2
TH2: mid_2 = r_1+1, Khi do r_1 = r_2. Viet lai: r_1+1 = (l_1+r_2)/2 => r_2 = 2r_1-l_1+2

BEFORE BEFORE BASE CASE: 
Gia su mid_3 = l_2-1:
    value > a[mid_3] => mid_3 = l_2-1
    value < a[mid_3] => mid_3 = r_2+1 
Ta co: mid_3 = (l_3+r_3)/2
TH1: mid_3 = l_2-1. Khi do r_2 = r_3. Viet lai: l_2-1 = (l_3+r_2)/2 => l_3 = 2*l_2-r_2-2
TH2: mid_3 = r_2+1, Khi do r_2 = r_3. Viet lai: r_2+1 = (l_2+r_3)/2 => r_3 = 2r_2-l_2+2

*Luu y: Neu mid_x * 2 =

Vi du: Cho mang [1,2,3,5,7,9,12,14,16,20,23,34,35,37], tim index cua 34
BASE CASE: 35 = a[12]
OUTPUT BASE CASE: 12 = (11+13)/2

BEFORE BASE CASE: 
Gia su mid_2 = l_1-1 = 11-1 = 10 la so chan 
Ta co: a[mid_2] = a[l_1-1] = a[11-1] = a[10] = 23 < 35 = value nen dieu gia su dung.
=> mid_2 = l_1-1. Khi do 13 = r_1 = r_2. Viet lai: l_1-1 = (l_2+r_1)/2 => l_2 = 2*l_1-r_1-2 = 2*11-13-2 = 7
Vay l_2 = 7, r_2 = 13.

BEFORE BEFORE BASE CASE: 
Gia su mid_3 = l_2-1 
Ta co: a[mid_3] = a[l_2-1] = a[7-1] = a[6] = 12 < 35 = value nen dieu gia su dung.
=> mid_3 = l_2-1. Khi do 13 = r_2 = r_3. Viet lai: l_2-1 = (l_3+r_2)/2 => l_3 = 2*l_2-r_2-2 = 2*7-13-2 = -1
Vay l_3 = 0, r_3 = 13.
*/
int main() {
    int a[100] = {1,2,3,5,7,9,12,14,16,20,23,34,35,37};
    if (dequy(a,0,13,45)!=-1) printf("%d", dequy(a, 0, 13, 45));
    else printf("Khong co phan tu");
    return 0;
}