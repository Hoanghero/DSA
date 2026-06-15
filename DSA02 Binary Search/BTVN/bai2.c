#include <stdio.h>
#include <string.h>

/* Hàm: checkIncrease
 * Công dụng: Kiểm tra xem chuỗi ký tự có được sắp xếp tăng dần hay không.
 * Trả về: 1 nếu chuỗi tăng dần, 0 nếu có bất kỳ phần tử nào nhỏ hơn phần tử đứng trước nó.
 */
int checkIncrease (char *s) {
    int len = strlen(s)-1;
    for (int i=0; i<len; i++) {
        // Chuyển ký tự số sang số nguyên để so sánh
        if ((s[i+1]-'0') < (s[i]-'0')) {
            return 0; // Phát hiện phần tử đứng sau nhỏ hơn đứng trước
        }
    }
    return 1; // Chuỗi hoàn toàn tăng dần
}

/* Hàm: linearSearch
 * Công dụng: Tìm kiếm tuần tự một ký tự trong chuỗi đã sắp xếp.
 * Giải thuật: Duyệt từ đầu chuỗi, nếu ký tự tại vị trí i lớn hơn giá trị tìm kiếm 
 * thì dừng lại sớm để tiết kiệm thời gian (vì chuỗi đã tăng dần).
 */
int linearSearch(char *s, char value)
{
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (value == s[i])
            return i; // Tìm thấy, trả về chỉ số (index)
        else { 
            if (value < s[i]) break; // Giá trị cần tìm nhỏ hơn s[i] thì chắc chắn không nằm phía sau
        }
    }
    return -1; // Không tìm thấy
}

/* Hàm: binarySearch
 * Công dụng: Tìm kiếm nhị phân một ký tự trong chuỗi đã sắp xếp.
 * Giải thuật: Chia đôi phạm vi tìm kiếm liên tục dựa trên việc so sánh 
 * giá trị tìm kiếm với phần tử ở giữa (midpoint).
 */
int binarySearch(char *s, char value) {
    int len = strlen(s);
    int lower=0;
    int upper=len-1;
    while (lower<=upper) {
        int midpoint = (lower+upper)/2;
        int valueAtMid = s[midpoint];
        if (value == valueAtMid) {
            return midpoint; // Tìm thấy, trả về chỉ số
            break;
        }
        else if (value < valueAtMid) {
            upper = midpoint - 1; // Thu hẹp phạm vi về bên trái
        }
        else {
            lower = midpoint + 1; // Thu hẹp phạm vi về bên phải
        }
    }
    return -1; // Không tìm thấy
}

int main() {
    char s[1000];
    char value;
    
    // Nhập chuỗi và ký tự cần tìm
    gets_s(s, 999);
    scanf("%c", &value);
    
    // Kiểm tra tính tăng dần của chuỗi đầu vào
    if (checkIncrease(s)) {
        // Nếu chuỗi tăng dần, thực hiện cả hai thuật toán tìm kiếm và in kết quả
        printf("Step linear: %d\nStep binary: %d\n", linearSearch(s,value), binarySearch(s,value));
    }
    else {
        // Thông báo nếu chuỗi không thỏa mãn điều kiện sắp xếp
        printf("Chuoi khong tang");
    }
    
    return 0;
}