// 인접 리스트를 이용한 그래프 표현 프로그램

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

void error(char str[]) {
    printf("%s\n", str);
    exit(1);
}

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
        for (v = g->adj_list[i]; v != NULL; v = v->link)
            printf("   %c", vdata[v->id]);
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
    insert_edge(&g, 0, 1);
    insert_edge(&g, 0, 3);
    insert_edge(&g, 1, 2);
    insert_edge(&g, 1, 3);
    insert_edge(&g, 2, 3);

    print_graph(&g, "그래프(인접 리스트)\n");
}