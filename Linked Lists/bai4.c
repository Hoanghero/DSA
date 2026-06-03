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
node* add(node* p, int x) {
    node* newNode = create(x);
    p->next = newNode;
    return newNode;
}
node* truyvan(node* l, int k) {
    node* p = l;
    node* temp = (node*)malloc(sizeof(node));
    for (int i=0; i<k-1; i++) {
        p = p->next;
    }
    temp = p->next;
    return temp;
}
node* truyvanHead(node* l) {
    return l;
}
node* truyvanTail(node* l) {
    node* p = l;
    node* temp = (node*)malloc(sizeof(node));
    while (p->next!=NULL) {
        p = p->next;
    }
    temp = p;
    return temp;
}
int main() {
    int n, k, x;
    scanf("%d", &n);
    scanf("%d", &x);
    node* l = create(x);
    node* p = l;
    for (int i=0; i<n-1; i++) {
        scanf("%d", &x);
        p = add(p, x);
    }
    scanf("%d", &k);
    if (k==0) {
        l = truyvanHead(l);
    }
    else if (k==n) {
        l = truyvanTail(l);
    }
    else {
        l = truyvan(l, k);
    }
    printf("%d", l->data);
    return 0;
}