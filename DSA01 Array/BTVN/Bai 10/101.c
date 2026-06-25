#include <stdio.h>
#include <string.h>
// Định nghĩa cấu trúc để lưu trữ thông tin về một loại mã độc
typedef struct poison {
    char maDoc[10001]; // Nội dung chuỗi mã độc
    int viTri[100];    // Mảng lưu các vị trí (index) tìm thấy mã độc trong chuỗi gốc
} poison;
/*
 * Hàm: timMaDoc
 * Công dụng: Tìm kiếm tất cả các lần xuất hiện của một mã độc trong chuỗi s
 * Các bước:
 * 1. Duyệt qua từng ký tự của chuỗi s.
 * 2. Tại mỗi vị trí i, so sánh chuỗi con bắt đầu từ s[i] với maDoc.
 * 3. Nếu khớp hoàn toàn, tăng biến soluong và lưu chỉ số i vào mảng viTri của struct.
 */
void timMaDoc(char s[10001], poison *a, char maDoc[10001], int *soluong) {
    int len = strlen(s);
    int len1 = strlen(maDoc);
    int count1 = 0; // Biến phụ để đếm và gán chỉ số vào mảng viTri
    for (int i = 0; i < len; i++) {
        int count = 0;
        // Kiểm tra nếu ký tự đầu tiên trùng khớp thì mới kiểm tra các ký tự tiếp theo
        if (s[i] - maDoc[0] == 0) {
            count++;
            for (int j = i + 1; j < len1 + i; j++) {
                // Kiểm tra các ký tự còn lại của mã độc
                if (s[j] - maDoc[j - i] == 0) count++;
            }
        }
        // Nếu số ký tự trùng khớp bằng chiều dài mã độc -> tìm thấy 1 mẫu
        if (count == len1) {
            (*soluong)++;          // Tăng tổng số lượng tìm thấy (dùng con trỏ để cập nhật về main)
            a->viTri[count1] = i;  // Lưu vị trí bắt đầu vào struct
            count1++;
        }
    }
}
int main() {
    poison a[100];     // Danh sách các cấu trúc mã độc
    int soluong;       // Biến tạm để lưu số lần xuất hiện của mã độc hiện tại
    char s[10001];     // Chuỗi gốc cần kiểm tra
    // Nhập chuỗi văn bản gốc
    gets_s(s, 10000);
    int k;
    // Nhập số lượng loại mã độc cần tìm
    scanf("%d", &k);
    getchar(); // Xóa bộ nhớ đệm (tránh trôi lệnh khi dùng gets_s phía sau)
    // Nhập nội dung cho từng loại mã độc
    for (int i = 0; i < k; i++) {
        gets_s(a[i].maDoc, 10000);
    }
    // Duyệt qua từng loại mã độc để tìm kiếm và in kết quả
    for (int i = 0; i < k; i++) 
    {
        soluong = 0; // Reset số lượng về 0 trước mỗi lần tìm kiếm mới
        /*
         * Gọi hàm tìm kiếm mã độc:
         * Truyền vào chuỗi gốc s, địa chỉ struct của mã độc thứ i, 
         * nội dung mã độc và địa chỉ biến soluong.
         */
        timMaDoc(s, &a[i], a[i].maDoc, &soluong);
        // In kết quả: [Số lượng] [Nội dung mã độc]
        printf("%d %s ", soluong, a[i].maDoc);

        // Nếu tìm thấy ít nhất 1 vị trí, tiến hành in danh sách các vị trí
        if (soluong != 0) {
            for (int j = 0; j < soluong - 1; j++) {
                printf("%d, ", a[i].viTri[j]);
            }
            // In vị trí cuối cùng (không có dấu phẩy sau cùng)
            printf("%d", a[i].viTri[soluong - 1]);
        }
        printf("\n"); // Xuống dòng cho loại mã độc tiếp theo
    }
    return 0;
}