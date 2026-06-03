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
node* deleteHead(node* l) {
    node* p = l;
    l = p->next;
    return l;
}
node* deleteTail(node* l) {
    node* p = l;
    while (p->next->next!=NULL) {
        p=p->next;
    }
    p->next = NULL;
    return l;
}
node* deleteAt(node* l, int k) {
    node* p = l;
    node* temp = (node*)malloc(sizeof(node));
    for (int i=0; i<k-1; i++) {
        p=p->next;
    }
    temp = p->next->next;
    p->next = temp;
    return l;
}
void printList(node* l){
    node* p = l;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main() {
    int n, k, x;
    scanf("%d", &n);
    scanf("%d", &x);
    node* l = create(x);
    node* p = l;
    for (int i=1; i<n; i++) {
        scanf("%d", &x);
        p = add(p, x);
    }
    scanf("%d", &k);
    if (k==0) {
        l = deleteHead(l);
    }
    else if (k==n) {
        l = deleteTail(l);
    }
    else {
        l = deleteAt(l, k);
    }
    printList(l);
    return 0;
}