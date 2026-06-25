#include <stdio.h>
void insertOrderedArray(int *a, int *n, int value) {
    for (int i=0; i<*n; i++) {
        if (a[i]>value) {
            (*n)++;
            for (int j=*n; j>i; j--) {
                a[j] = a[j-1];
            }
            a[i] = value;
            break;
        }
    }
}
int main() {
    int n, a[100], value;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &value);
    insertOrderedArray(a,&n,value);
    for (int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}