#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void sinhMang(int arr[], int n, int max, int min) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
}
int chanLe(int a) {
    if (a%2==0) return 0;
    return 1;
}
void leftOdd(int arr[], int n, int *totalComps, int *totalShifts) {
    int key;
    for (int i = 1; i < n; i++) {
        int comps = 0, shifts = 0;
        key = arr[i];
        int j = i - 1;
        if (chanLe(key)!=0){
            while (j >= 0) {
                comps++;
                if (chanLe(arr[j])==0) {
                    shifts++;
                    arr[j+1] = arr[j];
                    j--;
                }   
                else {
                    break;
                }    
            }
            arr[j+1] = key;
        }
        (*totalComps)+=comps;
        (*totalShifts)+=shifts;
    }
}
float trungBinhCong(int arr[], int n, int m) {
    float tong = 0;
    for (int i = 0; i < n; i++) {
        tong += (float)(i* arr[i]);
    }
    return tong/m;
}
int main() {
    time_t t;
    srand((unsigned)time(&t));
    int a[1001];
    int danhDauComps[1001] = {};
    int danhDauShifts[1001] = {};
    for (int i=0; i<1000; i++) {
        int totalComps = 0, totalShifts = 0;
        sinhMang(a, 10, 1000, 0);
        leftOdd(a,10, &totalComps, &totalShifts);
        danhDauComps[totalComps]++;
        danhDauShifts[totalShifts]++;
    }
    for (int l=0; l<1000; l++) {
        if (danhDauComps[l]!=0) printf("So sanh %d lan: %d\n", l, danhDauComps[l]);
    }
    printf("Mean comps: %.2f\n", trungBinhCong(danhDauComps, 1000, 1000));
    for (int l=0; l<1000; l++) {
        if (danhDauShifts[l]!=0) printf("Doi %d lan: %d\n", l, danhDauShifts[l]);
    }
    printf("Mean shifts: %.2f\n", trungBinhCong(danhDauShifts, 1000, 1000));
    printf("Complexity: O(n^2) n*(n+1)/2");
    return 0;
}