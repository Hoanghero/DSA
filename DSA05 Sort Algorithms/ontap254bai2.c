#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int comps=0;
void initializeArray(int arr[], int n, int min, int max){
    for (int i=0; i<n;i++){
        arr[i]=min+rand() % (max-(n-i-1)-min+1);
        min = arr[i]+1;
    }
}

int arithmeticTripleNumber(int a[], int n) {
    int count=0;
    int b[100];
    for (int i=0; i<n; i++) b[i]=a[i];
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
float Mean(int arr[], int n, int m) {
    float tong = 0;
    for (int i = 0; i < n; i++) {
        tong += (float)(i* arr[i]);
    }
    return tong/m;
}
int main() {
    time_t t;
    srand((unsigned)time(&t));
    int a[20], danhDau[1000]={};
    for (int i=0; i<1000; i++) {
        initializeArray(a, 20, -200, 200);
        comps=0;
        arithmeticTripleNumber(a, 20);
        danhDau[comps]++;
    }
    printf("Bang tan so\n");
    for (int l=0; l<1000; l++) {
        if (danhDau[l]!=0) printf("So sanh %d lan:      %d\n", l, danhDau[l]);
    }
    printf("Mean: %.2f\n", Mean(danhDau, 1000, 1000));
    printf("Big O: O(n^2) boi vi ham arithmeticTripleNumber chay 2 vong lap");
    return 0;
}