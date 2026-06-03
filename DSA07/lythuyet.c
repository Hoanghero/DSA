#include <stdio.h>
// Cho mảng số ngyên arr có 10 phần tử. 
//Tính tổng tất cả phần tử trong mảng số nguyên bằng 2 phương pháp: dùng vòng lặp và đệ quy.
//So sánh quy trình tính của 2 phương pháp này.
void loop(int *arr, int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
}
void recursion(int *arr, int n) {
    if (n==9) {
        printf("%d ", arr[9]);
        return;
    }
    printf("%d ", arr[n]);
    recursion(arr, n+1);
}
/*
1. Base case  xảy ra khi: n = 0 hoặc n = 2.
2. Kết quả của Base Case:
    - Với n = 0, f(0) = 2.
    - Với n = 2, f(2) = 4.
3. Before Base Case: n = 3, f(3) = 6;
4. Before Before Base Case: n = 4, f(3) = ;
*/
int main() {
    int arr[10] = {3,5,2,6,4,7,10,4,7,8};
    loop(arr, 10);
    printf("\n");
    recursion(arr, 0);
    return 0;
}