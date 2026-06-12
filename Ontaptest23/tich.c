#include <stdio.h>

int S(int n) {
    if(n==1) return 2;
    return n*(n+1)+S(n-1);
}
/*
BASE CASE: n = 1
OUTPUT BASE CASE: S(1) = 1*2 = 2
BEFORE BASE CASE: S(2) = 2*3 + S(1) = 6+2 = 8
BEFORE BEFORE BASE CASE: S(3) = 3*4 + S(2) = 12+8 = 20
*/
int main() {
    int n;
    scanf("%d", &n);
    printf("%d", S(n));
    return 0;
}