#include <stdio.h>
#include <stdbool.h>

bool isSafe(int board[10][10], int row, int col, int n) {
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i]) return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j]) return false;
        
    return true;
}
bool solveNQUtil(int board[10][10], int col, int n, int *count) {
    if (col >= n) {
        (*count)++; 
        return true;         
    }
    bool res = false;
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;
            res = solveNQUtil(board, col + 1, n, count) || res; 
            board[i][col] = 0; 
        }
    }
    return res; 
}

int main() {
    int n, count=0;
    scanf("%d", &n);
    int board[10][10] = {};
    if (solveNQUtil(board, 0, n, &count)) printf("%d", count);
    else {printf("%d", 0);}
    return 0;
}