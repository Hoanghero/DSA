#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int danhDau[821]; // tạo mảng đánh dấu cho bảng tần số

void sinhMang(float arr[], int n, int min, int max) // sinh mảng số thực
{
    for (int i = 0; i < n; i++)
        arr[i] = min + ((float)rand() / RAND_MAX) * (max - min); // gán từng phần tử là số thực
}

void sort(float arr[], int n, int *comps) // hàm sắp xếp mảng
{
    for (int i = 0; i < n; i++) // chạy qua tất cả phần tử
    {
        int minIndex = i;           // tạo đánh dấu cho index phàn tử ban đầu
        for (int j = i; j < n; j++) // chạy tất cả phần tử trở về sau
        {
            (*comps)++;                 // đếm số bước so sánh
            if (arr[j] < arr[minIndex]) // nếu xuất hiện phần tử bé hơn đánh dấu thì gán lại index của phần tử bé nhất
            {
                minIndex = j;
            }
        }
        float temp = arr[minIndex]; // tạo biến tạm thời lưu giá trị của giá trị nhỏ nhất
        arr[minIndex] = arr[i];     // đổi chỗ 2 giá trị tại i và giá trị nhỏ nhất
        arr[i] = temp;
    }
}

int main()
{
    srand(time(0));
    int n = 40;
    float arr[n];            // tạo mảng 40 phần tử
    int comps = 0;           // tạo biến đếm
    sinhMang(arr, n, 0, 10); // sinh mảng 40 phần tử số thực từ 0 đến 10
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]); // in mảng ngẫu nhiên đã sinh
    printf("\n\n");
    sort(arr, n, &comps); // sắp xếp lại mảng
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);     // in mảng sau khi đã sắp xếp để kiểm tra
    printf("\n%d\n", comps);       // in số bước đếm
    int sum = 0;                   // tạo biến tổng
    for (int i = 0; i < 1000; i++) // chạy 1000 test
    {
        int comps = 0;           // tạo biến đếm số bước so sánh
        sinhMang(arr, n, 0, 10); // sinh mảng số thực từ 0 đến 10
        sort(arr, n, &comps);    // sắp xếp lại mảng và đếm
        danhDau[comps]++;        // đánh dấu bước đếm vào bảng tần số
        sum += comps;            // tính tổng
    }
    for (int i = 0; i < 821; i++)
    {
        if (danhDau[i] != 0)
            printf("So lan so sanh: %d| So lan xuat hien: %d", i, danhDau[i]); // in bảng tần số những số bước khác 0
    }
    printf("\nSo buoc trung binh: %f", (float)sum / 1000); // in số bước trung bình
}