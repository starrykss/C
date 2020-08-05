// 이진 탐색 트리 프로그램
 
#include <stdio.h>
#include <stdlib.h>
 
typedef struct TreeNode {
    int key;
    int data;
    struct TreeNode *left, *right;
} TreeNode;
 
// 순환적인 탐색 함수
TreeNode *search(TreeNode *node, int key) {
    if (node == NULL) return NULL;
    if (key == node->key) return node;
    else if (key < node->key) {
        return search(node->left, key);
    }
    else {
        return search(node->right, key);
    }
}
 
void insert_node(TreeNode **root, int key) {
    TreeNode *p, *t;        // p는 부모 노드, t는 현재 노드
    TreeNode *n;            // n은 새로운 노드
 
    t = *root;
    p = NULL;
 
    // 탐색을 먼저 수행
    while (t != NULL) {
        if (key == t->key) return;        // 이미 존재
        p = t;
        if (key < p->key) t = p->left;
        else t = p->right;
    }
 
    // key가 트리 안에 없으므로 삽입 가능
    // 트리 노드 구성
    n = (TreeNode *)malloc(sizeof(TreeNode));
    if (n == NULL) return;
    
    // 데이터 복사
    n->key = key;
    n->left = n->right = NULL;
    
    // 부모 노드와 연결
    if (p != NULL) {
        if (key < p->key) {
            p->left = n;
        }
        else p->right = n;
    }
    else *root = n;
}
 
// 삭제 함수
void delete_node(TreeNode **root, int key) {
    TreeNode *p, *child, *succ, *succ_p, *t;
 
    // key를 갖는 노드 t를 탐색. p는 t의 부모 노드
    p = NULL;
    t = *root;
    
    // key를 갖는 노드 t를 탐색한다.
    while (t != NULL && t->key != key) {
        p = t;
        t = (key < p->key) ? p->left : p->right;
    }
 
    // 탐색이 종료된 시점에 t가 NULL이면 트리 안에 key가 없음
    if (t == NULL) {    // 탐색 트리에 없는 키
        printf("key is not in the tree");
        return;
    }
    
    // 첫 번째 경우 : 단말 노드인 경우
    if ((t->left == NULL) && (t->right == NULL)) {
        if (p != NULL) {
            // 부모 노드의 자식 필드를 NULL로 만든다.
            if (p->left == t) {
                p->left = NULL;
            }
            else p->right = NULL;
        }
        else {        // 만약 부모 노드가 NULL이면 삭제되는 노드가 루트
            *root = NULL;
        }
    }
 
    // 두 번째 경우 : 하나의 자식만 가지는 경우
    else if ((t->left == NULL) || (t->right == NULL)) {
        child = (t->left != NULL) ? t->left : t->right;
        if (p != NULL) {
            if (p->left == t) {    // 부모를 자식과 연결
                p->left = child;
            } 
            else p->right = child;
        }
        else {        // 만약 부모 노드가 NULL이면 삭제되는 노드가 루트
            *root = child;
        }
    }
 
    // 세 번째 경우 : 두 개의 자식을 가지는 경우
    else {
        // 오른쪽 서브 트리에서 후계자를 찾는다.
        succ_p = t;
        succ = t->right;
        // 후계자를 찾아서 계속 왼쪽으로 이동한다.
        while (succ->left != NULL) {
            succ_p = succ;
            succ = succ->left;
        }
        // 후속자의 부모와 자식을 연결
        if (succ_p->left == succ) {
            succ_p->left = succ->right;
        }
        else {
            succ_p->right == succ->right;
        }
        // 후속자가 가진 키 값을 현재 노드에 복사
        t->key = succ->key;
        // 원래의 후속자 삭제
        t = succ;
    }
    free(t);
}

// 출력 함수
void displayInorder(TreeNode *root) {
    if (root) {
        displayInorder(root->left);
        printf("%c_", root->key);
        displayInorder(root->right);
    }
}

TreeNode * SmallestNode(TreeNode *bst) {
    TreeNode *founded = bst;
    while (founded->left != NULL) {
        founded = founded->left;
    }
    return founded;
}

TreeNode * BiggestNode(TreeNode *bst) {
    TreeNode *founded = bst;
    while (founded->right != NULL) {
        founded = founded->right;
    }
    return founded;
}

void main() {
    TreeNode *root = NULL;
    TreeNode *foundedNode = NULL;
    char choice, key;
    
    // 트리 만들기
    insert_node(&root, 'G'); // 트리 만들기
    insert_node(&root, 'I');
    insert_node(&root, 'H');
    insert_node(&root, 'D');
    insert_node(&root, 'B');
    insert_node(&root, 'M');
    insert_node(&root, 'N');
    insert_node(&root, 'A');
    insert_node(&root, 'J');
    insert_node(&root, 'E');
    insert_node(&root, 'Q');

    printf("Smallest Node : %c\n", *SmallestNode(root));
    printf("Biggest Node : %c\n", *BiggestNode(root));

}