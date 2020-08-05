// Tree Sort
#include <stdio.h>
#include <stdlib.h>

#define N 8 

typedef int TElement;

typedef struct BinTrNode {
    TElement     data;
    struct BinTrNode* left;
    struct BinTrNode* right;
} TNode;
TNode *root;

void init_tree() { root = NULL; }
int is_empty_tree() { return root == NULL; }

TNode* create_tree(TElement val, TNode* l, TNode* r) {
    TNode* n = (TNode*)malloc(sizeof(TNode));
    n->data = val;
    n->left = l;
    n->right = r;
    return n;
}

void inorder(TNode *n, int **ary) {
    if (n != NULL) {
        inorder(n->left, ary);
        **ary = n->data;
        ++*ary;
        inorder(n->right, ary);
    }
}

// 이진탐색트리 삽입
int insert(TNode *r, TNode* n) {
    if (n->data == r->data) return 0;
    else if (n->data < r->data) {
        if (r->left == NULL) r->left = n;
        else insert(r->left, n);
    }
    else {
        if (r->right == NULL) r->right = n;
        else insert(r->right, n);
    }
    return 1;
}

void insert_BST(int key) {
    TNode *n = create_tree(key, NULL, NULL);
    if (is_empty_tree())
        root = n;
    else if (insert(root, n) == 0)
        free(n);
}

void TreeSort(int ary[], int size) {
    int *temp = ary;

    init_tree();
    for (int i = 0; i < size; i++) {
        insert_BST(ary[i]);
    }
    inorder(root, &temp);
}

void main() {
    int data[N] = {69, 10, 30, 2, 16, 8, 31, 22};
    int temp;

    printf("정렬 전 : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // 트리 정렬 알고리즘
    TreeSort(data, N);

    printf("정렬 후 : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}