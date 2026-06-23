#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data  = val;
    n->left  = NULL;
    n->right = NULL;
    return n;
}
int minBranchLength(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    if (!root->left)  return 1 + minBranchLength(root->right);
    if (!root->right) return 1 + minBranchLength(root->left);
    int l = minBranchLength(root->left);
    int r = minBranchLength(root->right);
    return 1 + (l < r ? l : r);
}
int treeHeight(Node* root) {
    if (!root) return 0;
    int l = treeHeight(root->left);
    int r = treeHeight(root->right);
    return 1 + (l > r ? l : r);
}

void countByLevel(Node* root, int level, int* counts) {
    if (!root) return;
    counts[level]++;
    countByLevel(root->left,  level + 1, counts);
    countByLevel(root->right, level + 1, counts);
}

int maxElementLevel(Node* root) {
    if (!root) return -1;
    int h = treeHeight(root);
    int* counts = (int*)calloc(h, sizeof(int));
    countByLevel(root, 0, counts);
    int bestLevel = 0;
    for (int i = 1; i < h; i++)
        if (counts[i] > counts[bestLevel])
            bestLevel = i;
    free(counts);
    return bestLevel;
}
int sumOneChild(Node* root) {
    if (!root) return 0;
    int hasLeft  = (root->left  != NULL);
    int hasRight = (root->right != NULL);
    int sum = 0;
    if (hasLeft ^ hasRight)
        sum += root->data;
    sum += sumOneChild(root->left);
    sum += sumOneChild(root->right);
    return sum;
}
int sumOnlyLeftChild(Node* root) {
    if (!root) return 0;
    int sum = 0;
    if (root->left && !root->right)
        sum += root->data;
    sum += sumOnlyLeftChild(root->left);
    sum += sumOnlyLeftChild(root->right);
    return sum;
}

int difference34(Node* root) {
    return sumOneChild(root) - sumOnlyLeftChild(root);
}
#define MY_ABS(x) ((x) < 0 ? -(x) : (x))

static Node* closestNode = NULL;
static int   closestDiff = 2147483647; /* INT_MAX không dùng limits.h */

void findClosest(Node* root, int target) {
    if (!root) return;
    int diff = MY_ABS(root->data - target);
    if (diff < closestDiff) {
        closestDiff = diff;
        closestNode = root;
    }
    findClosest(root->left,  target);
    findClosest(root->right, target);
}

Node* nodeClosestTo(Node* root, int target) {
    closestNode = NULL;
    closestDiff = 2147483647;
    findClosest(root, target);
    return closestNode;
}
int main() {
    Node* root               = createNode(10);
    root->left               = createNode(5);
    root->right              = createNode(20);
    root->left->left         = createNode(3);
    root->left->right        = createNode(7);
    root->right->right       = createNode(25);
    root->left->right->right = createNode(8);

    printf("3.1 - So phan tu nhanh ngan nhat      : %d\n",
           minBranchLength(root));

    printf("3.2 - Level co nhieu phan tu nhat      : %d\n",
           maxElementLevel(root));

    int s33 = sumOneChild(root);
    printf("3.3 - Tong cac node co 1 node con      : %d\n", s33);

    int diff = difference34(root);
    printf("3.4 - Hieu (3.3 - tong chi co con trai): %d\n", diff);

    Node* closest = nodeClosestTo(root, diff);
    if (closest)
        printf("3.5 - Node gan gia tri %d nhat         : %d\n",
               diff, closest->data);

    return 0;
}