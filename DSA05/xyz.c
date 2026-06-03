#include <stdio.h>
int comps=0;
void sort(int a[], int n) {
    int key;
    for (int i = 1; i < n; i++) {
        key = a[i];
        int j = i - 1;
        while (j >= 0) {
            if (a[j] > key) {
                a[j+1] = a[j];
                j--;
            }
            else {
                break;
            }    
        }
        a[j+1] = key;
    }
}
int arithmeticTripleNumber(int a[], int n) {
    int count=0;
    int b[100];
    for (int i=0; i<n; i++) b[i]=a[i];
    sort(b, n);
    for (int i=1; i<n-1; i++) {
        int l=i-1;
        int r=i+1;
        while (l>=0 && r<=n-1) {
            comps++;
            if (b[i]*2 == b[l]+b[r]) {
                count++;
                l--;
                r++;
            }
            else if (b[i]*2>b[l]+b[r]) {
                comps++;
                r++;
            }
            else {
                comps++;
                l--;
            }
        }
    }
    return count;
}
int main() {
    int a[6]={1,2, 3, 5, 7, 13};
    comps=0;
    int d = arithmeticTripleNumber(a, 6);
    printf("%d", d);
    return 0;
}