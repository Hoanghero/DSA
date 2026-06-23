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
node* addAt(node* l, int k, int value) {
    node *p = l;
    if (k==1) {
        node *temp = (node*)malloc(sizeof(node));
        temp->data = value;
        temp->next = l;
        return temp;
    }
    node *temp = (node*)malloc(sizeof(node));
    for (int i=1; i<k-1; i++) {
        p=p->next;
    }
    temp->data = value;
    temp->next = p->next;
    p->next = temp;
    free(temp);
    return l;
}
node* deleteAt(node* l, int k) {
    node* p = l;
    if (k==1) {
        node* temp = l;
        l = l->next;
        free(temp);
        return l;
    }
    node* temp = (node*)malloc(sizeof(node));
    for (int i=1; i<k-1; i++) {
        p=p->next;
    }
    temp = p->next->next;
    p->next = temp;
    free(temp);
    return l;
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
    h = addAt(h, k, value);
    printList(h);

    printf("Xoa phan tu tai vi tri k.\n");
    printf("k = ");
    scanf("%d", &k);
    h1 = deleteAt(h1, k);
    printList(h1);
    return 0;
}