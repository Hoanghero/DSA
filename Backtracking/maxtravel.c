#include <stdio.h>
#include <stdbool.h>
int max(int *a, int n) {
    int max=a[0];
    for (int i=1; i<n; i++) {
        if (max<a[i]) max=a[i];
    }
    return max;
}
bool isSafe(int x, int y) {
    if (x>=0 && x<4 && y>=0 && y<4) return true;
    return false;
}
void huongDi(int *x, int *y, int a) {
    if (a==1) {(*x)++;}
    if (a==2) {(*y)++;}
}
void sovle(int board[10][10], int *a, int *index, int x, int y, int sum) {
    sum+=board[x][y];
    if (x==3 && y==3) {
        a[*index] = sum;
        (*index)++;
        return;
    }
    int x1=x;
    int y1=y;
    for (int i=1; i<=2; i++) {
        huongDi(&x,&y,i);
        if (isSafe(x, y)) {
            sovle(board, a, index, x, y, sum);
        }
        x=x1;
        y=y1;
    }
}
int main() {
    int board[10][10], index=0, a[100];
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    sovle(board,a,&index,0,0,0);
    printf("%d", max(a, 20));
    return 0;
}