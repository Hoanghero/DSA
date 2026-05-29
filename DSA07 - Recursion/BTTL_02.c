#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

float s1(int n)
{
    if (n == 1) return n;
    return (float)1/n + s1(n-1);
}

float s2(int n)
{
    if (n == 1) return (float)1/2;
    return (float)1/(n * 2) + s2(n - 1);
}

float s3(int n)
{
    if (n == 1) return (float)n / (n + 1);
    return (float)n / (n + 1) + s3(n - 1);
}

long long s4(int n)
{
    if (n == 0) return 2;
    if (n == 1) return 3;
    return 6 * s4(n - 1) - 9 * s4(n - 2);
}

int main()
{
    time_t t;
    srand((unsigned) time (&t));
    int n; scanf("%d", &n);
    printf("n = %d:\n", n);;
    printf("s1: %f\n", s1(n));
    printf("s2: %f\n", s2(n));
    printf("s3: %f\n", s3(n));
    printf("s4: %d\n", s4(n));
    return 0;
}