#include <stdio.h>
int sum(int a[], int n){
    if (n==1)
        return a[0];
    return sum(a,n-1) + a[n-1];
}
/*
BASE CASE xảy ra khi n=1
Kết quả của BASE CASE: sum(1)=a[0]=4
Before BASE CASE: sum(2)=sum(1)+a[1]=4+6=10
Before Before BASE CASE: sum(3)=sum(2)+a[2]=10+2=12
*/
int main() {
    int a[5] = {4,6,2,7,5};
    printf("%d", sum(a, 5));
    return 0;
}
