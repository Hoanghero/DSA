#include <stdio.h>
#include <string.h>
//Hàm thêm chuỗi, mỗi chuỗi là một phần tử của mảng lưu chuỗi
void addString(char str[][1000], char *s, int index, int *n) {
    (*n)++;
    //Cho mỗi chuỗi sau vị trí index dịch lên một ô
    for (int i=(*n); i>=index; i--) {
        strcpy(str[i+1], str[i]);
    }
    //copy chuỗi cần chèn vào vị trí index
    strcpy(str[index], s);
}
int main() {
    //Khai báo
    int n, m, index;
    char str[100][1000], s[1000];
    //Nhập
    scanf("%d", &n);
    scanf("%d", &m);
    getchar(); // bỏ kí tự xuống dòng
    for (int i=0; i<n; i++) {
        gets_s(str[i], 999);
    }
    scanf("%d", &index);
    getchar(); //bỏ kí tự xuống dòng
    gets_s(s, 999);
    //gọi hàm
    addString(str, s, index, &n);
    //In các chuỗi trong mảng
    for (int i=0; i<n; i++) {
        // puts(str[i]);
        for (int j = 0; j < strlen(str[i]); j++)
        {
            printf("%c", str[i][j]);
        }
        printf(" ");
    }
    return 0;
}