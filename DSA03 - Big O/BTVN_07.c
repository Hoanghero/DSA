#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int ascending_int(int n,int *comps) {
*comps=0;
while(n>=10) {
    (*comps)++; //đếm số lần so sánh
    if (n%10 < (n%100)/10) { //n%10 là lấy số hàng đơn vị so sánh với (n%100)/10 là chữ số hàng chục
        return -1; // nếu chữ số hàng đơn vị lớn hơn hàng chục thì kết hàm không phải số tăng dần
    }
n/=10; //bỏ chữ số cuối của số n
}
return 1;// là số tăng dần
}
int main() {
int comps; //biến đếm số phép so sánh
float sum=0; //tổng số phép so sánh
int freTable[4]={}; //bảng tần số các bước so sánh
for (int i=1000; i<10000;i++) {
int t=ascending_int(i,&comps);
freTable[comps]++;
sum+=comps;
}
float m = sum / 9000; //trung bình số phép so sánh
printf("Xet cac so tu 1000 den 9999: \n");
printf("Mean = %.2f \n",m); //in số trung bình
printf("Sum = %.2f\n",sum);// in tổng số phép so sánh
//in bảng tần số
printf("Bang tan so \n");
for (int l=1;l<4;l++) {
    printf("  %5d  |  %5d \n",l,freTable[l]);
}
return 0;
}
