#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[101];
int n = 10;

void random(int n, int l, int r)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = l + rand() % (r - l + 1);
    }
}

void bubblesort(int a[], int* n, int* comp, int* swap)
{
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *n - 1 - i; j++)
        {
            (*comp)++;
            if (a[j] > a[j+1])
            {
                (*swap)++;
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

int cnt(int n)
{
    if (n == 0) return 1;
    int cnt = 0;
    while(n)
    {
        n /= 10;
        cnt++;
    }
    return cnt;
}

void stats(int k)
{

    int c[46] = {}, s[46] = {};
    for (int t = 0; t < k; t++)
    {
        random(n, -1000, 1000);
        int comp = 0, swap = 0;
        bubblesort(a, &n, &comp, &swap);
        c[comp]++;
        s[swap]++;
    }
    float ave = 0;
    printf("index          comp          swap:\n");
    for (int i = 0; i <= 45; i++)
    {
        printf("%d", i);
        for (int j = 0; j < 9 - cnt(i); j++) printf(" ");
        printf("||");
        for (int j = 0; j < 6 - (cnt(c[i]) + 1) / 2; j++) printf(" ");
        printf("%d", c[i]);
        for (int j = 0; j < 6 - cnt(c[i]) / 2; j++) printf(" ");
        printf("||");
        for (int j = 0; j < 6 - (cnt(s[i]) + 1) / 2; j++) printf(" ");
        printf("%d", s[i]);
        for (int j = 0; j < 6 - (cnt(s[i])) / 2; j++) printf(" ");
        printf("||\n");
        ave += s[i] * i;
    }
    printf("average: %f\n", ave/k);
    printf("\n");
}


int main()
{
    time_t t;
    srand((unsigned) time (&t));
    stats(10);
    stats(100);
    stats(1000);
    stats(10000);
}