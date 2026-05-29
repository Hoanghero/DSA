    #include <stdio.h>
    #include <time.h>
    #include <stdlib.h>


    int a[100];
    int n = 10;
    int b[11];


    void random(int a[], int n, int l, int r)
    {
        for (int i = 0; i < n; i++)
        {
            a[i] = l + rand() % (r - (n - i - 1) - l + 1);
            l = a[i] + 1;
        }
    }

    float average(int a[], int n)
    {
        float res = 0;
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            res += i * a[i];
            s += a[i];
        }
        return res / s;
    }

    void bisect(int a[], int n, int v, int * loops)
    {
        int l = 0, r = n - 1;
        while(l <= r)
        {
            int m = l + (r - l)/2;
            if (a[m] < v)
            {
                (*loops)++;
                l = m + 1;
            }
            else if (a[m] > v)
            {
                (*loops)++;
                r = m - 1;
            }
            else
            {
                (*loops)++;
                return;
            }
        }
        return;
    }

    void test(int k)
    {
        printf("%d:\n", k);
        for (int i = 1; i <= n; i++) b[i] = 0;
        for (int i = 0; i < k; i++)
        {
            int loops = 0;
            bisect(a, n, a[rand() % n], &loops);
            b[loops]++;
        }
        for (int i = 1; i <= n; i++)
        {
            printf("%d %d\n", i, b[i]);
        }
        printf("trung binh cong la: %f\n\n", average(b, n));
    }

    int main()
    {
        time_t t;
        srand((unsigned)time(&t));
        random(a, n, -1000, 1000);
        for (int i = 0; i < n; i++) printf("%d ", a[i]);
        printf("\n\n");
        test(100);
        test(1000);
        test(10000);    
    }