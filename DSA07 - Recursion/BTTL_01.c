#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int sum(int a[], int n)
{
    if (n == 1) return a[0];
    return sum(a, n - 1) + a[n-1];
}

//BASE CASE: Xay ra khi n = 1
//OUTPUT OF BASE CASE: Tra ve phan tu dau tien: sum(1) = a[0]
//BEFORE BASE CASE: Xay ra khi n = 2 -> Tra ve sum(2) = sum(1) + a[1] = a[0] + a[1]
//BEFORE BEFORE BASE CASE: Xay ra khi n = 3 -> Tra ve sum (3) = sum(2) + a[2] = sum (1) + a[1] + a[2] = a[0] + a[1] + a[2]

int main()
{
    time_t t;
    srand((unsigned) time (&t));
    int n; scanf("%d", &n);
    int a[n+1];
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sum(a, 5);
    return 0;
}