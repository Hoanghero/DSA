#include <stdio.h>
#include<time.h>
#include<stdlib.h>

int n = 10;
int a[1000];
int b[11] = {};


void random(int a[], int n, long long l, long long r)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = l + rand() % (r - l + 1);
	}
}

float average(int a[], int n)
{
	float res = 0;
	int s = 0;
	for (int i = 1; i <= n; i++)
	{
		res += i * b[i];
		s += b[i];
	}
	return res/s;
}

void linearSearch(int a[], int n, int v, int* comps)
{
	for (int i = 0; i < n; i++)
	{
		(*comps)++;
		if (a[i] == v) return;
	}
	return;
}

void test(int k)
{
	for (int i = 0; i < k; i++)
	{
		int id = rand() % n;
		int comps = 0;
		linearSearch(a, n, a[id], &comps); 
		b[comps]++;
	}
	printf("%d:\n", k);
	for (int i = 1; i <= 10; i++)
	{
		printf("so phep so sanh %d: %d lan\n", i, b[i]);
	}
	printf("trung binh cong la: %f\n", average(b, n));
	return;
}


int main()
{
	time_t t;
	srand((unsigned)time(&t));
	random(a, n, -1000, 1000);
	test(100);
	test(1000);
	test(10000);
	return 0;
}