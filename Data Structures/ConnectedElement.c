// 연결 성분 프로그램

#include <stdio.h>
#include <stdlib.h>

#define MAX_VTXS 256

typedef char VtxData; 
typedef struct {
    int adj_mat[MAX_VTXS][MAX_VTXS]; 
    int vsize;
} GraphType;

VtxData vdata[MAX_VTXS];  // 정점에 저장할 데이터 배열
int visited[MAX_VTXS];
int label[MAX_VTXS];

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

void labelDFS(GraphType *g, int v, int color) {
    int w;
    visited[v] = 1;
    label[v] = color;
    printf("%c ", vdata[v]);
    for (w = 0; w < g->vsize; w++)
        if (g->adj_mat[v][w] != 0 && visited[w] == 0)
            labelDFS(g, w, color);
}

void findConnectedComponent(GraphType *g) {
    int i, count = 0;
    
    for (i = 0; i < g->vsize; i++) {
        visited[i] = 0;
    }
    for (i = 0; i < g->vsize; i++) {
        if (visited[i] == 0) {
            labelDFS(g, i, ++count);
        }
    }
    printf("\n연결성분 개수 = %d\n", count);
    for (i = 0; i < g->vsize; i++) {
        printf("%c=%d ", vdata[i], label[i]);
    }
}

void main() {
    GraphType g;

    load_graph(&g, "graph2.txt");     
    reset_visited(&g);
    print_graph(&g, "그래프(연결 성분 테스트)\n");
    findConnectedComponent(&g);
    printf("\n");
}