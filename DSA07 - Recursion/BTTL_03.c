#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void insertArray(int a[], int n, int value, int index)
{
	if (n <= index)
	{
		a[index] = value;
		return;
	}
	a[n] = a[n-1];
	insertArray(a, n - 1, value, index);
}

int main()
{
	time_t t;
	srand((unsigned) time (&t));
	int n = 10;
	int a[101] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int id, value; scanf("%d %d", &id, &value);
	insertArray(a, n, value, id);
	// for (int i = 0; i < )
	return 0;
}