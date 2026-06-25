#include <stdio.h>
int searchArray(int arr[], int n, int value) {
    int index = -1;
    while (index<n) {
        index++;
        if (index==n) {
            index=-1;
        }
        if (arr[index]==value){
            break;
        }
    }
    return index;
}

int main() {
    int n;
    int arr[100];
    int value;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &value);
    int index = searchArray(arr, n, value);
    if (index == -1)
        printf("Not found!");
    else
        printf("Found %d at %d", value, index);
    return 0;    
}