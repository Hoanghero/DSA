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

void delete(BinaryTree* tree, int val) {
    TreeNode* curr = tree->root;
    TreeNode* prev = NULL;
    
    while (1) {
        // Case 1: not found
        if (curr == NULL) {
            printf("=> NULL, ");
            return;
        }
        if (curr->data == val) {
            // Case 2: no child / leaf
            if (curr->left == NULL && curr->right == NULL) {
                if (prev == NULL) tree->root = NULL; 
                else if (prev->left == curr) prev->left = NULL;
                else prev->right = NULL;
                free(curr);
            }
            // Case 3: one child
            else if (curr->left == NULL || curr->right == NULL) {
                TreeNode* child = (curr->left != NULL) ? curr->left : curr->right;
                if (prev == NULL) tree->root = child; 
                else if (prev->left == curr) prev->left = child;
                else prev->right = child;
                free(curr);
            }
            // Trường hợp node có 2 con (Case 4 và Case 5)
            // Thay thế bằng node trái nhất (nhỏ nhất) của cây con bên phải
            else {
                TreeNode* succParent = curr;
                TreeNode* succ = curr->right;
                
                // Case 4: children (leafs)
                if (succ->left == NULL) {
                    curr->data = succ->data;
                    curr->right = succ->right; 
                    free(succ);
                }
                // Case 5: curr->right is not a leaf leaf (duyệt xuống bên trái tìm min)
                else {
                    while (succ->left != NULL) {
                        succParent = succ;
                        succ = succ->left;
                    }
                    curr->data = succ->data;
                    succParent->left = succ->right;
                    free(succ);
                }
            }
            break;
        }
        prev = curr;
        if (val < curr->data) curr = curr->left;
        else curr = curr->right;
    }
}

int main() {
    BinaryTree tree;
    init(&tree);
    int a[14] = {50, 25, 75, 10, 33, 56, 89, 4, 11, 40, 52, 61, 82, 95};
    for (int i = 0; i < 14; i++) {
        insert(&tree, a[i]);
    }
    printf("Cay ban dau: ");
    print(tree.root);
    printf("\n");
    int valdel[10] = {75, 89, 33, 61, 35};
    for (int i = 4; i >= 0; i--) {
        printf("Val = %d ", valdel[i]);
        delete(&tree, valdel[i]);
        printf("Cay sau khi xu ly: ");
        print(tree.root);
        printf("\n");
    }

    return 0;
}