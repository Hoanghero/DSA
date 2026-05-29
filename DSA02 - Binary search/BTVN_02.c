#include <stdio.h>
#include <string.h>
int checkIncrease (char *s) {
    int len = strlen(s)-1;
    for (int i=0; i<len; i++) {
        if ((s[i+1]-'0') < (s[i]-'0')) {
            return 0;
        }
    }
    return 1;
}
int linearSearch(char *s, char value)
{
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (value == s[i])
            return i;
        else { 
            if (value < s[i]) break;
        }
    }
    return -1;
}
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
int main() {
    char s[1000];
    char value;
    gets_s(s, 999);
    scanf("%c", &value);
    if (checkIncrease(s)) {
        printf("%d %d", linearSearch(s,value), binarySearch(s,value));
    }
    else {
        printf("Chuoi khong tang");
    }
    return 0;
}