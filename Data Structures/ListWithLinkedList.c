#include <stdio.h> 
#include <stdlib.h> 

typedef int Element;
typedef struct LinkedNode {
	Element data;
	struct LinkedNode* link;
} Node;
Node *head = NULL;

void init_list() { head = NULL; }
int is_empty() { return head == NULL; }

Node *get_entry(int pos) {
	Node* p = head;
	int i;
	for (i = 0; i<pos; i++, p = p->link) {
		if (p == NULL) return NULL;
    }
	return p;
}

int size() {
	Node* p;
	int count = 0;
	for (p = head; p != NULL; p = p->link) {
		count++;
    }
	return count;
}

void replace(int pos, Element val) {
	Node* node = get_entry(pos);
	if (node != NULL) {
		node->data = val;
    }
}
Node *find(Element val) {
	Node* p;
	for (p = head; p != NULL; p = p->link) {
        if (p->data == val) return p;
    }
	return NULL;
}

void insert_next(Node *before, Node *node) {
	if (node != NULL) {
		node->link = before->link;
		before->link = node;
	}
}

void insert(int pos, Element val) {
	Node *new_node, *prev;

	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = val;
	new_node->link = NULL;

	if (pos == 0) {
		new_node->link = head;
		head = new_node;
	}
	else {
		prev = get_entry(pos - 1);
		if (prev != NULL) {
            insert_next(prev, new_node);
        }
		else free(new_node);
	}
}

Node *remove_next(Node *prev) {
	Node* removed = prev->link;
	if (removed != NULL) {
        prev->link = removed->link;
    }
		
	return removed;
}

void delete(int pos) {
	Node* prev, *removed;

	if (pos == 0 && is_empty() == 0) {
		removed = head;
		head = head->link;
		free(removed);
	}
	else {
		prev = get_entry(pos - 1);
		if (prev != NULL) {
			removed = remove_next(prev);
			free(removed);
		}
	}
}

void clear_list() {
	while (is_empty() == 0) {
        delete(0);
    }
}

void print_list(char* msg) {
	Node* p;
	printf("%s[%2d]: ", msg, size());
	for (p = head; p != NULL; p = p->link) {
		printf("%2d ", p->data);
    }
	printf("\n");
}

void main() {
	int i, n, val, data;
	Node *p;

	init_list( );
	printf("노드의 개수 : ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("노드 #%d의 데이터 : ", i+1);
		scanf("%d", &val);
		insert(i, val);
	}
	// 연결 리스트의 맨 끝에 새로운 노드를 추가하는 코드*****/
	// 2번 문제 정답 코드 추가 위치
	printf("끝에 추가할 데이터 : ");
	scanf("%d", &data);
	insert(size(), data);
	/////////////////////////////////////////////////////

	printf("생성된 연결 리스트: ");
	p = head;
	if (head != NULL) {
		printf("%d", head->data);
		for (p = head->link; p != NULL; p = p->link)
			printf("->%d", p->data);
		printf("\n");
	}


	// 생성된 연결 리스트의 맨 처음에 있는 노드를 삭제하는 코드
	// 3번 문제 정답 코드 추가 위치
	delete(0);
	printf("첫 번째 노드 삭제 후 연결 리스트: ");
	p = head;
	if (head != NULL) {
		printf("%d", head->data);
		for (p = head->link; p != NULL; p = p->link)
			printf("->%d", p->data);
		printf("\n");
	}
	////////////////////////////////////////////////////////

	
	clear_list( );
}