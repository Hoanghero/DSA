#include <stdio.h>

void insertionSort (int arr[],int n, int *totalComps, int *totalShifts) {
    int key;
    for (int i = 1; i < n; i++) {
        int comps = 0, shifts = 0;
        key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comps++;
            if (arr[j] > key) {
                shifts++;
                arr[j+1] = arr[j];
                j--;
            }
            else {
                break;
            }    
        }
        arr[j+1] = key;
        printf("%-10d %-10d %-10d ", i, comps, shifts);
        for (int u=0; u<n; u++) printf("%d ", arr[u]);
        printf("\n");
        (*totalComps)+=comps;
        (*totalShifts)+=shifts;
    }
}

int main() {
    int a[100], n;
    int totalComps=0, totalShifts=0;
    scanf("%d", &n);
    printf("Mang ban dau: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("%-10s %-10s %-10s %-10s\n","Vong thu","Comps","Shifts","Mang luc nay");
    insertionSort(a,n, &totalComps, &totalShifts);
    printf("Tong so buoc so sanh %d\n", totalComps);
    printf("Tong so buoc doi %d\n",totalShifts);
    printf("Mang sau khi duoc sap xep: ");
    for (int i=0; i<n; i++) printf("%d ", a[i]);
    return 0;
}