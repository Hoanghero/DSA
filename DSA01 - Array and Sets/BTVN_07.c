#include <stdio.h>
#include <string.h>
//hàm so sánh
int whichIsBigger(int a, int b) {
    if (a<b) return b;
    return a;
}
//hàm tìm giá trị lớn nhất của mảng
int maxArray(int a[], int x) {
    int max = a[0];
    for (int i=0; i<x; i++) {
        if (max < a[i]) max = a[i];
    }
    return max;
}

int main() {
    //Khai báo
    int n, m, a[100], b[100], maxIndex;
    char str[100][100], str1[100][100], strfinal[200][100];
    //Cho giá trị đầu của mỗi hàng mảng 2 chiều final là kí tự \0 để tránh giá trị rác
    for (int i = 0; i < 200; i++) {
        strfinal[i][0] = '\0';
    }
    //Nhập n kích thước 
    scanf("%d", &n);

    //Mỗi loop nhập các chuỗi ban đầu, 
    //mảng a lưu giá trị số nguyên 2 kí tự đầu của chuỗi
    //copy chuỗi vào vị trí a[i] của mảng 2 chiều final
    for (int i=0; i<n; i++) {
        scanf("%s", str[i]);
        a[i] = ((str[i][0]-'0')*10 + (str[i][1]-'0'));
        strcpy(strfinal[a[i]], str[i]);
    }
    //Nhập m
    scanf("%d", &m);
    //Mỗi loop nhập chuỗi cần chèn
    //mảng b lưu giá trị số nguyên 2 kí tự đầu của chuỗi
    //copy chuỗi vào vị trí b[i] của mảng 2 chiều final
    for (int i=0; i<m; i++) {
        scanf("%s", str1[i]);
        b[i] = ((str1[i][0]-'0')*10 + (str1[i][1]-'0'));
        strcpy(strfinal[b[i]], str1[i]);
    }
    //Xác định maxIndex là chỉ số lớn nhất trong 
    //2 mảng a và b để duyệt đủ chuỗi trong strfinal
    maxIndex = whichIsBigger(maxArray(a,n), maxArray(b,m));
    //Xuất
    for (int i=0; i<=maxIndex; i++) {
        if (strlen(strfinal[i]) > 0) {
            puts(strfinal[i]);
        }
    }
    return 0;
}