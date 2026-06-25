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

int main() {
    BinaryTree tree;
    init(&tree);
    int a[100] = {4,6,2,3,5,1,7};
    //insert các cây ở câu 1.1
    for (int i=0; i<7; i++) {
        insert(&tree, a[i]);
    }
    print(tree.root);
    return 0;
}
