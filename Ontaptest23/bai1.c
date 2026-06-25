#include <stdio.h>
float S(long long n) {
    if (n==1) return (float)1;
    return S(n-1) + (float)1/(2*n-1);
}
//BASE CASE: n=1
//OUTPUT BASE CASE: S(1) = u_1 = 1/(0+1) = 1
//BEFORE BASE CASE: S(2) = S(1) + u_2 = 1 + 1/(1+2) = 4/3
//BEFORE BEFORE BASE CASE: S(3) = S(2) + u_3 = 4/3 + 1/(2+3) = 23/15 
float S1(int n) {
    float sum = 0;
    for (int i=1; i<=n; i++) {
        sum += (float)1/(2*i-1);
    }
    return sum;
}
int main() {
    printf("u_n = 1/(2n-1)\n");
    printf("n = 10, S = %.2f\n", S(3));
    printf("n = 10, S1 = %.2f\n", S1(3));
    return 0;
}