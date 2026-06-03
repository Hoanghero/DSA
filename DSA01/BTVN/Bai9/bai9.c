#include <stdio.h>
#include <stdlib.h>
//tạo struct ToaDo gồm x và y 
typedef struct ToaDo {
    float x;
    float y;
} ToaDo;
//hàm xóa ToaDo
int xoaToaDo(ToaDo *a, int *n, ToaDo xoa, int *b) {
    int index=-1, count=0;
    //Chạy loop, nếu đúng tọa độ x, y thì dịch trái
    //các ToaDo 
    for (int i=0; i<*n; i++) {
        if (a[i].x==xoa.x && a[i].y==xoa.y) {
            index = i;
            (*n)--; //giảm n một đơn vị vì đã xóa 1 ToaDo
            for (int j=i; j<*n; j++) {
                a[j]=a[j+1];
            }
            count++; //đếm số lượng ToaDo đã xóa
            b[count-1] = index+count-1; 
            // lưu vị trí đã xóa vào mảng b, cộng thêm count-1 để bù lại vị trí đã dịch trái
            i--; //giảm i để kiểm tra lại vị trí mới sau khi dịch trái
        }
    }
    return index; //trả về -1 nếu không có ToaDo phù hợp
}
int main() {
    //Khai báo và nhập
    int n, b[10]={0};
    scanf("%d", &n);
    ToaDo *a = (ToaDo*)malloc(n*sizeof(ToaDo));
    for (int i=0; i<n; i++) {
        scanf("%f %f", &a[i].x, &a[i].y);
    }
    ToaDo xoa;
    scanf("%f %f", &xoa.x, &xoa.y);
    //Nếu index là -1 thì thực hiện xóa và in, ngược lại thì không in
    int index = xoaToaDo(a,&n,xoa, b);
    if (index!=-1) {
        for (int i=0; i<n; i++) {
            printf("%.2f %.2f\n", a[i].x, a[i].y);
        }
        printf("Delete %.2f %.2f at", xoa.x, xoa.y);
        for (int i=0; i<10; i++) {
            if (b[i]!=0) {
                printf(" %d", b[i]);
            }
        }
        printf("\n");
    }
    else {
        printf("Can not delete %.2f %.2f from the array!", xoa.x, xoa.y);
    }
    return 0;
}