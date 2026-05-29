#include <stdio.h>
#include <string.h>
/*
 * Hàm: checkMaDoc
 * Công dụng: Kiểm tra xem tại vị trí 'index' trong chuỗi 's' có khớp với chuỗi 'z' hay không.
 * Trả về: 1 nếu khớp, 0 nếu không khớp.
 */
int checkMaDoc(char *s, char *z, int index) {
    int len = strlen(z);
    int count = 0;
    // Kiểm tra ký tự đầu tiên để tối ưu tốc độ so sánh
    if (s[index] - z[0] == 0) {
        count++;
        // Duyệt các ký tự tiếp theo của chuỗi z
        for (int j = index + 1; j < len + index; j++) {
            if (s[j] - z[j - index] == 0) count++;
        }
    }
    // Nếu số ký tự khớp bằng chiều dài chuỗi cần tìm thì trả về đúng
    if (count == len) return 1;
    return 0;
}
/*
 * Hàm: xoaChuoi
 * Công dụng: Xóa một đoạn ký tự có độ dài bằng chuỗi 'z' tại vị trí 'index'.
 * Cách làm: Dồn các ký tự phía sau về trước để lấp đầy khoảng trống.
 */
void xoaChuoi(char *s, char *z, int index, int *n) {
    int len1 = strlen(z);
    // Dịch chuyển các ký tự từ sau vị trí cần xóa lên phía trước
    for (int i = index; i < *n - len1; i++) {
        s[i] = s[i + len1];
    }
    // Đặt ký tự kết thúc chuỗi mới và cập nhật lại độ dài chuỗi n
    s[*n - len1] = '\0';
    (*n) -= len1;
}
/*
 * Hàm xoaMaDoc
 * Công dụng: Duyệt toàn bộ chuỗi s và gọi hàm xóa mỗi khi tìm thấy maDoc.
 */
void xoaMaDoc(char *s, char *maDoc) {
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        // Sử dụng while để kiểm tra lại chính vị trí đó sau khi xóa
        // Điều này giúp xử lý trường hợp các mã độc lồng nhau (vừa xóa xong lại hiện ra cái mới)
        while (checkMaDoc(s, maDoc, i)) {
            xoaChuoi(s, maDoc, i, &len);
        }
    }
}
int main() {
    char maDoc[10][1000]; // Mảng 2 chiều lưu danh sách các mã độc
    char s[10001];        // Chuỗi văn bản gốc
    // Nhập chuỗi văn bản gốc
    gets_s(s, 10000);
    int k;
    // Nhập số lượng loại mã độc
    scanf("%d", &k);
    getchar(); // Xóa bộ nhớ đệm để tránh trôi lệnh nhập tiếp theo
    // Vòng lặp nhập từng chuỗi mã độc
    for (int i = 0; i < k; i++) gets_s(maDoc[i], 999);
    // Thực hiện xóa lần lượt từng loại mã độc trong danh sách
    for (int i = 0; i < k; i++) 
    {
        xoaMaDoc(s, maDoc[i]);
    }
    // In kết quả cuối cùng sau khi đã sạch "mã độc"
    puts(s);
    return 0;
}