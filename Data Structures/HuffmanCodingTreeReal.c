#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENT 100
#define MAX_CODE 100
#define ALPHA_SIZE 58

typedef struct TreeNode {
    int weight;
    int alpha;
    char code[MAX_CODE];
    int depth;
    struct TreeNode *left_child;
    struct TreeNode *right_child;
} TreeNode;

typedef struct {
    TreeNode *ptree;
    int key;
} element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

void init(HeapType *h) { h->heap_size = 0; }

void insert_min_heap(HeapType *h, element item) {
    int i;

    i = ++(h->heap_size);
    while ((i != 1) && (item.key < h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;    
}

element delete_min_heap(HeapType *h) {
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];

    parent = 1;
    child = 2;

    while (child <= h->heap_size) {
        if ((child <= h->heap_size) &&
            (h->heap[child].key) > h->heap[child + 1].key)
            child++;
        if (temp.key < h->heap[child].key) break;

        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;

    return item;
}



TreeNode *make_tree(TreeNode *left, TreeNode *right) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    if (node == NULL) {
        fprintf(stderr, "메모리 에러\n");
        exit(1);
    }

    node->left_child = left;
    node->right_child = right;

    return node;
}

void destroy_tree(TreeNode *root) {
    if (root == NULL) return;
    destroy_tree(root->left_child);
    destroy_tree(root->right_child);
    free(root);
}

void huffman_code(TreeNode* r, int n, char* code) {
    if (r) {
        n++;
        code[n] = '1';
        huffman_code(r->right_child, n, code);
        code[n] = '0';
        huffman_code(r->left_child, n, code);
        code[n] = '\0';
        if (r->left_child == NULL && r->right_child == NULL ) {
            strcpy(r->code, code);
            r->depth = n;
        }
    }
}

void sub_order(TreeNode *r, int i) {
    if (r) {
        sub_order(r->right_child, i);
        sub_order(r->left_child, i);
        if ((r->left_child == NULL || r->right_child == NULL) && r->depth == i) {
            printf("weight = %2d depth = %d char = %c code = %s \n", r->weight, r->depth, r->alpha, r->code);
        }
    }
}

void level_order(TreeNode *r) {
    int i;
    for (i = 0; i < 10; i++) {
        sub_order(r, i);
    }
}

void huffman_tree(int freq[], int n) {
    int i;
    int j = 0;
    TreeNode *node, *x;
    HeapType heap;
    element e, e1, e2;

    char* code = (char*)malloc(sizeof(char));
    init(&heap);
    for (i = 0; i<n; i++) {
            node = make_tree(NULL, NULL);
            e.key = node->weight = freq[i];
            node->alpha = (i + 65);
            e.ptree = node;
            insert_min_heap(&heap, e);
            j++;
    }

    for (i = 1; i<j; i++) {
        e1 = delete_min_heap(&heap);      
        e2 = delete_min_heap(&heap);
        x = make_tree(e1.ptree, e2.ptree); 
        e.key = x->weight = e1.key + e2.key;
        e.ptree = x;
        insert_min_heap(&heap, e);
    }
    e = delete_min_heap(&heap);
    huffman_code(e.ptree, -1, code);
    level_order(e.ptree);
    destroy_tree(e.ptree);
}

void main() {
    int i = 0;
    int freq[ALPHA_SIZE] = { 0 };

    FILE* stream = fopen("word_list.txt", "r");
    if (stream == NULL) { puts("파일이 없습니다."); }
    while (i != EOF) {
        i = fgetc(stream);

        if ((0 <= (i - 65) <= 25) || (32 <= (i - 65) <= 57)) {
            freq[i - 65] += 1;
        }
    }
    fclose(stream);
    huffman_tree(freq, ALPHA_SIZE);
}