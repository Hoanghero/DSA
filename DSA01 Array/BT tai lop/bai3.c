#include<stdio.h>
void deleteArray(int a[], int* n, int index){
        for (int i=index; i<*n;i++) {
            a[i] = a[i+1];
        }
        (*n)--;
}
int main(){
    int a[] = {1,4,3,7,5};
    int n = 5;
    int index = 2;

    deleteArray(a,&n,index);
    for(int i = 0; i < n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
