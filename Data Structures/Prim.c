#include <stdio.h>
#include <stdlib.h>

#define MAX_VTXS 100
#define INF 9999

void error(char str[]) {
	printf("%s\n", str);
	exit(1);
}

//////////////// 그래프 구현 /////////////////////////

typedef char VtxData;
typedef struct {
    int adj_mat[MAX_VTXS][MAX_VTXS];
    int vsize;
} GraphType;

VtxData vdata[MAX_VTXS];

int is_empty_graph(GraphType *g) { return (g->vsize == 0); }
int is_full_graph(GraphType *g) { return (g->vsize >= MAX_VTXS); }
void init_graph(GraphType *g) {
	int i, j;
	g->vsize = 0;
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

void insert_edge(GraphType *g, int u, int v, int val) {
	g->adj_mat[u][v] = val;
}

void insert_edge2(GraphType *g, int u, int v, int val) {
	g->adj_mat[u][v] = g->adj_mat[v][u] = val;
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
				if (i != j && val == 0)
					g->adj_mat[i][j] = INF;
				else g->adj_mat[i][j] = val;
			}
		}
		fclose(fp);
	}
}

void print_wgraph(GraphType *g, char* msg) {
	int i, j, val;

	printf("%s%d\n", msg, g->vsize);
	for (i = 0; i < g->vsize; i++) {
		printf("%c  ", vdata[i]);
		for (j = 0; j < g->vsize; j++) {
			val = g->adj_mat[i][j];
			if (i == j) printf("  0 ");
			else if (val >= INF) printf("  - ");
			else printf("%3d ", val);
		}
		printf("\n");
	}
}

//////////////// 정점 집합 처리  /////////////////////////
int selected[MAX_VTXS];
int dist[MAX_VTXS];

int getMinVertex(GraphType *g) {
	int v, minv = 0, mindist = INF;

	for (v = 0; v < g->vsize; v++) {
		if (!selected[v] && dist[v] < mindist) {
			mindist = dist[v];
			minv = v;
		}
    }
	return minv;
}

// Prim의 최소 비용 신장 트리 프로그램
void Prim(GraphType *g) {
	int i, u, v;

	for (i = 0; i < g->vsize; i++) {
		dist[i] = INF;
		selected[i] = 0;
	}
	dist[0] = 0;

	for (i = 0; i < g->vsize; i++) {
		u = getMinVertex(g);
		selected[u] = 1;
		if (dist[u] == INF) return;
		printf("%c ", vdata[u]);

		for (v = 0; v < g->vsize; v++) {
			if (g->adj_mat[u][v] != INF) {
				if (!selected[v] && g->adj_mat[u][v]< dist[v]) {
					dist[v] = g->adj_mat[u][v];
                }
            }
        }
	}
	printf("\n");
}

void main() {
    GraphType g;

	load_wgraph(&g, "graph_final1.txt");
	printf("MST By Prim's Algorithm\n");
	Prim(&g);
}

/*
#include <stdio.h>
 
#define TRUE 1
#define FALSE 0
 
#define VERTICES 7
#define INF 1000L
 
int adj_mat[VERTICES][VERTICES] = {
    { 0, 29, INF, INF, INF, 10, INF },
    { 29,  0, 16, INF, INF, INF, 15 },
    { INF, 16, 0, 12, INF, INF, INF },
    { INF, INF, 12, 0, 22, INF, 18 },
    { INF, INF, INF, 22, 0, 27, 25 },
    { 10, INF, INF, INF, 27, 0, INF },
    { INF, 15, INF, 18, 25, INF, 0 } };
 
int selected[VERTICES];
int dist[VERTICES];
 
// 최소 dist[v] 값을 갖는 정점을 반환
int get_min_vertex(int n) {
    int v, i;
    for (i = 0; i <n; i++)
        if (!selected[i]) {
            v = i;
            break;
        }
    for (i = 0; i < n; i++) {
        if (!selected[i] && (dist[i] < dist[v])) v = i;
    }
    return (v);
}
 
void prim(int s, int n) {
    int i, u, v;
 
    for (u = 0; u<n; u++) {
        dist[u] = INF;
    }
    dist[s] = 0;
    for (i = 0; i<n; i++) {
        u = get_min_vertex(n);
        selected[u] = TRUE;
        if (dist[u] == INF) return;
        printf("%d ", u);
        for (v = 0; v<n; v++) {
            if (adj_mat[u][v] != INF) {
                if (!selected[v] && adj_mat[u][v]< dist[v]) {
                    dist[v] = adj_mat[u][v];
                }
            }
        }
    }
}
 
void main() {
    prim(0, VERTICES);
}
*/