#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    char key;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;

typedef char element;

// 포인터 p가 가리키는 노드와 비교하여 노드 x를 삽입하는 연산
treeNode* insertNode(treeNode *p, char x) {
    treeNode *newNode;
    if (p == NULL) {
        newNode = (treeNode*)malloc(sizeof(treeNode));
        newNode->key = x;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    else if (x < p->key) p->left = insertNode(p->left, x);  // 새로운 노드 x가 부모 노드보다 작은 경우
    else if (x > p->key) p->right = insertNode(p->right, x); // 새로운 노드 x가 부모 노드보다 클 경우
    else printf("\n 이미 같은 키가 있습니다! \n");

    return p;
}

// root 노드부터 탐색하여 key 값과 같은 노드를 찾아 삭제하는 연산
void deleteNode(treeNode *root, element key) {
    treeNode *parent, *p, *succ, *succ_parent;
    treeNode *child;

    parent = NULL;
    p = root;

    // 삭제할 노드의 위치 탐색
    while ((p != NULL) && (p->key != key)) {    
        parent = p;
        if (key < p->key) p = p->left;
        else p = p->right;
    }
    
    // 삭제할 노드가 없는 경우
    if (p == NULL) { 
        printf("\n 찾는 키가 이진 트리에 없습니다! \n");
        return;
    }

    // 삭제할 노드가 단말 노드인 경우
    if ((p->left == NULL) && (p->right = NULL)) {
        if (parent != NULL) {
            if (parent->left == p) parent->left = NULL;
            else parent->right = NULL;
        }
        else root = NULL;
    }

    // 삭제할 노드가 한 개의 자식 노드를 가진 경우
    else if ((p->left == NULL) || (p->right == NULL)) {
        if (p->left != NULL) child = p->left;
        else child = p->right;

        if (parent != NULL) {
            if (parent->left == p) parent->left = child;
            else parent->right = child;
        }
        else root = child;
    }

    // 삭제할 노드가 두 개의 자식 노드를 가진 경우
    else {
        succ_parent = p;
        succ = p->left;
        while (succ->right != NULL) {
            succ_parent = succ;
            succ = succ->right;
        }
        if (succ_parent->left == succ) succ_parent->left = succ->left;
        else succ_parent->right = succ->left;
        p->key = succ->key;
        p = succ;
    }
    free(p);
}

// 이진 탐색 트리에서 키값이 x인 노드의 위치를 탐색하는 연산
treeNode* searchBST(treeNode *root, char x) {
    treeNode *p;
    p = root;
    while (p != NULL) {
        if (x < p->key) p = p->left;
        else if (x == p->key) return p;
        else p = p->right;
    }
    printf("\n 찾는 키가 없습니다!");
    return p;
}

// 이진 탐색 트리를 중위 순회하면서 출력하는 연산
void displayInorder(treeNode *root) {
    if (root) {
        displayInorder(root->left);
        printf("%c_", root->key);
        displayInorder(root->right);
    }
}

void menu() {
    printf("\n*----------------------------*");
    printf("\n\t1 : 트리 출력");
    printf("\n\t2 : 문자 삽입");
    printf("\n\t3 : 문자 삭제");
    printf("\n\t4 : 문자 검색");
    printf("\n\t5 : 종료");
    printf("\n*----------------------------*");
    printf("\n메뉴 입력 >> ");
}

int main() {
    treeNode *root = NULL;
    treeNode *foundedNode = NULL;
    char choice, key;

    root = insertNode(root, 'G'); // 트리 만들기
    insertNode(root, 'I');
    insertNode(root, 'H');
    insertNode(root, 'D');
    insertNode(root, 'B');
    insertNode(root, 'M');
    insertNode(root, 'N');
    insertNode(root, 'A');
    insertNode(root, 'J');
    insertNode(root, 'E');
    insertNode(root, 'Q');
    
    while (1) {
        menu();
        scanf("%d", &choice);
        // choice = getchar(); getchar();
        switch (choice) {
            case '1': printf("[이진트리 출력] ");
                    displayInorder(root); printf("\n\n\n");
                    break;
            case '2': printf("삽입할 문자를 입력하세요 : ");
                    key = getchar(); getchar();
                    insertNode(root, key);
                    break;
            case '3': printf("삭제할 문자를 입력하세요 : ");
                    key = getchar(); getchar();
                    deleteNode(root, key);
                    break;    
            case '4': printf("찾을 문자를 입력하세요 : ");
                    key = getchar(); getchar();
                    foundedNode = searchBST(root, key);
                    if (foundedNode != NULL) printf("\n %c 를 찾았습니다! \n", foundedNode->key);
                    else printf("\n 문자를 찾지 못했습니다. \n");
                    break;
            case '5': return 0;
            default: printf("없는 메뉴입니다. 메뉴를 다시 선택하세요! \n");
                     break;
        }
    }
    
}