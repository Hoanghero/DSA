#include <stdio.h>
void insertArray(int a[], int n, int value, int index)
{
    if (n <= index) {
        a[index] = value;
        return;
    }
    a[n] = a[n - 1];
    insertArray(a, n - 1, value, index);
}

int main()
{
    int a[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    insertArray(a, 11, 15, 4);
    for (int i=0; i<11; i++) printf("%d ", a[i]);
    return 0;
}
/*
BASE CASE xảy ra khi: n=index, n<index
Kết quả của BASE CASE: a[index]=value
Before BASE CASE: a[index+1] = a[index]
Before Before BASE CASE: a[index+2] = a[index+1]
*/
