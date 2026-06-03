#include <stdio.h>
#include <string.h> // Thư viện này để dùng strcpy và strcmp
// Hàm compareString để xem xem 2 chuỗi có giống nhau không
int compareString(char *s, char *t) {
    //Vì strcpy trả về 0 khi 2 chuỗi giống nhau nên cái if ở dưới sẽ không chạy, 2 chuỗi khác nhau thì cái if sẽ chạy
    // => Cho x ban đầu là 1 để trả về 1 nếu if không chạy (2 chuỗi giống), và cho x xuống 0 nếu if chạy (2 chuỗi khác)
    int x=1;
    if (strcmp(s,t)) {
        x--; 
    }
    return x;
}
//Hàm searchString dùng để tìm chỉ số chỉ vị trí chuỗi cần tìm
int searchString(char s[][1000], char *t, int n) {
    // Cho chỉ số ban đầu là 0 rồi chạy vòng lặp chạy dần lên 1 đơn vị, tương ứng xét mỗi chuỗi
    // Nếu chuỗi đang xét bấy giờ giống chuỗi t thì return chỉ số luôn
    // Còn chạy hết mà không có gì thì trả về -1 để xét trường hợp Not found!
    int i=0;
    while (i<n) {
        if(compareString(s[i],t)) {
            return i;
        }
        i++;
    }
    return -1;
}

int main() {
    int n, k;
    char t[1000]; //Khai báo chuỗi nhập bên ngoài
    char serialKey[100][1000]; //Khai báo 2 chiều lưu n chuỗi

    // Nhập n và k
    scanf("%d", &n);
    scanf("%d", &k);
    

    getchar(); //Lệnh này dùng để xóa ký tự xuống dòng \n do lệnh scanf số k bên trên gây ra

    //Nhập lần lượt các chuỗi vào mảng 2 chiều serialKey
    for (int i=0; i<n; i++) {
        gets_s(serialKey[i],999);
    }

    gets_s(t,999); // Nhập chuỗi bên ngoài

    //Nếu chạy hàm searchString ra -1 nghĩa là chả có chuỗi nào giống => Not found!
    //Còn có chuỗi giống thì in ra bình thường
    if (searchString(serialKey,t,n)==-1) {
        printf("Not found!");
    }
    else {
        int a = searchString(serialKey,t,n);
        printf("Found %s at %d", t, a);
    }
    return 0;
}