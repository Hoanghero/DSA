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

int main()
{
    int n = 10;
    int a[10] = {3, 1, 8, 2, 6, 5, 3, 9, 1, 0}; //khai bao mang ban dau
    int b[10] = {3, 1, 8, 2, 6, 5, 3, 9, 1, 0};
    int c[10] = {3, 1, 8, 2, 6, 5, 3, 9, 1, 0};

    int bubble = 0, selection = 0, insertion = 0; // khai bao cac bien dem

    printf("Mang ban dau: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]); // in ra mang ban dau

    bubble_sort(a, 10, &bubble);  //goi ham bubble sort
    selection_sort(b, 10, &selection); // goi ham selection sort
    insertion_sort(c, 10, &insertion); // goi ham insertion sort
    
    printf("\nbubble sort: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]); // xuat ra mang sau khi sap xep
    printf("\nselection sort: ");
    for (int i = 0; i < n; i++) printf("%d ", b[i]); // xuat ra mang sau khi sap xep
    printf("\ninsertion sort: ");
    for (int i = 0; i < n; i++) printf("%d ", c[i]); // xuat ra mang sau khi sap xep
    printf("\nbubble sort: %d | selection sort: %d | insertion sort: %d", bubble, selection, insertion); // so sanh cac buoc thuc hien cua thuat toan
}