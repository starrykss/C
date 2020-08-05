// 링크 표현법으로 생성된 이진 트리의 순회
 
#include <stdio.h>
#include <stdarg.h>
#include <memory.h>
 
typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;
 
//       15
//    4     20
//  1     16  25
 
TreeNode n1 = { 9, NULL, NULL };
TreeNode n2 = { 8, NULL, NULL };
TreeNode n3 = { 7, NULL, NULL };
TreeNode n4 = { 6, NULL, &n1 };
TreeNode n5 = { 5, &n2, NULL };
TreeNode n6 = { 4, NULL, &n3 };
TreeNode n7 = { 3, &n5, &n4 };
TreeNode n8 = { 2, &n6, NULL };
TreeNode n9 = { 1, &n8, &n7 };

TreeNode *root = &n9;
 
// 중위 순회
void inorder(TreeNode *root) {
    if (root) {
        inorder(root->left);            // 왼쪽 서브 트리 순회
        printf("%d ", root->data);        // 노드 방문
        inorder(root->right);            // 오른쪽 서브 트리 순회
    }
}
 
// 전위 순회
void preorder(TreeNode *root) {
    if (root) {
        printf("%d ", root->data);        // 노드 방문
        preorder(root->left);            // 왼쪽 서브 트리 순회
        preorder(root->right);        // 오른쪽 서브 트리 순회
    }
}
 
// 후위 순회
void postorder(TreeNode *root) {
    if (root) {
        postorder(root->left);            // 왼쪽 서브 트리 순회
        postorder(root->right);        // 오른쪽 서브 트리 순회
        printf("%d ", root->data);        // 노드 방문
    }
}
 
void main() {
    printf("중위 순회 : ");
    inorder(root);
    printf("\n");
    printf("전위 순회 : ");
    preorder(root);
    printf("\n");
    printf("후위 순회 : ");
    postorder(root);
    printf("\n");
}