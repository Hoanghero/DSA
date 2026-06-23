#include <stdio.h>
#include <stdlib.h>

typedef struct NodeType {
    int data;
    struct NodeType* left;
    struct NodeType* right;
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
    BinaryTree tree1;
    BinaryTree tree2;
    BinaryTree tree3;
    BinaryTree tree4;
    init(&tree1);
    init(&tree2);
    init(&tree3);
    init(&tree4);
    //insert 1.1
    tree1.root = makeNode(1);
    tree1.root->left = makeNode(2);
    tree1.root->right = makeNode(3);
    tree1.root->left->left = makeNode(4);
    tree1.root->left->right = makeNode(5);
    tree1.root->right->left = makeNode(6);
    tree1.root->right->right = makeNode(7);
    tree1.root->left->left->left = makeNode(8);
    tree1.root->left->left->right = makeNode(9);
    tree1.root->left->right->left = makeNode(10);
    tree1.root->left->right->right = makeNode(11);
    tree1.root->right->left->left = makeNode(12);
    tree1.root->right->left->right = makeNode(13);
    tree1.root->right->right->left = makeNode(14);
    tree1.root->right->right->right = makeNode(15);
    int a2[100] = {50,17,76,9,23,54,14,19,72,12,67};
    int a3[100] = {15,11,26,8,12,20,30,6,9,14,35};
    printf("Cay 1.1: ");
    print(tree1.root);
    printf("\n");
    //insert các cây ở câu 1.2
    for (int i=0; i<11; i++) {
        insert(&tree2, a2[i]);
    }
    printf("Cay 1.2: ");
    print(tree2.root);
    printf("\n");
    //insert các cây ở câu 1.3
    for (int i=0; i<11; i++) {
        insert(&tree3, a3[i]);
    }
    printf("Cay 1.3: ");
    print(tree3.root);
    printf("\n");
    //insert các cây ở câu 1.4
    tree4.root = makeNode(3);
    tree4.root->left = makeNode(1);
    tree4.root->right = makeNode(10);
    tree4.root->left->left = makeNode(13);
    tree4.root->left->right = makeNode(5);
    tree4.root->left->right->left = makeNode(6);
    tree4.root->right->left = makeNode(11);
    tree4.root->right->right = makeNode(16);
    tree4.root->right->right->left = makeNode(15);
    tree4.root->right->right->right = makeNode(2);
    tree4.root->right->right->left->left = makeNode(9);
    tree4.root->right->right->left->right = makeNode(4);
    printf("Cay 1.4: ");
    print(tree4.root);
    printf("\n");
    return 0;
}