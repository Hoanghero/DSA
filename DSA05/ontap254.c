#include <stdio.h>
void fixArray(int a[], int n, int *totalComps, int *totalShifts) {
    int key;
    for (int i = 1; i < n; i++) {
        int comps = 0, shifts = 0;
        key = a[i];
        int j = i - 1;
        while (j >= 0) {
            comps++;
            if (a[j] > key) {
                shifts++;
                a[j+1] = a[j];
                j--;
            }
            else {
                break;
            }    
        }
        a[j+1] = key;
        (*totalComps)+=comps;
        (*totalShifts)+=shifts;
    }
}
int main() {
    int n, a[100], totalComps=0, totalShifts=0;
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    fixArray(a, n, &totalComps, &totalShifts);
    printf("So buoc so sanh: %d\n", totalComps);
    printf("So buoc doi: %d", totalShifts);
    return 0;
}