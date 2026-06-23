#include <stdio.h>
#include <stdlib.h>

typedef struct NodeType {
    int data;
    struct NodeType* left, * right;
} TreeNode;

typedef struct BinaryTreeType {
    struct NodeType* root;
} BinaryTree;

TreeNode* makeNode(int data) {
    TreeNode* new = (TreeNode*)malloc(sizeof(TreeNode));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void print(TreeNode* node) {
    if (node == NULL) 
        return;
    print(node->left);
    printf("%d ", node->data);
    print(node->right);
}

void init(BinaryTree* tree) {
    if (tree != NULL) {
        tree->root = NULL;
    }
}  
TreeNode* insertNode(TreeNode* node, int data) {
    if (node == NULL) {
        return makeNode(data);
    }
    if (data < node->data) {
        node->left = insertNode(node->left, data);
    }
    else {
        node->right = insertNode(node->right, data);
    }
    return node;
}
void insert(BinaryTree* tree, int data) {
    if (tree != NULL) {
        tree->root = insertNode(tree->root, data);
    }
}
TreeNode* search(TreeNode* node, int val) {
    if (node == NULL || val == node->data) 
        return node;

    if (val < node->data) {
        return search(node->left, val);
    }
    else {
        return search(node->right, val);
    }
    return NULL;
}
int main() {
    BinaryTree tree;
    init(&tree);
    int a[100] = {50,25,75,10,33,56,89,4,11,40,52,61,82,95};
    int val[10] = {75,89,33,61,35};
    //insert các cây ở câu 1.1
    for (int i=0; i<14; i++) {
        insert(&tree, a[i]);
    }
    for (int i=0; i<5; i++) {
        TreeNode* x = search(tree.root, val[i]);
        if (x != NULL) {
            printf("Val = %d; Node address: %p\n", val[i], (void*)&(x->data));
        }
        else printf("Val = %d => NULL\n", val[i]);
    }
    return 0;
}
