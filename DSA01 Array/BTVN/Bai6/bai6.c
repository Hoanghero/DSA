#include <stdio.h>
//Hàm thêm phần tử b vào vị trí c
void addArray(float a[], float b, int c, int *n) {
    (*n)++;
    for (int i=*n; i>=c; i--) {
        a[i+1] = a[i];
    }
    a[c] = b; 
}

int main() {
    //Khai báo
    int n, m, c[100];
    float a[100], b[100];
    //Nhập
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%f", &a[i]);
    }
    scanf("%d", &m);
    //Chạy vòng lặp thêm các phần tử trong danh sách vào mảng
    //mỗi loop nhập giá trị b[i], vị trí c[i], sau đó gọi hàm
    for (int i=0; i<m; i++) {
        scanf("%f", &b[i]);
        scanf("%d", &c[i]);
        addArray(a, b[i], c[i]+i, &n);
    }
    //In mảng
    for (int i=0; i<n; i++) {
        printf("%.1f ", a[i]);
    }
    return 0;
}