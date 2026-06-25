#include <stdio.h>
int binarySearch(int *a, int n, int value) {
    int lower=0;
    int upper=n-1;
    while (lower<=upper) {
        int midpoint = (lower+upper)/2;
        int valueAtMid = a[midpoint];
        if (value == valueAtMid) {
            return midpoint;
            break;
        }
        else if (value < valueAtMid) {
            upper = midpoint - 1;
        }
        else {
            lower = midpoint + 1;
        }
    }
    return -1;
}
int main() {
    int n, value, a[100];
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &value);
    int c = binarySearch(a,n,value);
    if (c==-1) printf("Not found!");
    else {
        printf("%d", c);
    }
    return 0;
}