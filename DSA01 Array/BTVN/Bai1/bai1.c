#include <stdio.h>
//Hàm nearestValue có tác dụng tìm phần tử trong mảng a có giá trị gần m nhất
float nearestValue(float a[100], int n, int m) {

    float min, nearestValue; //min là khoảng cách ngắn nhất, nearestValue là giá trị của phần tử trong mảng a có khoảng cách tới m là min

    //Gán giá trị min đầu ứng với khoảng cách từ a[0] đến m
    if (a[0]-m>=0) {
        min = a[0]-m;
    }
    else {
        min = m-a[0];
    }

    //Chạy vòng lặp trong mảng a để tìm và trả về min
    for (int i=1; i<n; i++) {
        if (a[i]-m>=0) {
            if (min>a[i]-m) {
                min = a[i]-m;
                nearestValue = a[i];
            }
        }
        else {
            if (min>m-a[i]) {
                min = m-a[i];
                nearestValue = a[i];
            }
        }
    }
    return nearestValue;
}

//Hàm searchIndex có tác dụng xác định index của phần tử có giá trị gần m nhất
int searchIndex(float a[100], int n, int m) {
    //Khởi tạo index ban đầu và các biến phục vụ cho việc tìm phần tử trong mảng a có khoảng cách tới m là min
    int index;
    float distance, min;

    //Gán giá trị min bằng distance đầu ứng với a[0]
    if (a[0]-m>=0) {
        distance = a[0]-m;
    }
    else {
        distance = m-a[0];
    }
    min = distance;
    
    //Chạy vòng lặp trong mảng a để tìm index 
    for (int i=1; i<n; i++) {
        if (a[i]-m>=0) {
            distance = a[i]-m;
        }
        else {
            distance = m-a[i];
        }
        if (min>distance) {
            min = distance;
            index = i; // Mỗi lần min thay đổi giá trị thì index bằng i tại lần lặp đó
        }
    }
    return index;
}
int main() {
    //Khai báo biến và mảng
    int n, m;
    float a[100];
    //Nhập n
    scanf("%d", &n);
    //Nhập lần lượt giá trị mảng a
    for (int i=0; i<n; i++) {
        scanf("%f", &a[i]);
    }
    //Nhập m
    scanf("%d", &m);
    //In kết quả
    printf("%.2f at index %d nearest to %d", nearestValue(a,n,m), searchIndex(a,n,m), m);
    return 0;
}