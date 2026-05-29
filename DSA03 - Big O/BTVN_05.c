#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//hàm tính tổng các giá trị âm trong mảng số nguyên
int negative_sum(int a[], int n, int *count) {
*count =0; //reset số phép đếm
int sum=0;
for (int i=0; i<n;i++) {
    if(a[i]<0) {
        sum+=a[i];
        (*count)++;
    }
}
return sum;
}
// hàm sinh mảng số nguyên bất kì
void initializeArray (int a[], int n, int min, int max) {
for (int i=0; i<n;i++) {
    a[i] = min + rand() % (max - min +1);
}
}
int main() {
    time_t t;
    srand((unsigned)time(&t));

    int n = 10;
    int a[1000];
    int k=1000;
    int min = -100;
    int max = 100;
    int count; //biến đếm số phép gán
    int freTable[1001] = {}; //tạo bảng tần số với tất cả phần tử bằng 0. Tối đa n phép gán
        for(int j = 0; j<k; j++){
            n=10;
            initializeArray(a,n,min,max);
            negative_sum(a,n,&count);
            freTable[count]++;
        }
        printf("k = %d; Mean = ",k);
        float sum = 0;
        for (int l = 0; l < 11; l++){
            sum += l*freTable[l];
        }
        sum /= k;
        printf("%f\n",sum);
        //In bảng tần số
        printf("Bang tan so: \n");
        printf("%-10s | %-10s\n", "Comps","Tan suat");
        for (int i=1; i<11; i++) {
            printf("%10d |  %10d\n",i,freTable[i]);
        }
        printf("----//---- \n");
    return 0;
}
