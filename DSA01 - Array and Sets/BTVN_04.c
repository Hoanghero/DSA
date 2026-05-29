#include <stdio.h>
#include <string.h>
// hàm thêm kí tự
void addChar(char str[1000], char s, int index) {
    int len = strlen(str);
    //dịch chuyển các kí tự bên phải vị trí cần chèn
    for (int i=len-1; i>=index; i--) {
        str[i+1] = str[i];
    }
    //cho vị trí cần chèn là kí tự
    str[index] = s;
}
int main() {
    // Khai báo chuỗi, kí tự cần chèn và index cần chèn
    char str[1000], s;
    int index;
    //Nhập input
    gets_s(str,999);
    scanf("%c", &s);
    scanf("%d", &index);
    getchar();
    //Gọi hàm
    addChar(str,s,index);
    //Xuất chuỗi
    for (int i = 0; i < strlen(str); i++)
    printf("%c", str[i]);
    return 0;
}