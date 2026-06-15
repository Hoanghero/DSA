#include <stdio.h>
#include <string.h>

/* Hàm: binarySearch
 * Công dụng: Tìm kiếm nhị phân một ký tự trong chuỗi đã sắp xếp.
 * Trả về: Vị trí (index) của ký tự nếu tìm thấy, ngược lại trả về -1.
 */
int binarySearch(char *s, char value) {
    int len = strlen(s);
    int lower=0;
    int upper=len-1;
    while (lower<=upper) {
        int midpoint = (lower+upper)/2;
        int valueAtMid = s[midpoint];
        if (value == valueAtMid) {
            return midpoint; // Tìm thấy giá trị, trả về vị trí ngay lập tức
            break;
        }
        else if (value < valueAtMid) {
            upper = midpoint - 1; // Thu hẹp phạm vi tìm kiếm sang nửa trái
        }
        else {
            lower = midpoint + 1; // Thu hẹp phạm vi tìm kiếm sang nửa phải
        }
    }
    return -1; // Không tìm thấy ký tự trong chuỗi
}

/* Hàm: checkMissingChar
 * Công dụng: Duyệt qua bảng chữ cái (a-z) để tìm ký tự đầu tiên không xuất hiện trong chuỗi.
 * Giải thuật: Sử dụng mã ASCII (97 là 'a') và hàm binarySearch để kiểm tra từng chữ cái.
 */
int checkMissingChar(char *s) {
    for (int i=0; i<26; i++) {
        // 97 + i tương ứng với 'a', 'b', 'c',...
        if (binarySearch(s, 97+i)==-1) {
            return i; // Trả về số thứ tự của ký tự còn thiếu (0 cho 'a', 1 cho 'b',...)
        }
    }
    return -1;
}

/* Hàm: insert
 * Công dụng: Chèn một ký tự vào một vị trí cụ thể trong chuỗi và dịch chuyển các ký tự sau nó.
 * Tham số: n là con trỏ đến độ dài chuỗi để cập nhật độ dài mới sau khi chèn.
 */
void insert(char *s, char a, int *n, int index) {
    (*n)++; // Tăng độ dài chuỗi lên 1
    // Dịch chuyển các phần tử từ cuối chuỗi sang phải để tạo chỗ trống tại 'index'
    for (int i=*n; i>index;i--) {
        s[i] = s[i-1]; 
    }
    s[index] = a; // Đặt ký tự mới vào vị trí trống đã tạo
}

int main() {
    char s[1000];
    char x;
    
    // Nhập chuỗi đầu vào (giả định chuỗi đã được sắp xếp)
    scanf("%s", s);
    int len = strlen(s);
    
    // Bước 1: Tìm và thông báo ký tự đầu tiên còn thiếu cùng vị trí thứ tự của nó
    printf("%c at %d is missing!\n", 97+checkMissingChar(s), checkMissingChar(s));
    
    // Bước 2: Lưu ký tự còn thiếu vào biến x
    x = 97+checkMissingChar(s);
    
    // Bước 3: Chèn ký tự thiếu đó vào chuỗi tại vị trí tương ứng
    insert(s, x, &len, checkMissingChar(s));
    
    // Bước 4: In ra chuỗi mới sau khi đã chèn thêm ký tự
    printf("%s", s);
    
    return 0;
}