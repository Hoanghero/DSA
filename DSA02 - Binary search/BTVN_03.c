#include <stdio.h>
#include <string.h>
int binarySearch(char *s, char value) {
    int len = strlen(s);
    int lower=0;
    int upper=len-1;
    while (lower<=upper) {
        int midpoint = (lower+upper)/2;
        int valueAtMid = s[midpoint];
        if (value == valueAtMid) {
            return midpoint;
            break;
        }
        else if (value < valueAtMid) {
            upper = midpoint - 1;
        }
        else {
            lower = midpoint + 1;
        }
    }
    return -1;
}
int checkMissingChar(char *s) {
    for (int i=0; i<26; i++) {
        if (binarySearch(s, 97+i)==-1) {
            return i;
        }
    }
}
void insert(char *s, char a, int *n, int index) {
    (*n)++;
    for (int i=*n; i>index;i--) {
        s[i] = s[i-1]; 
    }
    s[index] = a;
}
int main() {
    char s[1000];
    scanf("%s", s);
    int len = strlen(s);
    printf("%c at %d is missing!\n", 97+checkMissingChar(s), checkMissingChar(s));
    char x = 97+checkMissingChar(s);
    insert(s, x, &len, checkMissingChar(s));
    printf("%s", s);
    return 0;
}