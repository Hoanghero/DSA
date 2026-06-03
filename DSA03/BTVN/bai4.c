#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void initializeArray(int a[], int n, int min, int max)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = min + rand() % (max - min + 1);
    }
}
void delete(int a[], int *n, int index)
{
    if (index < 0 || index > (*n) - 1)
        return;
    for (int i = index; i < (*n) - 1; i++)
    {
        a[i] = a[i + 1];
    }
    (*n)--;
}
void bubbleSort(int a[], int n, int *step)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            (*step)++;
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                (*step)++;
            }
        }
    }
}
void caseA(int a[], int *n, int k, int *step)
{
    for (int i = 0; i < *n;)
    {
        (*step)++;
        if (a[i] >= k) {
            (*step)++;
            delete(a, n, i);
        }
        else {
            i++;
        }
    }
}
void caseB(int a[], int *n, int k, int *step)
{
    bubbleSort(a, *n, step);
    for (int i = 0; i < *n; i++)
    {
        (*step)++;
        if (a[i] >= k)
        {
            *n = i;
            return;
        }
    }
}
// hàm tạo bản sao của mảng
void taobansao(int b[], int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
}
int main()
{
    time_t t;
    srand((unsigned)time(&t));
    int n1 = 100;
    int n2 = 100;
    int k = 2016;
    int a[n1];
    int b[n2];
    initializeArray(a, n1, 1998, 2023);
    taobansao(b, a, n1); // tạo bản sao của mảng A để so sánh 2 case
    int stepA = 0;
    int stepB = 0;
    caseA(a, &n1, k, &stepA);
    caseB(b, &n2, k, &stepB);
    printf("Case A: \n");
    for (int i = 0; i < n1; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nCase B: \n");
    for (int i = 0; i < n2; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\nSo buoc thuc hien trong Case A: %d\n", stepA);
    printf("So buoc thuc hien trong Case B: %d\n", stepB);
    printf("Do phuc tap thuat toan trong Case A: O(n^2)\n");
    printf("Do phuc tap thuat toan trong Case B: O(n^2)\n");
    printf("Ket luan: trong truong hop xau nhat, do phuc tap thuat toan o 2 truong hop la nhu nhau, nhung trong cac bai toan case A toi uu hon vi chi can duyet qua cac phan tu 1 lan, con caseB trong moi truong hop ta deu phai duyet hon 1 vong do sap xep.\n");
    return 0;
}
/* đánh giá thuật toán
CaseA: độ phức tạp thuật toán ở trường hợp xấu nhất:
f(n)= n (số bước so sánh) + (n-1) + (n-2) + ... + 1 (số bước trong delete) = n + n(n-1)/2 =n(n+1)/2
suy ra: O(n^2)
Case B: độ phức tạp thuật toán trong trường hợp xấu nhất: (tùy vào thuật toán sắp xếp mà mình lựa chọn, xét trong trường hợp xài Bubble sort)
f(n) = n (số bước so sánh) + n*(n-1)/2 = n(n+1)/2
suy ra: O(n^2)
Kết luận: trong trường hợp xấu nhất độ phức tạp thuật toán ở 2 trường hợp là như nhau, nhưng trong các bài toán case A tối ưu hơn
vì chỉ cần duyệt qua các phần tử 1 lần, còn caseB trong mọi trường hợp ta đều phải duyệt hơn 1 vòng do sắp xếp.
*/
