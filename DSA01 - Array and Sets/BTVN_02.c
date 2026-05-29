#include <stdio.h>
#include <string.h> // Khai báo thư viện string để dùng strlen
// Hàm hoathuong đảm bảo đúng ký tự mà không phân biệt chữ hoa và chữ thường
int hoathuong(char a, char b) {
    int x=0;
    if (a==b || a+32==b || a-32==b) {
        x++;
    }
    return x;
}
//Hàm findIndex sẽ tìm vị trí có ký tự cần tìm
int findIndex (char arr[], char a){
    int index=0;
    //Chạy vòng lặp đến hết chuỗi, nếu mà đến ký tự thích hợp thì sẽ dừng vòng lặp và trả về index
    while(arr[index]!='\0') {
        if (hoathuong(a,arr[index])){
            break;
        }
        index++;
    }
    return index;
}

int main() {
    char a;
    char arr[1000];
    gets_s(arr,999); // Nhập chuỗi ký tự
    scanf("%c", &a); // Nhập ký tựT
    int d=strlen(arr); //Khai báo biến d là độ dài ký tự của chuỗi arr
    if (findIndex(arr,a)==d) {
        printf("Not found!");
    } //Nếu quét hết chuỗi arr nghĩa là không tìm được ký tự
    else {
        printf("Found %c at %d", a, findIndex(arr,a));
    } //In ra kết quả
    return 0;
}
