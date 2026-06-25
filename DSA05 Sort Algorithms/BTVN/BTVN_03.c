#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void swap(int *a, int *b) // ham doi cho 2 phan tu
{
    int tmp = *a; // tao bien tam 
    *a = *b; // gan b vao a
    *b = tmp; // gan bien tam vao b
}

void random(int a[], int b[], int c[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = -1000 + rand() % (1000 - (-1000) + 1);
        b[i] = a[i];
        c[i] = a[i];
    }
}

void bubble_sort(int a[], int n, int *step) // ham bubble sort
{
    for (int i = n-1; i >= 0; i--) // duyet qua tung phan tu
    {
        bool check = true; // bien kiem tra trang thai
        for (int j = 0; j < i; j++) // duyet qua tung phan tu de hoan doi vi tri
        {
            (*step)++; // dem so buoc 
            if (a[j] > a[j+1]) // neu phan tu phia sau nho hon phan tu phia truoc thi doi cho
            {
                check = false; // gan bien kiem tra
                swap(&a[j], &a[j+1]); // doi cho 2 phan tu
            }
        }
        if (check) break; // neu khong hoan doi vi tri cua phan tu nao thi dung lai
    }
}

void selection_sort(int a[], int n, int *step) // ham selection sort
{
    for (int i = 0; i < n; i++) // duyet qua tung phan tu
    {
        int id = i; // vi tri cua phan tu nho nhat trong mang
        for (int j = i + 1; j < n; j++) // duyet qua cac phan tu de tim phan tu nho nhat trong mang
        {
            (*step)++; // dem so buoc
            if (a[j] < a[id]) id = j; // so sanh va tim phan tu nho nhat
        }
        if (i != id) // neu phan tu nho nhat khac phan tu hien tai thi doi vi tri
        {
            (*step)++; // dem so buoc
            swap(&a[i], &a[id]); // doi vi tri 2 phan tu
        } 
    }
}

void insertion_sort(int a[], int n, int *step) // ham insertion sort
{
    for (int i = 1; i < n; i++) //duyet qua tung phan tu trong mang
    {
        int tmp = a[i]; // gan bien tam 
        int id = 0; // khai bao chi so
        for (int j = i - 1; j >= 0; j--) // duyet qua cac phan tu truoc do de tim vi tri thich hop
        {
            (*step)++; // dem so buoc thuc hien
            if (a[j] > tmp) a[j+1] = a[j]; //so sanh va hoan doi vi tri
            else //xac dinh vi tri thich hop
            {
                id = j + 1; 
                break;
            }
        }
        (*step)++; // dem so buoc
        a[id] = tmp; //chen phan tu
    }
}

void process(int n) //ham xu ly yeu cau
{
    int a[n+1], b[n+1], c[n+1]; //khai bao mang
    random(a, b, c, n); //sinh ngau nhien cac phan tu trong mang

    printf("n = %d:\n", n); //in ra n

    int bubble = 0, selection = 0, insertion = 0; // khai bao cac bien dem

    bubble_sort(a, n, &bubble);  //goi ham bubble sort
    selection_sort(b, n, &selection); // goi ham selection sort
    insertion_sort(c, n, &insertion); // goi ham insertion sort
    
    printf("bubble sort: %d | selection sort: %d | insertion sort: %d\n", bubble, selection, insertion); // so sanh cac buoc thuc hien cua thuat toan
}

int main()
{
    srand(time(0));
    process(10); // goi ham xu ly yeu cau
    process(20);
    process(50);
    process(100);    
}