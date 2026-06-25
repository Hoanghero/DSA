#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* next;
} node;
node* create(int y) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = y;
    newNode->next = NULL;
    return newNode;
}
node* add(node* p, int y) {
    node* temp = create(y);
    p->next = temp;
    return temp;
}
node* addAt(node* l, node* p, int id, int k, int value) {
    if (k==1) {
        node *temp = (node*)malloc(sizeof(node));
        temp->data = value;
        temp->next = l;
        return temp;
    }
    if (id > k-1) 
        return l;

    if (id == k-1) {
        node *temp = (node*)malloc(sizeof(node));
        temp->data = value;
        temp->next = p->next;
        p->next = temp;
    }
    return addAt(l,p->next,id+1,k,value);
}
node* deleteAt(node* l, node* p, int id, int k) {
    if (p == NULL || p->next == NULL) return l; 
    if (k==1) {
        node* temp = l;
        l = l->next;
        free(temp);
        return l;
    }
    if (id == k - 1) {
        node* temp = p->next;
        p->next = p->next->next;
        free(temp);
        return l;
    }
    return deleteAt(l, p->next, id + 1, k);
}
void printList(node* p) {
    while(p!=NULL) {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}
int main() {
    int value, k, a[100] = {2,3,4,5,6,7};
    node *h = create(a[0]);
    node *h1 = create(a[0]);
    node *q = h;
    for (int i=1; i<6; i++) {
        q = add(q, a[i]);
    }
    node *q1 = h1;
    for (int i=1; i<6; i++) {
        q1 = add(q1, a[i]);
    }

    printf("Them phan tu tai vi tri k.\n");
    printf("k = ");
    scanf("%d", &k);
    printf("value = ");
    scanf("%d", &value);
    node* p = h;
    h = addAt(h,p,1, k, value);
    printList(h);

    printf("Xoa phan tu tai vi tri k.\n");
    printf("k = ");
    scanf("%d", &k);
    node* p1 = h1;
    h1 = deleteAt(h1,p1,1, k);
    printList(h1);
    return 0;
}