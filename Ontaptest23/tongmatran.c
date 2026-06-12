#include <stdio.h>
int x,y;
int sum(int a[][100], int m, int n) {
    if (m==-1) return 0;
    if (n==-1) {
        n=x;
        return sum(a, m-1,n);
    }
    else return a[m][n] + sum(a,m,n-1);
}
/*
BASE CASE: m = -1, tức là đã đi hết các hàng
OUTPUT BASE CASE: 0
BEFORE BASE CASE: m = 0 
nếu n >= 0 thì ta cộng dồn các phần tử a[0][n]
nếu n = -1 (đã đi hết cột) thì đến bước BASE CASE
BEFORE BEFORE BASE CASE: m = 1
nếu n >= 0 thì ta cộng dồn các phần tử a[1][n]
nếu n = -1 (đã đi hết cột) thì đến bước BEFORE BASE CASE
*/
int main() {
    int m, n, a[100][100];
    scanf("%d %d", &m, &n);
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    x=m;
    y=n;
    printf("%d", sum(a,m-1,n-1));
    return 0;
}