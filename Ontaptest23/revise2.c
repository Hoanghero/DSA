#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
int soNutLa(TreeNode *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) 
        return 1;
    return soNutLa(root->left) + soNutLa(root->right);
}
void sinhMang(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
}
void freeTreeNode(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    freeTreeNode(node->left);
    freeTreeNode(node->right);
    free(node);
}
void freeTree(BinaryTree* tree) {
    if (tree != NULL && tree->root != NULL) {
        freeTreeNode(tree->root);
        tree->root = NULL;
    }
}
float trungBinhCong(int arr[], int n, int m) {
    float tong = 0;
    for (int i = 0; i < n; i++) {
        tong += (float)i * arr[i]; 
    }
    return tong / (float)m;
}
int main() {
    time_t t;
    srand((unsigned)time(&t));
    BinaryTree tree;
    init(&tree);
    int a[10], danhDau[11] = {};
    for (int i=0; i<1000; i++) {
        sinhMang(a,10,0,100);
        for (int j=0; j<10; j++) insert(&tree, a[j]);
        danhDau[soNutLa(tree.root)]++;
        freeTree(&tree);
    }
    printf("Mean: %.2f\n", trungBinhCong(danhDau,11,1000));
    return 0;
}