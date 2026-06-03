#include <stdio.h>
int orderedLinearSearch(int *a, int n, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (value == a[i])
            return i;
        else { 
            if (value < a[i]) break;
        }
    }
    return -1;
}
int main() {
    int n;
    scanf("%d", &n);
    int a[100];
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    int value;
    scanf("%d", &value);
    int id = orderedLinearSearch(a,n,value);
    if (id == -1) {
        printf("Not found!");
    }
    else {
        printf("%d", id);
    }
    return 0;
}