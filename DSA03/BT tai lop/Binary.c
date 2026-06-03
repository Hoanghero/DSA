#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void binary_search(int a[], int n, int value, int *loops){
    (*loops)=0;
    int lower =0;
    int upper =n-1;
    while (lower<=upper){
        (*loops)++;
        int midpoint = (upper+lower)/2;
        int value_at_midpoint = a[midpoint];
        if(value < value_at_midpoint){
            upper=midpoint-1;
        }
        else if(value > value_at_midpoint){
            lower= midpoint+1;
        }
        else if(value==value_at_midpoint){
            return;
        }
    }
}
void sinhMangTang(int arr[], int n, int min, int max){
    for (int i=0; i<n;i++){
        arr[i]=min+rand() % (max-(n-i-1)-min+1);
        min = arr[i]+1;
    }
}
int main(){
    time_t t;
    srand((unsigned)time(&t));
    int k[] ={100, 1000, 10000};
    int arr[100];
    for(int i=0; i<3;i++){
        float tong=0;
        int tanso[11]={};
        for (int u=0; u<k[i]; u++) {
            initializeArray(arr,10,-1000,1000);
            int index=rand() % 10;
            int value =arr[index];
            int loops =0;
            binary_search(arr,10,value,&loops);
            tanso[loops]++;
        }
        for(int j=1; j<=10;j++){
            tong += j * tanso[j];
        }
        for (int i = 1; i <= 10; i++)
        {
            printf("%d %d \n", i, tanso[i]);
        }
        printf("k = %d; Mean = ", k[i]);
        tong /= k[i];
        printf("%.2f\n", tong);
    }
    return 0;
}