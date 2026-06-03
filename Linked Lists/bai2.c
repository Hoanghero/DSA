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
node* addHead(node* l, int y) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = y;
    temp->next = l;
    l = temp;
    return l;
}
node* addTail(node* l, int y) {
    node* p = l;
    while(p->next != NULL) {
        p=p->next;
    }
    node* new = (node*)malloc(sizeof(node));
    new->data = y;
    new->next = NULL;
    p->next = new;
    return l;
}
node* addAt(node* l, int x, int k) {
    node* p = l;
    node* temp = (node*)malloc(sizeof(node));
    for (int i=0; i<x-1; i++) {
        p=p->next;
    }
    temp->data = k;
    temp->next = p->next;
    p->next = temp;
    return l;
}
void printList(node* p) {
    while(p!=NULL) {
        printf("%d ", p->data);
        p=p->next;
    }
}
int main() {
    int n, x, k, a[100];
    scanf("%d", &n);
    scanf("%d", &a[0]);
    node *h = create(a[0]);
    node *q = h;
    for (int i=1; i<n; i++) {
        scanf("%d", &a[i]);
        q = add(q, a[i]);
    }
    scanf("%d", &x);
    scanf("%d", &k);
    if (x==0) {
        h = addHead(h, k);
    }
    else if (x==n) {
        h = addTail(h, k);
    }
    else {
        h = addAt(h, x, k);
    }
    printList(h);
    return 0;
}