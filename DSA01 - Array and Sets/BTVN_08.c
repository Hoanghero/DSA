#include <stdio.h>
#include <string.h>
//Hàm xóa kí tự
void delChar(char str[], int index) {
    int len = strlen(str);
    //dịch trái các kí tự chuỗi
    for (int i=index; i<len; i++) {
        str[i] = str[i+1];
    }
    //cho kí tự cuối là kí tự kết thúc chuỗi
    str[len] = '\0';
}
int main() {
    //Khai báo
    char str[1000];
    int index;
    //Nhập
    gets_s(str,999);
    scanf("%d", &index);
    getchar(); //bỏ kí tự xuống dòng
    //gọi hàm
    delChar(str,index);
    //xuất
    puts(str);
    return 0;
}