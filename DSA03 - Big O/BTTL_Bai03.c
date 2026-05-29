#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int a[100000];
int n = 10;
int b[11];

void random(int a[], int n, int l, int r)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = l + rand() % (r - l + 1);
    }
}

void insert(int a[], int* n, int v, int id, int* assignment)
{
    *assignment = 0;
    (*n)++;
    for (int i = *(n) - 1; i >= id; i--)
    {
        (*assignment)++;
        a[i] = a[i-1];
    }
    (*assignment)++;
    a[id-1] = v;
}

void solve(int k)
{
    random(a, n, -1000, 1000);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    for (int i = 0; i < k; i++)
    {
        n = 10;
        int v = rand();
        int id = rand() % 10;
        int assignment = 0;
        insert(a, &n, v, id, &assignment);
        b[assignment]++;
        printf("%d %d %d\n", v, assignment, id);
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[j]);
        }
        printf("\n");
    }
    // for (int i = 1; i <= 10; i++)
    // {
    //     printf("%d %d\n", i, b[i]);
    // }
    float s = 0;
    for (int i = 1; i <= 10; i++) s += b[i];
    printf("%f ", (float)s / k);
}

int main()
{
    time_t t;
    srand((unsigned)time(&t));
    solve(100);
    // solve(1000);
    // solve(10000);
}