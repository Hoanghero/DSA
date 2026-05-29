#include <stdio.h>

int f(int a[], int n, int *x, int *s, int *dm, int *da, int *ds)
{
    int count = -1;
    *x = 0;
    *s = 0;
    for (int d = n / 2; d > 0; d /= 2)
    {
        count++;
        int d_assigns = 0;
        int d_shifts = 0;
        for (int i = d; i < n; i++)
        {
            int t = a[i];
            d_assigns++; // Gán: t = a[i]
            int j;
            for (j = i; j >= d && a[j - d] > t; j -= d)
            {
                a[j] = a[j - d];
                d_shifts++; // Dịch chuyển bên trong mảng
            }
            a[j] = t; // Gán: a[j] = t
            d_assigns++;
        }
        dm[count] = d;
        da[count] = d_assigns;
        ds[count] = d_shifts;
        (*x) += d_assigns;
        (*s) += d_shifts;
    }
    return count + 1;
}

int main()
{
    int a[] = {34, 29, 10, 3, 2, 44, 88, 1, 21, 12, 3, 18, 21, 23, 37, 17, 8, 9, 4, 0};
    int n = 20, dm[100], da[100], ds[100];
    int x, s;
    printf("%-10s | %-10s | %-10s\n", "Vong ", "Assigns", "Shifts");
    int c = f(a, n, &x, &s, dm, da, ds);
    for (int t = 0; t < c; t++)
        printf("%10d | %10d | %10d\n", dm[t], da[t], ds[t]);
    printf("Tong: Assigns = %d, Shifts = %d", x, s);
    return 0;
}