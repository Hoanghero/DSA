#include <stdio.h>
#include <string.h>
/*
 * Hàm: insert
 * Công dụng: Chèn một ký tự 'a' vào vị trí 'index' trong chuỗi 's'
 * Các bước: Tăng độ dài n, đẩy toàn bộ ký tự từ index về sau, chèn a vào chỗ trống.
 */
void insert(char *s, char a, int *n, int index) {
    (*n)++;
    for (int i = *n; i > index; i--) {
        s[i] = s[i - 1];
    }
    s[index] = a;
}
/*
 * Hàm: insertString
 * Công dụng: Chèn cả một chuỗi 'z' vào vị trí 'index' trong chuỗi 's'
 */
void insertString(char *s, char *z, int *n, int index) {
    int n1 = strlen(z);
    (*n) += n1;
    // Dịch chuyển mảng s sang phải n1 đơn vị để tạo khoảng trống cho chuỗi z
    for (int i = *n; i > index + n1 - 1; i--) {
        s[i] = s[i - n1];
    }
    // Sao chép nội dung chuỗi z vào khoảng trống vừa tạo
    for (int j = 0; j < n1; j++) {
        s[index + j] = z[j]; 
    }
}
/*
 * Hàm: checkMaDoc
 * Công dụng: Kiểm tra sự tồn tại của mã độc z tại vị trí index của s
 */
int checkMaDoc(char *s, char *z, int index) {
    int len = strlen(z);
    int count = 0;
    if (s[index] - z[0] == 0) {
        count++;
        for (int j = index + 1; j < len + index; j++) {
            if (s[j] - z[j - index] == 0) count++;
        }
    }
    if (count == len) return 1;
    return 0;
}
/*
 * Hàm: xoaChuoi
 * Công dụng: Xóa một đoạn con trong s (đã giải thích ở bài trước)
 */
void xoaChuoi(char *s, char *z, int index, int *n) {
    int len1 = strlen(z);
    for (int i = index; i < *n - len1; i++) {
        s[i] = s[i + len1];
    }
    s[*n - len1] = '\0';
    (*n) -= len1;
}
/*
 * Hàm: voHieuMaDoc
 * Công dụng: Biến đổi nội dung mã độc bằng cách chèn thêm ký tự (mã gốc + 1) vào sau mỗi ký tự gốc.
 * Ví dụ: "ABC" -> "A(A+1)B(B+1)C(C+1)" -> "ABBC CD"
 */
void voHieuMaDoc(char *maDoc) {
    int len = strlen(maDoc);
    for (int i = 0; i < len; i += 2) {
        char a = maDoc[i] + 1;
        insert(maDoc, a, &len, i + 1); // Chèn ký tự biến đổi vào vị trí kế tiếp
    }
}
/*
 * Hàm: xoaMaDoc (Thực tế là Thay thế/Vô hiệu hóa)
 * Công dụng: Tìm mã độc, xóa nó đi và chèn bản đã vô hiệu hóa vào đúng vị trí đó.
 */
void xoaMaDoc(char *s, char *maDoc) {
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        char maDoc1[1000];
        strcpy(maDoc1, maDoc); // Copy mã độc ra biến tạm để xử lý
        if (checkMaDoc(s, maDoc, i)) {
            xoaChuoi(s, maDoc1, i, &len); // Bước 1: Xóa mã độc cũ khỏi s
            voHieuMaDoc(maDoc1);           // Bước 2: Biến đổi mã độc tạm
            insertString(s, maDoc1, &len, i); // Bước 3: Chèn mã đã biến đổi ngược lại s
        }
    }
}
int main() {
    char maDoc[10][1000];
    char s[10001];
    gets_s(s, 10000);
    int k;
    scanf("%d", &k);
    getchar();
    for (int i = 0; i < k; i++) gets_s(maDoc[i], 999);
    for (int i = 0; i < k; i++) 
    {
        xoaMaDoc(s, maDoc[i]);
    }
    puts(s);
    return 0;
}