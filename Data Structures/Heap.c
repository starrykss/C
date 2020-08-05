#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_NODE	200

typedef int HNode;

HNode heap[MAX_HEAP_NODE];
int heap_size;

#define Key(n)   (n) 
#define Parent(i) (heap[i/2])	// i의 부모 노드 
#define Left(i) (heap[i*2])	// i의 왼쪽 자식 노드 
#define Right(i) (heap[i*2+1])	// i의 오른쪽 자식 노드 

void error(char str[]) {
	printf("%s\n", str);
	exit(1);
}

void init_heap() { heap_size = 0; }
int is_empty_heap() { return heap_size == 0; }
int is_full_heap() { return (heap_size == MAX_HEAP_NODE - 1); }
HNode find_heap() { return heap[1]; }

// 최대 히프 삽입
void insert_max_heap(HNode n) {
	int i;
	if (is_full_heap()) return;
	i = ++(heap_size);
	while (i != 1 && Key(n) > Key(Parent(i))) {
		heap[i] = Parent(i);
		i /= 2;
	}
	heap[i] = n;
}

// 최대 히프 삭제
HNode delete_max_heap() {
	HNode hroot, last;
	int parent = 1, child = 2;

	if (is_empty_heap() != 0)
		error("힙 트리 공백 에러");

	hroot = heap[1];
	last = heap[heap_size--];
	while (child <= heap_size) {
		if (child < heap_size && Key(Left(parent)) < Key(Right(parent)))
			child++;
		if (Key(last) >= Key(heap[child]))
			break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = last;
	return hroot;
}

// 최소 히프 삽입
void insert_min_heap(HNode n) {
	int i;
	if (is_full_heap()) return;
	i = ++(heap_size);
	while (i != 1 && Key(n) < Key(Parent(i))) {
		heap[i] = Parent(i);
		i /= 2;
	}
	heap[i] = n;
}

// 최소 히프 삭제
HNode delete_min_heap() {
	HNode hroot, last;
	int parent = 1, child = 2;

	if (is_empty_heap() != 0)
		error("힙 트리 공백 에러");

	hroot = heap[1];
	last = heap[heap_size--];

	while (child <= heap_size) {
		if (child <= heap_size && Key(Left(parent)) > Key(Right(parent)))
			child++;
		if (Key(last) < Key(heap[child]))
			break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = last;
	return hroot;
}

void print_heap() {
	int i, level;
	for (i = 1, level = 1; i <= heap_size; i++) {
		if (i == level) {
			printf("\n");
			level *= 2;
		}
		printf("%2d ", Key(heap[i]));
	}
	printf("\n-----------");
}

void main() {
	init_heap();

    insert_max_heap(10);
    insert_max_heap(40);
    insert_max_heap(30);
    insert_max_heap(5);
    insert_max_heap(12);
    insert_max_heap(6);
    insert_max_heap(15);
    insert_max_heap(9);
    insert_max_heap(60);
    print_heap();

    for (int i = 0; i < heap_size + 2; i++) {
        printf("[%2d]", Key(heap[i]));
    }

    delete_max_heap();
    print_heap();

    for (int i = 0; i < heap_size + 2; i++) {
        printf("[%2d]", Key(heap[i]));
    }
    

    /*
	// MAX HEAP
	insert_max_heap(2);		insert_max_heap(5);
	insert_max_heap(4);		insert_max_heap(8);
	insert_max_heap(9);		insert_max_heap(3);
	insert_max_heap(7);		insert_max_heap(3);
	print_heap();

	delete_max_heap();	print_heap();
	delete_max_heap();	print_heap();
	printf("\n");
	*/
	/*
	// MIN HEAP
    insert_min_heap(2);		insert_min_heap(5);
	insert_min_heap(4);		insert_min_heap(8);
	insert_min_heap(9);		insert_min_heap(3);
	insert_min_heap(7);		insert_min_heap(3);
	print_heap();

    delete_min_heap();	print_heap();
	delete_min_heap();	print_heap();

	printf("\n");
	*/
}