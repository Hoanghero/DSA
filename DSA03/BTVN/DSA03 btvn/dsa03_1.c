#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int danhDau[10]; // tạo mảng đánh dấu cho bảng tần số

void sinhMang(float arr[], int n, int min, int max) // sinh mảng số thực
{
    for (int i = 0; i < n; i++)
        arr[i] = min + ((float)rand() / RAND_MAX) * (max - min); // gán từng phần tử là số thực
}

int minIndex(float arr[], int n, int *comps) // tìm index có giá trị nhỏ nhất
{
    int res = 0; // tạo đánh dấu cho index ban đầu
    for (int i = 0; i < n; i++)
    {
        (*comps)++;            // đếm bước so sánh
        if (arr[i] < arr[res]) // nếu phần tử đó nhỏ hơn thì đánh dấu lại
        {
            res = i; // lưu index của phần tử nhỏ nhất
        }
    }
    return res;
}

int main()
{
    srand(time(0));
    int n = 10;
    int k1 = 100;
    int k2 = 1000;
    float arr[n];
    int sum = 0;                 // tạo tổng
    for (int i = 0; i < k1; i++) // chạy test 100 lần
    {
        int comps = 0;
        sinhMang(arr, n, -2 * n, 2 * n); // sinh mảng số thực
        minIndex(arr, n, &comps);        // chạy hàm minIndex và đếm
        danhDau[comps]++;                // đánh dấu vào bảng tần số
        sum += comps;                    // tính tổng
    }
    printf("Bang tan so cua 100 lan chay:\n");
    for (int i = 1; i < 11; i++)
        printf("So lan so sanh: %d So lan xuat hien: %d\n", i, danhDau[i]); // in bảng tần số
    printf("Gia tri trung binh: %f\n", (float)sum / k1);                    // tính trung bình
    for (int i = 0; i < 11; i++)
        danhDau[i] = 0;          // reset lại mảng đánh dấu
    sum = 0;                     // reset lại tổng
    for (int i = 0; i < k2; i++) // chạy test 1000 lần
    {
        int comps = 0;
        sinhMang(arr, n, -2 * n, 2 * n); // sinh mảng số thực
        minIndex(arr, n, &comps);        // chạy hàm minIndex và đếm
        danhDau[comps]++;                // đánh dấu vào bảng tần số
        sum += comps;                    // tính tổng
    }
    printf("Bang tan so cua 1000 lan chay:\n");
    for (int i = 1; i < 11; i++)
        printf("So lan so sanh: %d So lan xuat hien: %d\n", i, danhDau[i]); // in bảng tần số
    printf("Gia tri trung binh: %f\n", (float)sum / k2);                    // tính trung bình
}