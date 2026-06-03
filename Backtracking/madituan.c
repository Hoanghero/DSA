#include <stdio.h>
#include <stdbool.h>

void printSolution(int board[10][10], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}
bool isSafe(int board[10][10], int x, int y, int n, int m) {
    if (x>=0 && x<n && y>=0 && y<m && board[x][y]==0) return true;
    return false;
}
void quyDinhHuongDi(int *row, int *col, int a) {
    if(a==1) {
        (*row)-=2;
        (*col)++;
    }
    else if (a==2) {(*row)--; (*col)+=2;}
    else if (a==3) {(*row)++; (*col)+=2;}
    else if (a==4) {(*row)+=2; (*col)++;}
    else if (a==5) {(*row)+=2; (*col)--;}
    else if (a==6) {(*row)++; (*col)-=2;}
    else if (a==7) {(*row)--; (*col)-=2;}
    else if (a==8) {(*row)-=2; (*col)--;}
}
bool solve(int board[10][10], int x, int y, int n, int m, int steps) {
    if (steps==n*m) {
        printSolution(board, n, m);
        return true;
    }
    int x1=x, y1=y;
    for (int i=1; i<=8; i++) {
        quyDinhHuongDi(&x, &y, i);
        if (isSafe(board, x, y, n, m)) {
            board[x][y] = steps+1;
            if(solve(board, x, y, n, m, steps+1)) return true;
            board[x][y] = 0;
        }
        x=x1;
        y=y1;
    }
    return false;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int board[10][10] = {0};
    board[0][0]=1;
    if (solve(board, 0, 0, n, m, 1) == false) {
        printf("Khong ton tai giai phap");
    }
    return 0;
}