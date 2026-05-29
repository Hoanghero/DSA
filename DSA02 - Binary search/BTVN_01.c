#include <stdio.h>

void insertOrderedArray(float a[], int *n, float value) {
    int i = *n - 1; // Khởi tạo biến chỉ số bắt đầu từ phần tử cuối cùng của mảng
    while (i >= 0 && a[i] > value) { // Vòng lặp chạy khi chưa vượt quá biên trái và phần tử hiện tại lớn hơn giá trị chèn
        a[i + 1] = a[i]; // Dịch chuyển phần tử hiện tại sang phải một vị trí để tạo khoảng trống
        i--; // Giảm chỉ số để tiếp tục kiểm tra phần tử kế tiếp về phía bên trái
    }
    a[i + 1] = value; // Đặt giá trị cần chèn vào vị trí thích hợp đã được
    (*n)++; // Tăng kích thước của mảng thêm một đơn vị sau khi chèn
}

int orderedLinearSearch(float a[], int n, float value) {
    for (int i = 0; i < n; i++) { // Duyệt tuyến tính qua từng chỉ số từ đầu mảng đến cuối mảng
        if (a[i] == value) { // So sánh phần tử tại chỉ số hiện tại với giá trị cần tìm kiếm
            return i; // Trả về chỉ số ngay khi phát hiện
        }
    }
    return -1; // Trả về -1 sau khi duyệt hết mảng mà không tìm thấy giá trị yêu cầu
}

int binarySearch(float a[], int n, float value) {
    int lower = 0; // Khởi tạo biên dưới của vùng tìm kiếm tại vị trí đầu mảng
    int upper = n - 1; // Khởi tạo biên trên của vùng tìm kiếm tại vị trí cuối mảng
    int result = -1; // Khởi tạo biến lưu trữ kết quả mặc định là không tìm thấy (-1)
    while (lower <= upper) { // Vòng lặp điều kiện tiếp diễn khi phạm vi tìm kiếm còn hợp lệ
        int mid = lower + (upper - lower) / 2; // Xác định chỉ số phần tử ở chính giữa phân vùng hiện tại
        if (a[mid] == value) { // Kiểm tra nếu phần tử tại vị trí giữa bằng với giá trị cần tìm
            result = mid; // Ghi nhận chỉ số hiện tại vào biến kết quả tiềm năng
            upper = mid - 1; // Tiếp tục thu hẹp phạm vi sang nửa bên trái để tìm kiếm vị trí xuất hiện sớm hơn
        } else if (a[mid] < value) { // Trường hợp phần tử giữa nhỏ hơn giá trị cần tìm
            lower = mid + 1; // Loại bỏ nửa bên trái bằng cách dịch chuyển biên dưới lên sau vị trí giữa
        } else { // Trường hợp phần tử giữa lớn hơn giá trị cần tìm
            upper = mid - 1; // Loại bỏ nửa bên phải bằng cách dịch chuyển biên trên về trước vị trí giữa
        }
    }
    return result; // Trả về chỉ số đầu tiên tìm thấy hoặc -1 nếu phần tử không tồn tại
}

int main(){
    int n; // Khai báo biến số lượng phần tử
    scanf("%d", &n); // nhập vào số lượng phần tử
    float a[1000]; // mảng số thực chứa tối đa 1000 phần tử
    for(int i=0; i<n;i++){
        scanf("%f", &a[i]); //nhập mảng từ bàn phím
    }
    float value; //Khai báo số cần tìm
    scanf("%f", &value); // Nhập số cần tìm từ bàn phím

    insertOrderedArray(a, &n, value);
    printf("Mảng sau khi chèn:\n");
    for (int i = 0; i < n; i++) printf("%.2f ", a[i]);
    printf("\n%d", orderedLinearSearch(a, n, value));
    printf("\n%d", binarySearch(a, n, value));
    return 0; 
}