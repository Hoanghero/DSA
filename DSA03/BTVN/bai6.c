#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sinhMang(int arr[], int n, int max, int min) // Sinh mảng ngẫu nhiên
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = min + rand() % (max - min + 1); // Gán từng phần tử một giá trị ngẫu nhiên
    }
}

int maximumProduct(int arr[], int n, int *steps, int *assigments) // Hàm tìm giá trị tích lớn nhất
{
    if (n < 2)
        return 0;                   // Nếu mảng có ít hơn 2 phần tử trả về 0
    (*steps) = 0;                   // Reset steps
    (*assigments) = 0;              // Reset assignments
    int res = arr[0] * arr[1];      // Khởi tạo kết quả giả định bằng tích 2 phần tử đầu
    for (int i = 0; i < n - 1; i++) // Chạy vòng lặp cho phần tử đầu
    {
        for (int j = i + 1; j < n; j++) // Chạy vòng lặp cho phần tử thứ hai
        {
            (*steps)++;                // Đếm số bước nhân
            if (arr[i] * arr[j] > res) // Nếu tích 2 phần tử duyệt qua lớn hơn kết quả giả định thì gán cho kết quả giả định
            {
                res = arr[i] * arr[j];
                (*assigments)++; // Đếm số bước gán
            }
        }
    }
    return res; // Trả về tích lớn nhất
}

int danhDau[100] = {}; // Tạo mảng đánh dấu cho bảng tần số

int main()
{
    int n = 4;
    int arr[n]; // Tạo mảng 4 phần tử
    srand(time(0));
    sinhMang(arr, n, 100, 1); // Sinh mảng từ 4 phần tử ngẫu nhiên từ 1 đến 100
    int steps = 0;
    int assignments = 0;
    printf("Mang ban dau:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);                                                                     // In mảng ban đầu
    printf("\nTich lon nhat: %d| Steps: %d", maximumProduct(arr, n, &steps, &assignments), steps); // In kết quả tích lớn nhất và số bước nhân
    printf("\nSo buoc nhan theo N la steps = (N - 1) * N / 2 hay co do phuc tap O(N^2)");          // In độ phức tạp thuật toán
    int sum = 0;                                                                                   // Khởi tạo tổng cho thống kê
    for (int i = 0; i < 10000; i++)                                                                // Chạy thử 10000 lần
    {
        sinhMang(arr, n, 100, 1);                     // Sinh mảng ngẫu nhiên
        maximumProduct(arr, n, &steps, &assignments); // Chạy hàm tích tối đa
        sum += assignments;                           // Tính tổng số lần gần
        danhDau[assignments]++;                       // Đánh dấu số lần gán
    }
    printf("\nBang tan so:");
    for (int i = 0; i < 100; i++) // In bảng tần số
    {
        if (danhDau[i] != 0)
        {
            printf("\nSo lan gan: %d| Tan so: %d", i, danhDau[i]);
        }
    }
    printf("\nSo lan gan trung binh: %f", (float)sum / 10000); // In số lần gán trung bình
}