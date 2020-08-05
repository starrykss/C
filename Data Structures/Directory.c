// 디렉터리 용량 계산 프로그램
 
#include <stdio.h>
#include<stdlib.h>
#include <memory.h>
 
typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;
 
int calc_direc_size(TreeNode *root) {
    int total_size = 0;
    if (root) {
        total_size = root->data + calc_direc_size(root->left) + calc_direc_size(root->right);
    }
    return total_size;
}
 
void main() {
    TreeNode n4 = { 500, NULL, NULL };
    TreeNode n5 = { 200, NULL, NULL };
    TreeNode n3 = { 100, &n4, &n5 };
    TreeNode n2 = { 50, NULL, NULL };
    TreeNode n1 = { 0, &n2, &n3 };
 
    printf("디렉토리의 크기 = %d \n", calc_direc_size(&n1));
}