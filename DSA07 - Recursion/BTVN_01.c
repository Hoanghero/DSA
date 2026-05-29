#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int f(int n)
{
    if (n == 1) return 1;
    return f(n-1) * 2;
}

//BASE CASE: Xay ra khi n = 1
//OUTPUT OF BASE CASE: Tra ve: f(1) = 1
//BEFORE BASE CASE: Xay ra khi n = 2 -> Tra ve f(2) = f(1) * 2 = 1 * 2 = 2
//BEFORE BEFORE BASE CASE: Xay ra khi n = 3 -> Tra ve f(3) = f(2) * 2 = f(1) * 2 * 2 = 1 * 2 * 2 = 4
int f_nrecursion(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++) res *= i;
    return res;
}


float g(int n)
{
    if (n == 1) return 1.0;
    return n * n + g(n - 1);
}

//BASE CASE: Xay ra khi n = 1
//OUTPUT OF BASE CASE: Tra ve: g(1) = 1.0
//BEFORE BASE CASE: Xay ra khi n = 2 -> Tra ve g(2) = 2.0 * 2.0 + g(1) = 2.0 * 2.0 + 1.0 = 5.0
//BEFORE BEFORE BASE CASE: Xay ra khi n = 3 -> Tra ve g(3) = 3.0 * 3.0 + g(2) = 3.0 * 3.0 + 2.0 * 2.0 + g(1) = 3.0 * 3.0 + 2.0 * 2.0 + 1.0 = 14.0

float g_nrecursion(int n)
{
    float res = 1.0;
    for (int i = 2; i <= n; i++)
    {
        res += i * i;
    }
    return res;
}

int F(int n)
{
    if (n == 1) return 1;
    if (n == 2) return 1;
    return F(n - 1) + F(n - 2);
}

//BASE CASE 1: Xay ra khi n = 1
//BASE CASE 2: Xay ra khi n = 2
//OUTPUT OF BASE CASE: Tra ve: F(1) = 1, F(2) = 1
//BEFORE BASE CASE: Xay ra khi n = 3 -> Tra ve F(3) = F(2) + F(1) = 1 + 1 = 2
//BEFORE BEFORE BASE CASE: Xay ra khi n = 4 -> Tra ve F(4) = F(3) + F(2) = F(2) + F(1) + 1 = 1 + 1 + 1 = 2

int F_nrecursion(int n)
{
    int f1 = 1, f2 = 2, f;
    for (int i = 3; i <= n; i++)
    {
        f = f1 + f2;
        f1 = f2;
        f2 = f;
    }
    return f;
}

int P(int n)
{
    if (n == 0) return 1;
    if (n == 1) return 2;
    if (n == 2) return 3;
    return P(n - 1) * P(n - 3); 
}

//BASE CASE 1: Xay ra khi n = 0
//BASE CASE 2: Xay ra khi n = 1
//BASE CASE 3: Xay ra khi n = 2
//OUTPUT OF BASE CASE: Tra ve: P(0) = 1, P(1) = 2, P(2) = 3 
//BEFORE BASE CASE: Xay ra khi n = 3 -> Tra ve P(3) = P(2) * P(0) = 3 * 1 = 3
//BEFORE BEFORE BASE CASE: Xay ra khi n = 4 -> Tra ve P(4) = P(3) * P(1) = P(2) * P(0) * 2 = 3 * 1 * 2 = 6

int P_nrecursion(int n)
{
    int P1 = 1, P2 = 2, P3 = 3, P;
    for (int i = 3; i <= n; i++)
    {
        P = P3 * P1;
        P1 = P2;
        P2 = P3;
        P3 = P;
    }
}
int main()
{
    time_t t;
    srand((unsigned) time (&t));
    long long res = 1;
    int n;
    for (int i = 1; i <= n; i++)
    {

    }
    return 0;
}