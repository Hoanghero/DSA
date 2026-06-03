#include <stdio.h>
void searchOrderedArray(int a[], int n,int value, int *compsLinear){
    for (int i=0; i<n; i++){
        if (a[i]==value){
            (*compsLinear)++; 
            break;
        } 
        else{
            if(a[i]>value){
                (*compsLinear)++;
                break;
            }
            (*compsLinear)++;

        }
    }
}
void binary_search(int a[], int n, int value, int *compsBinary) {
    int lower =0;
    int upper =n-1;
    while (lower<=upper){
        int midpoint = (upper+lower)/2;
        int value_at_midpoint = a[midpoint];
        if(value==value_at_midpoint){
            (*compsBinary)++;
            break;
        }
        else if(value < value_at_midpoint){
            upper=midpoint-1;
            (*compsBinary)++;
        }
        else if(value > value_at_midpoint){
            lower= midpoint+1;
            (*compsBinary)++;
        }
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
    int a[1000];
    for(int i=0; i<n;i++){
        scanf("%d", &a[i]);
    }
    int value; 
    scanf("%d", &value);
    binary_search(a,n,value,&compsBinary);
    searchOrderedArray(a,n,value,&compsLinear);
    printf("stepLinear: %d\n", compsLinear);
    printf("stepBinary: %d", compsBinary);
    return 0;
}