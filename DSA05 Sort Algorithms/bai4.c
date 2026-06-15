#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sinhMang(int arr[], int n, int max, int min) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a=*b;
    *b=temp;
}

void selectionSort(int arr[], int n, int *comps, int *swaps) {
    int min, j1;
    for (int i=0; i<n; i++) {
        min = arr[i];
        for (int j=i+1; j<n; j++) {
            (*comps)++;
            if (arr[j] < min) {
                min = arr[j];
                j1=j;
            }
        }
        if (min!=arr[i]) {
            swap(&arr[j1], &arr[i]);
            (*swaps)++;
        }
    }
}
void insertionSort (int arr[],int n,int *comps,int *shifts) {
    int key;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        int j = i - 1;

        while (j >= 0) {
            (*comps)++;
            if (arr[j] > key) {
                (*shifts)++;
                arr[j+1] = arr[j];
                j--;
            }
            else {
                break;
            }    
        }
        arr[j+1] = key;
    }
}
int main() {
    time_t t;
    srand((unsigned)time(&t));

    int arr[12], k[] = {100,1000,10000};

    for (int i = 0 ; i < 3; i++) {
        printf("Chay thu nghiem voi k = %d\n", k[i]);
        printf("%-10s %-10s %-10s\n", "So lan", "Swaps", "Shifts");
        int totalComps1=0, totalComps2=0;
        int totalSwaps=0, totalShifts=0;
        int danhdau1[1000]={0}, danhdau2[1000]={0};
        for (int j = 0; j<k[i];j++) {
            sinhMang(arr,10,1000,-1000);
            int comps1=0;
            int swaps=0;
            selectionSort(arr,10,&comps1,&swaps);
            danhdau1[swaps]++;
            totalComps1 += comps1;
            totalSwaps += swaps;   
        }
        for (int j = 0; j<k[i];j++) {
            sinhMang(arr,10,1000,-1000);
            int comps2=0;
            int shifts=0;
            insertionSort(arr,10,&comps2,&shifts);
            danhdau2[shifts]++;
            totalComps2 += comps2;
            totalShifts += shifts;    
        }
        for (int m = 0; m < 100; m++) {
            if (danhdau1[m] > 0 || danhdau2[m] > 0) {
                printf("%-10d %-10d %-10d\n", m, danhdau1[m], danhdau2[m]);
            }
        }
        printf("Trung binh so lan so sanh trong selectionSort: %.2f\n", (float)totalComps1/k[i]);
        printf("Trung binh so lan so sanh trong insertionSort: %.2f\n", (float)totalComps2/k[i]);
        printf("Trung binh so lan hoan doi trong insertionSort: %.2f\n", (float)totalSwaps/k[i]);
        printf("Trung binh so lan di chuyen trong insertionSort: %.2f\n", (float)totalShifts/k[i]);
    }

    return 0;

}