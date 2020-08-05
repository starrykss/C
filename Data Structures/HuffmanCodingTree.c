#include <stdio.h>
#include <stdlib.h>

#define MIN_HEAP_NODE	200

typedef int HNode;

HNode heap[MIN_HEAP_NODE];
int heap_size;

#define Key(n)   (n) 
#define Parent(i) (heap[i/2])	// i의 부모 노드 
#define Left(i) (heap[i*2])		// i의 왼쪽 자식 노드 
#define Right(i) (heap[i*2+1])	// i의 오른쪽 자식 노드 

void error(char str[]) {
	printf("%s\n", str);
	exit(1);
}

void init_heap() { heap_size = 0; }
int is_empty_heap() { return heap_size == 0; }
int is_full_heap() { return (heap_size == MIN_HEAP_NODE - 1); }
HNode find_heap() { return heap[1]; }

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

void make_tree(int freq[], int n) {
    HNode e1, e2;
    int i;

    init_heap();
    for (i = 0; i < n; i++) {
        insert_min_heap(freq[i]);
    }
    for (i = 1; i < n; i++) {
        e1 = delete_min_heap();
        e2 = delete_min_heap();
        insert_min_heap(Key(e1) + Key(e2));
        printf(" (%d+%d)\n", Key(e1), Key(e2));
    }
}


void main() {
	char label[] = {'a', 'd', 'g', 'j', 'm', 'o', 's', 'v', 'x', 'z'};
	int freq[] = {3, 15, 20, 8, 3, 11, 7, 12, 18, 9};
	// char label[] = {'A', 'B', 'C', 'D', 'E'};
    // int freq[] = {15, 12, 8, 6, 4};
    make_tree(freq, 10);
}