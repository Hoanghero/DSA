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
//3.1
int minRootLeaf(TreeNode *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    if (root->left == NULL) return 1 + minRootLeaf(root->right);
    if (root->right == NULL) return 1 + minRootLeaf(root->left);
    int l = 1 + minRootLeaf(root->left);
    int r = 1 + minRootLeaf(root->right);
    if (l<r) return l;
    else return r;
}
//3.2
int treeHeight(TreeNode *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 0;
    int l = 1 + treeHeight(root->left);
    int r = 1 + treeHeight(root->right);
    if (l<r) return r;
    else return l;
}
void countEachLevel(TreeNode *root, int level, int *count) {
    if (root == NULL) return;
    count[level]++;
    countEachLevel(root->left, level+1, count);
    countEachLevel(root->right, level+1, count);
}
int maxNodeLevel(TreeNode *root) {
    if (root == NULL) return -1;
    int h = treeHeight(root);
    int *count = (int*)calloc(h, sizeof(int));
    countEachLevel(root, 0, count);
    int maxLevel = 0;
    for (int i=1; i<h; i++) {
        if (count[i] > count[maxLevel]) maxLevel = i;
    }
    free(count);
    return maxLevel;
}
//3.3
int checkOneChild(TreeNode *node) {
    if (node == NULL) return -1;
    int hasLeft, hasRight;
    if (node->left != NULL) hasLeft = 1;
    else hasLeft = 0;
    if (node->right != NULL) hasRight = 1;
    else hasRight = 0;
    return (hasLeft ^ hasRight);
}
int sumOnly1Child(TreeNode *root) {
    if (root == NULL) return 0;
    int sum = 0;
    if (checkOneChild(root) && checkOneChild(root) != -1) {
        sum += root->data;
    }
    sum += sumOnly1Child(root->left);
    sum += sumOnly1Child(root->right);
    return sum;
}
//3.4
int checkOneChildLeft(TreeNode *node) {
    if (node == NULL) return -1;
    return (node->left != NULL && node->right == NULL);
}
int sumOnly1ChildLeft(TreeNode *root) {
    if (root == NULL) return 0;
    int sum = 0;
    if (checkOneChildLeft(root) && checkOneChildLeft(root) != -1) {
        sum += root->data;
    }
    sum += sumOnly1ChildLeft(root->left);
    sum += sumOnly1ChildLeft(root->right);
    return sum;
}
int hieu3334(int a, int b) {
    return a-b;
}
//3.5
int gttd(int a, int b) {
    if (a-b > 0) return (a-b);
    else return (b-a);
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
    int a[100] = {10,5,20,7,3,14,25,2,4,17,12,29,22,34,1};
    for (int i=0; i<15; i++) {
        insert(&tree, a[i]);
    }
    //3.1
    printf("Duong di tu root den leaf co so node it nhat: %d\n", minRootLeaf(tree.root));
    //3.2
    if (maxNodeLevel(tree.root) != -1) {
        printf("Level co so phan tu nhieu nhat la: %d\n", maxNodeLevel(tree.root));
    }
    else printf("Cay khong co TreeNode nao.\n");
    //3.3
    printf("Tong gia tri cac node chi co mot child: %d\n", sumOnly1Child(tree.root));
    //3.4
    int hieu = hieu3334(sumOnly1Child(tree.root), sumOnly1ChildLeft(tree.root));
    printf("Hieu gia tri tim duoc o cau 3.3 va gia tri cua cac node chi co mot node con ben trai: %d\n", hieu);
    //3.5
    int index;
    int kcnn = gttd(a[0], hieu);
    for (int i=1; i<15; i++) {
        if (kcnn > gttd(a[i], hieu)) {
            kcnn = gttd(a[i], hieu);
            index = i;
        }
    }
    TreeNode *x = search(tree.root, a[index]);
    printf("Node gan gia tri hieu nhat co gia tri la: %d va dia chi la %p\n", x->data, (void*)&(x->data));
    return 0;
}