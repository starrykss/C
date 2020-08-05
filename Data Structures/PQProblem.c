// 문제4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 100   // 최대 입력받는 문자열의 개수
#define MAX_HEAP_NODE 200    // 최대 우선 순위 개수

typedef struct {
    int priority;
    char content[MAX_STRING_SIZE];
} ToDoType;

typedef int HNode;
typedef struct {
    ToDoType heap[MAX_HEAP_NODE]; // heap = priority
    int heap_size;
} HeapType;

void error(char str[]) {
	printf("%s\n", str);
	exit(1);
}

void init_heap(HeapType *hp) { hp->heap_size = 0; }
int is_empty_heap(HeapType *hp) { return hp->heap_size == 0; }
int is_full_heap(HeapType *hp) { return (hp->heap_size == MAX_HEAP_NODE - 1); }
HNode find_heap(HeapType *hp) { return hp->heap[1].priority; }

void insert_min_heap(HeapType *hp, HNode n, char *todo) {
	int i;
	if (is_full_heap(hp)) return;
	i = ++(hp->heap_size);
	while (i != 1 && n < hp->heap[i/2].priority) {
		hp->heap[i].priority = hp->heap[i/2].priority;
		i /= 2;
	}
	hp->heap[i].priority = n;
    strcpy(hp->heap[hp->heap[i].priority].content, todo);
}

HNode delete_min_heap(HeapType *hp) {
	HNode hroot, last;
	int parent = 1, child = 2;

	if (is_empty_heap(hp) != 0)
		error("힙 트리 공백 에러");

	hroot = hp->heap[1].priority;
	last = hp->heap[hp->heap_size--].priority;
	while (child <= hp->heap_size) {
		if (child <= hp->heap_size && hp->heap[parent*2].priority > hp->heap[parent*2+1].priority)
			child++;
		if (last < hp->heap[child].priority)
			break;
		hp->heap[parent].priority = hp->heap[child].priority;
		parent = child;
		child *= 2;
	}
	hp->heap[parent].priority = last;
	return hroot;
}

void print_heap(HeapType *hp) {
	int i, level;
	for (i = 1, level = 1; i <= hp->heap_size; i++) {
		if (i == level) {
			printf("\n");
			level *= 2;
		}
		printf("%2d ", hp->heap[i].priority);
	}
	printf("\n-----------");
}

void main() {
    HeapType hp;
    char choice, todo[MAX_STRING_SIZE];
    int priority;

    init_heap(&hp);
    
    while (1) {
        printf("삽입(i), 삭제(d): ");
        scanf("%c", &choice);
        getchar();

        switch (choice) {
            case 'i':
                printf("할일: ");
                gets(todo);
                printf("우선순위: ");
                scanf("%d", &priority);
                getchar(); // 엔터 무시
                insert_min_heap(&hp, priority, todo);
                printf("\n");
                break;
            case 'd':
                printf("제일 우선순위가 높은 일은 \"%s\"\n\n", hp.heap[delete_min_heap(&hp)].content);
                break;
            default:
                printf("메뉴선택 다시 하세요.\n\n");
            }
    }
}