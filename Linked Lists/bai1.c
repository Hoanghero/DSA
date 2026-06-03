#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node *creatNode(int x) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}   

node *add(node* p, int x) {
    node *temp = creatNode(x);
    p->next = temp;
    return temp;
}

void printList(node *p) {
    while (p!=NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main() {
    int n, x;
    scanf("%d", &n);
    scanf("%d", &x);
    node *k = creatNode(x);
    node *p = k;
    for (int i=1; i<n; i++) {
        scanf("%d", &x);
        p = add(p, x);
    }
    printList(k);
    return 0;
}