// 이차 조사법 구현 프로그램
 
#include <stdio.h>
#include <stdlib.h>
 
#define TABLE_SIZE 11      // 해시 테이블의 크기 = 소수
 
#define empty(e) (e.key == 0)
#define equal(e1, e2) (e1.key == e2.key)

typedef struct {
    int key; 
} element;

element hash_table[TABLE_SIZE]; 

void init_table(element ht[]) {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        ht[i].key = 0;
    }
}

// 제산 함수를 사용한 해싱 함수
int hash_function(int key) {
    return (key % TABLE_SIZE);
}

// 이차 조사법의 구현
void hash_qp_add(element item, element ht[]) {
    int i, hash_value, inc = 1;
    
    hash_value = i = hash_function(item.key);
    
    while (!empty(ht[i])) {
        if (equal(item, ht[i])) {
            fprintf(stderr, "탐색 키가 중복되었습니다. \n");
            exit(1);
        }

        // i = (i + inc + 1) % TABLE_SIZE;
        // inc = inc + 2;
        
        i = (hash_value + inc*inc) % TABLE_SIZE;
        inc = inc + 1;

        if (i == hash_value) {
            fprintf(stderr, "테이블이 가득 찼습니다. \n");
            exit(1);
        }
    }
    ht[i] = item;
}

// 이차 조사법을 이용하여 테이블에 저장된 키를 탐색
void hash_qp_search(element item, element ht[]) {
    int i, hash_value, inc = 1;
    hash_value = i = hash_function(item.key);
    while (!empty(ht[i])) {
        if (equal(item, ht[i])) {
            fprintf(stderr, "탐색성공: 위치 = %d\n", i);
            return;
        }

        i = (hash_value + inc*inc) % TABLE_SIZE;
        inc = inc + 1;

        if (i == hash_value) {
            fprintf(stderr, "찾는 값이 테이블에 없음.\n");
            return;
        }
    }
    fprintf(stderr, "찾는 값이 테이블에 없음. \n)");
}

// 해싱 테이블의 내용을 출력
void hash_qp_print(element ht[]) {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        printf("[%2d] %5d\n", i, ht[i].key);
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
            hash_qp_add(tmp, hash_table);
        }
        else if (op == 1) {
            hash_qp_search(tmp, hash_table);
        }
        hash_qp_print(hash_table);
    }
}