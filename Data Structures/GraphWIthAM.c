// 인접 행렬을 이용한 그래프 표현 프로그램
#include <stdio.h>
#include <stdlib.h>

#define MAX_VTXS 100

typedef char VtxData;   // 그래프 정점에 저장할 데이터의 자료형

typedef struct {
    int vsize;                       // 전체 정점의 개수
    int adj_mat[MAX_VTXS][MAX_VTXS]; // 인접 행렬
} GraphType;

VtxData vdata[MAX_VTXS];  // 정점에 저장할 데이터 배열

int is_empty_graph(GraphType *g) { return (g->vsize == 0); }
int is_full_graph(GraphType *g) { return (g->vsize >= MAX_VTXS); }

void error(char str[]) {
    printf("%s\n", str);
    exit(1);
}

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

// 방향 그래프에서의 삽입
void insert_edge(GraphType *g, int u, int v, int val) {
    g->adj_mat[u][v] = val;
}

// 무방향 그래프에서의 삽입
void insert_edge2(GraphType *g, int u, int v, int val) {
    g->adj_mat[u][v] = g->adj_mat[v][u] = val;
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

void main() {
    GraphType g;
    int i;

    init_graph(&g);
    for (i = 0; i < 4; i++) {
        insert_vertex(&g, 'A' + i);
    }
    insert_edge2(&g, 0, 1, 1);
    insert_edge2(&g, 0, 3, 1);
    insert_edge2(&g, 1, 2, 1);
    insert_edge2(&g, 1, 3, 1);
    insert_edge2(&g, 2, 3, 1);
    print_graph(&g, "그래프(인접행렬)\n");
}