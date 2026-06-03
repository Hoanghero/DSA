#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

void swap(int *a, int *b) // ham doi cho 2 phan tu
{
    int tmp = *a; // tao bien tam 
    *a = *b; // gan b vao a
    *b = tmp; // gan bien tam vao b
}

void print_array(int a[], int n, const char *label) // ham in mang
{
    printf("%s", label);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

void copy_array(int src[], int dest[], int n) // ham sao chep mang
{
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

void bubble_sort_greater(int a[], int n) // ham bubble sort
{
    for (int i = n-1; i >= 0; i--) // duyet qua tung phan tu
    {
        bool check = true; // bien kiem tra trang thai
        for (int j = 0; j < i; j++) // duyet qua tung phan tu de hoan doi vi tri
        {
            if (a[j] < a[j+1]) // neu phan tu phia sau lon hon phan tu phia truoc thi doi cho
            {
                check = false; // gan bien kiem tra
                swap(&a[j], &a[j+1]); // doi cho 2 phan tu
            }
        }
        if (check) break; // neu khong hoan doi vi tri cua phan tu nao thi dung lai
    }
}

void selection_sort_greater(int a[], int n) // ham selection sort
{
    for (int i = 0; i < n; i++) // duyet qua tung phan tu
    {
        int id = i; // vi tri cua phan tu nho nhat trong mang
        for (int j = i + 1; j < n; j++) // duyet qua cac phan tu de tim phan tu nho nhat trong mang
        {
            if (a[j] > a[id]) id = j; // so sanh va tim phan tu lon nhat
        }
        if (i != id) // neu phan tu nho nhat khac phan tu hien tai thi doi vi tri
        {
            swap(&a[i], &a[id]); // doi vi tri 2 phan tu
        } 
    }
}

void insertion_sort_greater(int a[], int n) // ham insertion sort
{
    for (int i = 1; i < n; i++) //duyet qua tung phan tu trong mang
    {
        int tmp = a[i]; // gan bien tam 
        int id = 0; // khai bao chi so
        for (int j = i - 1; j >= 0; j--) // duyet qua cac phan tu truoc do de tim vi tri thich hop
        {
            if (a[j] < tmp) a[j+1] = a[j]; //so sanh va hoan doi vi tri neu phan tu truoc do nho hon phan tu dang xet
            else //xac dinh vi tri thich hop
            {
                id = j + 1; 
                break;
            }
        }
        a[id] = tmp; //chen phan tu
    }
}

int main()
{
    int n = 10;
    int a[10] = {3, 1, 8, 2, 6, 5, 3, 9, 1, 0};
    int b[10], c[10];
    
    copy_array(a, b, n); // sao chep mang
    copy_array(a, c, n); // sao chep mang

    print_array(a, n, "Mang ban dau: ");

    bubble_sort_greater(a, n);  // goi ham bubble sort
    selection_sort_greater(b, n); // goi ham selection sort
    insertion_sort_greater(c, n); // goi ham insertion sort
    
    print_array(a, n, "Bubble sort: ");
    print_array(b, n, "Selection sort: ");
    print_array(c, n, "Insertion sort: ");
    
    return 0;
}