// BFS 구현 (인접 리스트 이용)
// 인접행렬로 표현된 그래프의 정보는 "graph.txt" 파일 안에 입력되어 있음.
#include <stdio.h>
#include <stdlib.h>

#define MAX_VTXS 256

typedef char VtxData;            // 그래프 정점에 저장할 데이터의 자료형     

typedef struct GraphNode {
    int id;                    // 정점의 id
    struct GraphNode* link;    // 다음 노드의 포인터
} GNode;

typedef struct {
    int vsize;  // 정점의 개수
    GNode *adj_list[MAX_VTXS];  // 각 정점의 인접 리스트
} GraphType;

VtxData vdata[MAX_VTXS];  // 정점에 저장할 데이터 배열
int visited[MAX_VTXS];

void error(char str[]) {
    printf("%s\n", str);
    exit(1);
}

//////////////// 큐 구현 함수 ////////////////

#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct { // 큐 타입
	element  queue[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

void init_queue(QueueType *q) {
	q->front = q->rear = 0;
}

int is_empty(QueueType *q) {
	return (q->front == q->rear);
}

int is_full(QueueType *q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 삽입 함수
void enqueue(QueueType *q, element item) {
	if (is_full(q)) {
		error("큐가 포화상태입니다");
    }
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType *q) {
	if (is_empty(q)) {
		error("큐가 공백상태입니다");
    }
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

//////////////////////////////////////////////////////////


int is_empty_graph(GraphType *g) { return (g->vsize == 0); }
int is_full_graph(GraphType *g) { return (g->vsize >= MAX_VTXS); }

void init_graph(GraphType *g) {
    int i;
    g->vsize = 0;
    for (i = 0; i < MAX_VTXS; i++) {
        g->adj_list[i] = NULL;
    }
}

void reset_graph(GraphType *g) {
    int i;
    GNode* n;

    for (i = 0; i < g->vsize; i++) {
        while (g->adj_list[i] != NULL) {
            n = g->adj_list[i];
            g->adj_list[i] = n->link;
            free(n);
        }
    }
    g->vsize = 0;
}

void insert_vertex(GraphType *g, VtxData name) {
    if (is_full_graph(g)) {
        error("Error: 그래프 정점의 개수 초과\n");
    }
    else {
        vdata[g->vsize++] = name;
    }
}

void insert_edge(GraphType *g, int u, int v) {
    GNode *n = (GNode*)malloc(sizeof(GNode));
    GNode *t;

    n->id = v;
    n->link = NULL;

    if (g->adj_list[u] == NULL) {
        g->adj_list[u] = n;
    }
    else {
        t = g->adj_list[u];
        while (t->link != NULL) {
            t = t->link;
        }
        t->link = n;
    }
    
    /* 인접리스트 내부가 정렬되지 않음
    n->id = v;
    n->link = g->adj_list[u];
    g->adj_list[u] = n;
    */
}

void print_graph(GraphType *g, char* msg) {
    int i;
    GNode* v;
    printf("%s%d\n", msg, g->vsize);
    for (i = 0; i < g->vsize; i++) {
        printf("%c  ", vdata[i]);
        for (v = g->adj_list[i]; v != NULL; v = v->link) {
            printf("   %c", vdata[v->id]);
        }
        printf("\n");
    }
}

void load_graph(GraphType *g, char *filename) {
    int i, j, val, n;
    
    char str[80];
    FILE *fp = fopen(filename, "r");
    if (fp != NULL) {
        init_graph(g);
        fscanf(fp, "%d", &n);
        for (i = 0; i<n; i++) {
            fscanf(fp, "%s", str);
            insert_vertex(g, str[0]);
            for (j = 0; j<n; j++) {
                fscanf(fp, "%d", &val);
                if (val != 0)
                    insert_edge(g, i, j);
            }
        }
        fclose(fp);
    }
}

void reset_visited(GraphType *g) {
    int i;
    for (i = 0; i < g->vsize; i++) {
        visited[i] = 0;
    }
}

void BFS_list(GraphType *g, int v) {
	GNode *w;
	QueueType q;

	init_queue(&q);    // 큐 초기 화 
	visited[v] = 1; // 정점 v 방문 표시 
	printf("%c ", vdata[v]);
	enqueue(&q, v);  // 시작정점을 큐에 저장 
	while (!is_empty(&q)) {
		v = dequeue(&q);  // 큐에 저장된 정점 선택 
		for (w = g->adj_list[v]; w; w = w->link) //인접 정점 탐색
			if (!visited[w->id]) {	// 미방문 정점 탐색 
				visited[w->id] = 1;   // 방문 표시
				printf("%c ", vdata[w->id]);
				enqueue(&q, w->id);	//정점을 큐에 삽입
			}
	}
}

void main() {
    GraphType g;

    init_graph(&g);
    load_graph(&g, "graph.txt");
    reset_visited(&g);
    print_graph(&g, "GRAPH\n");
    printf("BFS ==> ");
    BFS_list(&g, 0);
    printf("\n");
}