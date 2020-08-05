// BFS 구현 (인접 행렬 이용)
// 인접행렬로 표현된 그래프의 정보는 "graph.txt" 파일 안에 입력되어 있음.
#include <stdio.h>
#include <stdlib.h>

#define MAX_VTXS 256

typedef char VtxData; 
typedef struct {
    int adj_mat[MAX_VTXS][MAX_VTXS]; 
    int vsize;  // 정점의 개수
} GraphType;

VtxData vdata[MAX_VTXS];  // 정점에 저장할 데이터 배열
int visited[MAX_VTXS];

int is_empty_graph(GraphType *g) { return (g->vsize == 0); }
int is_full_graph(GraphType *g) { return (g->vsize >= MAX_VTXS); }

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

void init_graph(GraphType *g) {
    int i, j;
    g->vsize = 0;
    for (i = 0; i < MAX_VTXS; i++) {
        for (j = 0; j < MAX_VTXS; j++) {
            g->adj_mat[i][j] = 0;
        }
    }
}

void insert_vertex(GraphType *g, char name) {
    if (is_full_graph(g)) {
        error("Error: 정점 개수 초과\n");
    }
    else {
        vdata[g->vsize++] = name;
    }
}

void insert_edge(GraphType *g, int u, int v) {
    g->adj_mat[u][v] = g->adj_mat[v][u] = 1;
}

void print_graph(GraphType *g, char* msg) {
    int i, j;
    printf("%s", msg);
    printf("%d\n", g->vsize);
    for (i = 0; i < g->vsize; i++) {
        printf("%c  ", vdata[i]);
        for (j = 0; j < g->vsize; j++) {
            printf(" %3d", g->adj_mat[i][j]);
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
        for(i = 0; i < n; i++) {
            fscanf(fp, "%s", str);
            insert_vertex(g, str[0]);
            for (j = 0; j < n; j++) {
                fscanf(fp, "%d", &val);
                if (val != 0) {
                    insert_edge(g, i, j);
                }
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

void BFS_mat(GraphType *g, int v) {
	int w;
	QueueType q;
    
	init_queue(&q);     // 큐 초기화 
	visited[v] = 1;          // 정점 v 방문 표시 
	printf("%c ", vdata[v]);
	enqueue(&q, v);			// 시작 정점을 큐에 저장 
	while (!is_empty(&q)) {
		v = dequeue(&q);		// 큐에 정점 추출 
		for (w = 0; w < g->vsize; w++)	// 인접 정점 탐색 
			if (g->adj_mat[v][w] && !visited[w]) {
				visited[w] = 1;    // 방문 표시
				printf("%c ", vdata[w]);
				enqueue(&q, w); 	// 방문한 정점을 큐에 저장
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
    BFS_mat(&g, 0);
    printf("\n");
}