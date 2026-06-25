#include <stdio.h>
#include <stdlib.h>

typedef struct NodeType
{
    int data;
    struct NodeType *left;
    struct NodeType *right;
} TreeNode;

typedef struct BinaryTreeType
{
    struct NodeType *root;
} BinaryTree;

TreeNode *makeNode(int data)
{
    TreeNode *new = (TreeNode *)malloc(sizeof(TreeNode));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void print(TreeNode *node)
{
    if (node == NULL)
        return;
    print(node->left);
    printf("%d ", node->data);
    print(node->right);
}

void init(BinaryTree *tree)
{
    if (tree != NULL)
    {
        tree->root = NULL;
    }
}
TreeNode *insertNode(TreeNode *node, int data)
{
    if (node == NULL)
    {
        return makeNode(data);
    }
    if (data < node->data)
    {
        node->left = insertNode(node->left, data);
    }
    else
    {
        node->right = insertNode(node->right, data);
    }
    return node;
}
void insert(BinaryTree *tree, int data)
{
    if (tree != NULL)
    {
        tree->root = insertNode(tree->root, data);
    }
}
TreeNode *searchBST(TreeNode *node, int val)
{
    if (node == NULL || val == node->data)
        return node;

    if (val < node->data)
    {
        return searchBST(node->left, val);
    }
    else
    {
        return searchBST(node->right, val);
    }
    return NULL;
}
TreeNode *search(TreeNode *node, int val)
{
    if (node == NULL || val == node->data)
        return node;
    TreeNode *leftFind = search(node->left, val);
    if (leftFind != NULL)
    {
        return leftFind;
    }
    return search(node->right, val);
}
void deleteBST(BinaryTree *tree, int val)
{
    TreeNode *curr = tree->root;
    TreeNode *prev = NULL;

    while (1)
    {
        // Case 1: not found
        if (curr == NULL)
        {
            printf("NULL");
            return;
        }
        if (curr->data == val)
        {
            // Case 2: no child / leaf
            if (curr->left == NULL && curr->right == NULL)
            {
                if (prev == NULL)
                    tree->root = NULL;
                else if (prev->left == curr)
                    prev->left = NULL;
                else
                    prev->right = NULL;
                free(curr);
            }
            // Case 3: one child
            else if (curr->left == NULL || curr->right == NULL)
            {
                TreeNode *child = (curr->left != NULL) ? curr->left : curr->right;
                if (prev == NULL)
                    tree->root = child;
                else if (prev->left == curr)
                    prev->left = child;
                else
                    prev->right = child;
                free(curr);
            }
            // Trường hợp node có 2 con (Case 4 và Case 5)
            // Thay thế bằng node trái nhất (nhỏ nhất) của cây con bên phải
            else
            {
                TreeNode *succParent = curr;
                TreeNode *succ = curr->right;

                // Case 4: children (leafs)
                if (succ->left == NULL)
                {
                    curr->data = succ->data;
                    curr->right = succ->right;
                    free(succ);
                }
                // Case 5: curr->right is not a leaf leaf (duyệt xuống bên trái tìm min)
                else
                {
                    while (succ->left != NULL)
                    {
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
        if (val < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
}
// Hàm duyệt toàn bộ cây để tìm node cần xóa và node cha của nó
void findNodeAndParent(TreeNode *curr, TreeNode *parent, int val, TreeNode **target, TreeNode **targetParent)
{
    // Nếu đã duyệt hết nhánh hoặc đã tìm thấy node thì dừng lại
    if (curr == NULL || *target != NULL)
        return;

    if (curr->data == val)
    {
        *target = curr;
        *targetParent = parent;
        return;
    }

    // quét hết nhánh trái
    findNodeAndParent(curr->left, curr, val, target, targetParent);
    
    // quét hét nhánh phải
    findNodeAndParent(curr->right, curr, val, target, targetParent);
}
void delete(BinaryTree *tree, int val)
{
    if (tree == NULL || tree->root == NULL)
    {
        printf("NULL\n");
        return;
    }

    TreeNode *curr = NULL;
    TreeNode *prev = NULL;

    // Tìm node cần xóa và node cha
    findNodeAndParent(tree->root, NULL, val, &curr, &prev);

    // Case 1: Không tìm thấy
    if (curr == NULL)
    {
        printf("Khong tim thay 12\n");
        return;
    }

    // Case 2: Node là leaf
    if (curr->left == NULL && curr->right == NULL)
    {
        if (prev == NULL)
            tree->root = NULL;
        else if (prev->left == curr)
            prev->left = NULL;
        else
            prev->right = NULL;
        free(curr);
    }
    // Case 3: Node có 1 con
    else if (curr->left == NULL || curr->right == NULL)
    {
        TreeNode *child = (curr->left != NULL) ? curr->left : curr->right;
        if (prev == NULL)
            tree->root = child;
        else if (prev->left == curr)
            prev->left = child;
        else
            prev->right = child;
        free(curr);
    }
    // Trường hợp node có 2 con (Case 4 và Case 5)
    else
    {
        TreeNode *succParent = curr;
        TreeNode *succ = curr->right;

        // Case 4: children (leafs)
        if (succ->left == NULL)
        {
            curr->data = succ->data;
            curr->right = succ->right;
            free(succ);
        }
        // Case 5: curr->right is not a leaf (duyệt xuống bên trái tìm node trái nhất)
        else
        {
            while (succ->left != NULL)
            {
                succParent = succ;
                succ = succ->left;
            }
            curr->data = succ->data;
            succParent->left = succ->right;
            free(succ);
        }
    }
}
TreeNode* copyTree(TreeNode *root) {
    if (root == NULL) {
        return NULL;
    }
    TreeNode* newRoot = makeNode(root->data);
    newRoot->left = copyTree(root->left);
    newRoot->right = copyTree(root->right);
    return newRoot;
}
TreeNode* level3(TreeNode *node, int k) {
    if (node == NULL) 
        return NULL;
    if (k==3) {
        printf("%d ", node->data);
        return NULL;
    }
    TreeNode *leftFind = level3(node->left, k+1);
    if (leftFind != NULL) {
        return leftFind;
    }
    return level3(node->right, k+1);
}
int main()
{
    BinaryTree tree1;
    BinaryTree tree2;
    BinaryTree tree3;
    BinaryTree tree4;
    BinaryTree tree1Copy;
    BinaryTree tree2Copy;
    BinaryTree tree3Copy;
    BinaryTree tree4Copy;
    BinaryTree tree1Copy1;
    BinaryTree tree2Copy1;
    BinaryTree tree3Copy1;
    BinaryTree tree4Copy1;
    init(&tree1);
    init(&tree2);
    init(&tree3);
    init(&tree4);
    init(&tree1Copy);
    init(&tree2Copy);
    init(&tree3Copy);
    init(&tree4Copy);
    init(&tree1Copy1);
    init(&tree2Copy1);
    init(&tree3Copy1);
    init(&tree4Copy1);
    // insert 1.1
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
    tree1Copy.root = copyTree(tree1.root);
    tree1Copy1.root = copyTree(tree1.root);
    int a2[100] = {50, 17, 76, 9, 23, 54, 14, 19, 72, 12, 67};
    int a3[100] = {15, 11, 26, 8, 12, 20, 30, 6, 9, 14, 35};
    // insert các cây ở câu 1.2
    for (int i = 0; i < 11; i++)
    {
        insert(&tree2Copy1, a2[i]);
        insert(&tree2Copy, a2[i]);
        insert(&tree2, a2[i]);
    }
    // insert các cây ở câu 1.3
    for (int i = 0; i < 11; i++)
    {
        insert(&tree3Copy1, a3[i]);
        insert(&tree3Copy, a3[i]);
        insert(&tree3, a3[i]);
    }
    // insert các cây ở câu 1.4
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
    tree4Copy.root = copyTree(tree4.root);
    tree4Copy1.root = copyTree(tree4.root);
    // Tim phan tu 25
    TreeNode *x1 = search(tree1.root, 25);
    if (x1 != NULL)
    {
        printf("Cay 1.1, Val = %d; Node address: %p\n", 25, (void *)&(x1->data));
    }
    else
        printf("Cay 1.1, Val = %d => NULL\n", 25);

    TreeNode *x2 = searchBST(tree2.root, 25);
    if (x2 != NULL)
    {
        printf("Cay 1.2, Val = %d; Node address: %p\n", 25, (void *)&(x2->data));
    }
    else
        printf("Cay 1.2, Val = %d => NULL\n", 25);

    TreeNode *x3 = searchBST(tree3.root, 25);
    if (x3 != NULL)
    {
        printf("Cay 1.3, Val = %d; Node address: %p\n", 25, (void *)&(x3->data));
    }
    else
        printf("Cay 1.3, Val = %d => NULL\n", 25);

    TreeNode *x4 = search(tree4.root, 25);
    if (x4 != NULL)
    {
        printf("Cay 1.4, Val = %d; Node address: %p\n", 25, (void *)&(x4->data));
    }
    else {
        printf("Cay 1.4, Val = %d => NULL\n", 25);
    }
    printf("\n");
    // Xoa phan tu 12
    delete(&tree1, 12);
    printf("Xoa phan tu 12 cay 1.1: ");
    print(tree1.root);
    printf("\n");
    deleteBST(&tree2, 12);
    printf("Xoa phan tu 12 cay 1.2: ");
    print(tree2.root);
    printf("\n");
    deleteBST(&tree3, 12);
    printf("Xoa phan tu 12 cay 1.3: ");
    print(tree3.root);
    printf("\n");
    printf("Cay 1.4: ");
    delete(&tree4, 12);
    printf("\n");
    //Chen phan tu 23
    insert(&tree1Copy, 23);
    print(tree1Copy.root);
    printf("\n");
    insert(&tree2Copy, 23);
    print(tree2Copy.root);
    printf("\n");
    insert(&tree3Copy, 23);
    print(tree3Copy.root);
    printf("\n");
    insert(&tree4Copy, 23);
    print(tree4Copy.root);
    printf("\n\n");
    //Level 3 cua cay
    printf("Cay 1.1: ");
    level3(tree1Copy1.root, 0);
    printf("\n");
    printf("Cay 1.2: ");
    level3(tree2Copy1.root, 0);
    printf("\n");
    printf("Cay 1.3: ");
    level3(tree3Copy1.root, 0);
    printf("\n");
    printf("Cay 1.4: ");
    level3(tree4Copy1.root, 0);
    printf("\n");
    return 0;
}