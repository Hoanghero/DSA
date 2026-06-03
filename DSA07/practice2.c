#include <stdio.h>
float sum1(int n){
    if (n==1)
        return 1.0;
    return sum1(n-1) + (float)1/n;
}
float sum2(int n){
    if (n==1)
        return 0.5;
    return sum2(n-1) + (float)1/(2*n);
}
float sum3(int n){
    if (n==1)
        return 0.5;
    return sum3(n-1) + (float)n/(n+1);
}
int sum4(int n){
    if (n==0) return 2;
    if (n==1) return 3;
    return sum4(n-1)*6 - 9*sum4(n-2);
}
/*
a) 
BASE CASE xảy ra khi n=1
Kết quả của BASE CASE: sum1(1)=1.0
Before BASE CASE: sum1(2)=sum1(1)+1/2
Before Before BASE CASE: sum1(3)=sum1(2)+1/3

b) 
BASE CASE xảy ra khi n=1
Kết quả của BASE CASE: sum2(1)=0.5
Before BASE CASE: sum2(2)=sum2(1)+1/4
Before Before BASE CASE: sum2(3)=sum2(2)+1/6

c) 
BASE CASE xảy ra khi n=1
Kết quả của BASE CASE: sum3(1)=0.5
Before BASE CASE: sum3(2)=sum3(1)+2/3
Before Before BASE CASE: sum3(3)=sum3(2)+3/4

d) 
BASE CASE xảy ra khi n=0 và n=1
Kết quả của BASE CASE: sum4(0)=2, sum4(1)=3
Before BASE CASE: sum4(2)=sum4(1)*6 - 9*sum4(0)
Before Before BASE CASE: sum4(3)=sum4(2)*6 - 9*sum4(1)
*/
int main() {
    int n;
    scanf("%d", &n);
    printf("%.2f\n", sum1(n));
    printf("%.2f\n", sum2(n));
    printf("%.2f\n", sum3(n));
    printf("%d", sum4(n));
    return 0;
}
