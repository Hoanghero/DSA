#include <stdio.h>

/* Hàm: searchOrderedArray
 * Công dụng: Tìm kiếm tuần tự trên mảng đã sắp xếp.
 * Giải thuật: Duyệt qua từng phần tử, nếu thấy phần tử lớn hơn giá trị cần tìm 
 * thì dừng lại ngay (vì mảng đã sắp xếp nên các phần tử sau chắc chắn lớn hơn).
 */
void searchOrderedArray(float a[], int n, float value, int *compsLinear){
    for (int i=0; i<n; i++){
        if (a[i]==value){
            (*compsLinear)++; 
            break; // Tìm thấy giá trị, thoát vòng lặp
        } 
        else{
            if(a[i]>value){
                (*compsLinear)++;
                break; // Vì mảng đã sắp xếp, nếu a[i] > value thì value không tồn tại phía sau
            }
            (*compsLinear)++;
        }
    }
}

/* Hàm binary_search
 * Công dụng: Tìm kiếm nhị phân trên mảng đã sắp xếp.
 * Giải thuật: Chia đôi khoảng tìm kiếm sau mỗi bước so sánh để thu hẹp phạm vi,
 * giúp tốc độ tìm kiếm nhanh hơn đáng kể so với tuần tự (O(log n)).
 */
void binary_search(float a[], int n, float value, int *compsBinary) {
    int lower =0;
    int upper =n-1;
    while (lower<=upper){
        int midpoint = (upper+lower)/2;
        int value_at_midpoint = a[midpoint]; // Lấy giá trị tại vị trí giữa
        
        if(value==value_at_midpoint){
            (*compsBinary)++;
            break; // Tìm thấy tại trung điểm
        }
        else if(value < value_at_midpoint){
            upper=midpoint-1; // Thu hẹp phạm vi tìm kiếm về nửa bên trái
            (*compsBinary)++;
        }
        else if(value > value_at_midpoint){
            lower= midpoint+1; // Thu hẹp phạm vi tìm kiếm về nửa bên phải
            (*compsBinary)++;
        }
        
        // Kiểm tra nếu sau khi cập nhật mà không còn khoảng tìm kiếm hợp lệ
        if (upper<lower) {
            (*compsBinary)++;
        }
    }
}

int main(){
    int n; 
    int compsBinary=0;
    int compsLinear=0;
    scanf("%d", &n);
    float a[1000];
    for(int i=0; i<n;i++){
        scanf("%f", &a[i]);
    }
    float value; 
    scanf("%f", &value);

    // Gọi hàm và đếm số bước
    binary_search(a, n, value, &compsBinary);

    // Gọi hàm tìm kiếm tuần tự và đếm số bước
    searchOrderedArray(a, n, value, &compsLinear);

    // In kết quả so sánh số bước thực hiện của hai thuật toán
    printf("stepLinear: %d\n", compsLinear);
    printf("stepBinary: %d", compsBinary);
    
    return 0;
}