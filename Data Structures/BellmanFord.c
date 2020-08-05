/* 
 * Bellman Ford Program (with Adjacent Matrix)
 * Author : starrykss
 * Language : C
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VTXS 100
#define INF 9999
#define LIMITS 9000

void error(char str[]) {
    printf("%s\n", str);
    exit(1);
}

typedef char VtxData;
typedef struct {
    int adj_mat[MAX_VTXS][MAX_VTXS];
    int vsize;
    int esize;
} GraphType;

typedef struct {
    int src;
    int dest;
    int weight;
} EdgeType;

VtxData vdata[MAX_VTXS];
EdgeType edge[MAX_VTXS];
int idx = 0;

int is_empty_graph(GraphType *g) { return (g->vsize == 0); }
int is_full_graph(GraphType *g) { return (g->vsize >= MAX_VTXS); }
void init_graph(GraphType *g) {
	int i, j;
	g->vsize = 0;
    g->esize = 0;
	for (i = 0; i < MAX_VTXS; i++) {
		for (j = 0; j < MAX_VTXS; j++) {
			g->adj_mat[i][j] = 0;
        }
    }
}

void insert_vertex(GraphType *g, VtxData name) {
	if (is_full_graph(g))
		error("Error: 그래프 정점의 개수 초과\n");
	else
		vdata[g->vsize++] = name;
}

void setting_edge(GraphType *g) {
    for (int i = 0; i < g->vsize; i++) {
        for (int j = 0; j < g->vsize; j++) {
            edge[idx].src = i;
            edge[idx].dest = j;
            edge[idx].weight = g->adj_mat[i][j];
            if (g->adj_mat[i][j] != 0 && g->adj_mat[i][j] != INF) {
                g->esize++;
            }
        idx++;
        }
    }
    g->esize;
}

void print_graph(GraphType *g, char* msg) {
	int i, j;
	printf("%s", msg);
	printf("%d\n", g->vsize);
	for (i = 0; i < g->vsize; i++) {
		printf("%c  ", vdata[i]);
		for (j = 0; j < g->vsize; j++)
			printf(" %3d", g->adj_mat[i][j]);
		printf("\n");
	}
}

void load_wgraph(GraphType *g, char *filename) {
    int i, j, val, n;
    char str[80];
    FILE *fp = fopen(filename, "r");
    if (fp != NULL) {
        init_graph(g);
        fscanf(fp, "%d", &n);
        for (i = 0; i < n; i++) {
            fscanf(fp, "%s", str);
            insert_vertex(g, str[0]);
            for (j = 0; j < n; j++) {
                fscanf(fp, "%d", &val);
                if (i != j && val == 0) g->adj_mat[i][j] = INF;
                else g->adj_mat[i][j] = val;
            }
        }
        fclose(fp);
    }
    setting_edge(g);
}

void print_wgraph(GraphType *g, char *msg) {
    int i, j, val;

    printf("%s%d\n", msg, g->vsize);
    for (i = 0; i < g->vsize; i++) {
        printf("%c ", vdata[i]);
        for (j = 0; j < g->vsize; j++) {
            val = g->adj_mat[i][j];
            if (i == j) printf("  0 ");
            else if (val >= INF) printf("  - ");
            else printf("%3d ", val);
        }
        printf("\n");
    }
}

// 결과를 출력하기 위한 함수
void printArr(int **dist, int n, int src) {
    int num = 0;

    for (int i = 1; i < n; i++) {
        printf("(distance :%2d) =>", ++num);
        for (int j = 0; j < n; j++) {
            if (dist[i][j] > LIMITS) {
                printf("%3s ", "INF");
            }
            else {
                printf("%3d ", dist[i][j]);
            }
        }
        printf("\n");
    }

    // 최단 경로 출력
    printf("# Shortest Path(start : %c)\n", vdata[src]);
    for (int i = 0; i < n; i++) {
        printf("%c - %c : ", vdata[src], vdata[i]);
        if (dist[n - 1][i] > LIMITS) printf("INF\n");
        else printf("%d\n",  dist[n - 1][i]);
    }
}

void BellmanFord(GraphType *g, int src) {
    int V = g->vsize;
    int E = g->esize;

    // 2차원 dist 배열 동적 할당
    int **dist = (int**)malloc(sizeof(int*) * V);
    for (int i = 0; i < V; i++) {
        dist[i] = (int*)malloc(sizeof(int*) * V);
    }

    // 모든 최단 거리를 무한대로 지정
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = INF;
        }
    }
    // 시작점(src)만 0으로 초기화
    for (int i = 0; i < V; i++) {
        dist[i][src] = 0;
    }

    // 벨만 포드 알고리즘
    for (int i = 1; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = dist[i - 1][j];
            for (int k = 0; k < V; k++) {
                if (dist[i][j] > dist[i - 1][k] + g->adj_mat[k][j]) {
                    dist[i][j] = dist[i - 1][k] + g->adj_mat[k][j];
                }
            }

        }
    }
    printArr(dist, V, src);

    return;
}

void main() {
    GraphType g;

    load_wgraph(&g, "wgraph_negative.txt");
    print_wgraph(&g, "GRAPH\n");
    printf("Bellman Ford's Shortest Path Algorithm\n");
    BellmanFord(&g, 0);
}