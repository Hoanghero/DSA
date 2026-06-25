#include <stdio.h>
int sumChan(int a[], int n){
    if (n==1){
        if (a[0]%2==0) return a[0];
        else {
            return 0;
        }
    }
    if (a[n]%2!=0) a[n]=0;
    return sumChan(a,n-1) + a[n-1];
}
/*
BASE CASE xảy ra khi n=1
Kết quả của BASE CASE: nếu a[0] là chẵn thì trả về a[0], lẻ thì trả về 0
Before BASE CASE: sumChan(a, 2) = sumChan(a, 1) + a[1]
Before Before BASE CASE: sumChan(a, 3) = sumChan(a, 2) + a[2]
*Lưu ý: nếu a[n] lẻ thì gán a[n] bằng 0 để cộng
*/
int main() {
    int a[9] = {4,6,2,7,5, 8, 10, 7, 13};
    printf("Tong cac so chan trong day: %d", sumChan(a, 9));
    return 0;
}
