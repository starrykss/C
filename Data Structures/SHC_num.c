// 선형 조사법 구현 프로그램
 
#include <stdio.h>
#include <stdlib.h>
 
#define TABLE_SIZE 11      // 해시 테이블의 크기 = 소수
#define NEW_TABLE_SIZE 7   // 이중 해시법을 위한 해시 테이블의 크기
 
#define empty(e) (e.key == 0)
#define equal(e1, e2) (e1.key == e2.key)

typedef struct {
    int key; 
} element;

typedef struct ListNode {
    element item;
    struct ListNode *link;
} ListNode;

ListNode *hash_table[TABLE_SIZE];

// 제산 함수를 사용한 해싱 함수
int hash_function(int key) {
    return (key % TABLE_SIZE);
}

// 체이닝을 이용하여 테이블에 키를 삽입
void hash_chain_add(element item, ListNode *ht[]) {
    int hash_value = hash_function(item.key);
    ListNode *ptr;                    // 새로운 노드
    ListNode *node_before = NULL;     // 이전 노드
    ListNode *node = ht[hash_value];  // 현재 노드
    for (; node; node_before = node, node = node->link) {
        if (equal(node->item, item)) {
            fprintf(stderr, "탐색 키가 중복되었습니다. \n");
            return;
        }
    }
    ptr = (ListNode*)malloc(sizeof(ListNode));
    ptr->item = item;
    ptr->link = NULL;
    if (node_before) {  // 기존의 연결 리스트가 있다면
        node_before->link = ptr;
    }
    else {  // 기존의 연결 리스트가 없다면
        ht[hash_value] = ptr;
    }
}

// 체이닝을 이용하여 테이블에 저장된 키를 탐색
void hash_chain_find(element item, ListNode *ht[]) {
    ListNode *node;
 
    int hash_value = hash_function(item.key);
    for (node = ht[hash_value]; node; node = node->link) {
        if (equal(node->item, item)) {
            printf("키를 찾았음. \n");
            return;
        }
    }
    printf("키를 찾지 못했음. \n");
}
 
// 해싱 테이블의 내용을 출력
void hash_chain_print(ListNode *ht[]) {
    struct ListNode *node;
    int i;
    for (i = 0; i<TABLE_SIZE; i++) {
        printf("[%d]->", i);
        for (node = ht[i]; node; node = node->link) {
            printf("%d->", node->item.key);
        }
        printf("\n");
    }
}

void main() {
    element tmp;
    int op;

    while (1) {
        printf("원하는 연산을 입력하시오 (0=입력, 1=탐색, 2=종료)=");                                                             
        scanf("%d", &op);
        if (op == 2) break;
        printf("키를 입력하시오=");
        scanf("%d", &tmp.key);
        
        if (op == 0) {
            hash_chain_add(tmp, hash_table);
        }
        else if (op == 1) {
            hash_chain_find(tmp, hash_table);
        }
        hash_chain_print(hash_table);
    }
}