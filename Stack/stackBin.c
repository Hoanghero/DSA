#include <stdio.h>
#include <stdlib.h>

char* stack(int n) {
    if (n == 0) {
        char* result = (char*)malloc(2 * sizeof(char));
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    int st[32];
    int top = -1; 

    while (n > 0) {
        st[++top] = n % 2;
        n = n / 2;
    }

    char* result = (char*)malloc((top + 2) * sizeof(char));

    int i = 0;
    while (top >= 0) {
        result[i++] = st[top--] + '0'; 
    }
    result[i] = '\0';

    return result;
}
int main() {
    int n;

    printf("Nhap vao mot so thap phan: ");
    scanf("%d", &n);

    char* binary_str = stack(n);

    printf("He nhi phan cua %d la: %s\n", n, binary_str);
    free(binary_str);
    
    return 0;
}
