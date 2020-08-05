// Floyd 알고리즘 구현

#include <stdio.h>
#include <stdlib.h>

#define MAX_VTXS 256
#define INF 9999

typedef char VtxData;
typedef struct {
    int adj_mat[MAX_VTXS][MAX_VTXS];
    int vsize;
} GraphType;

VtxData vdata[MAX_VTXS];

static int A[MAX_VTXS][MAX_VTXS]; // 최단 경로 거리

void error(char str[]) {
	printf("%s\n", str);
	exit(1);
}

int is_empty_graph(GraphType *g) { return (g->vsize == 0); }
int is_full_graph(GraphType *g) { return (g->vsize >= MAX_VTXS); }
void init_graph(GraphType *g) {
	int i, j;
	g->vsize = 0;
	for (i = 0; i < MAX_VTXS; i++)
		for (j = 0; j < MAX_VTXS; j++)
			g->adj_mat[i][j] = 0;
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

static void printA(GraphType *g) {
    printf("=====================================\n");
    for (int i = 0; i < g->vsize; i++) {
        for (int j = 0; j < g->vsize; j++) {
            if (A[i][j] == 9999) {
                printf("%5s", "INF");
            }
            else {
                printf("%5d", A[i][j]);
            }
        }
        printf("\n");
    }
}

void shortest_path_floyd(GraphType *g) {
    int i, j, k;
    for (i = 0; i < g->vsize; i++) {
        for (j = 0; j < g->vsize; j++) {
            A[i][j] = g->adj_mat[i][j];
        }
    }
    for (k = 0; k < g->vsize; k++) {
        for (i = 0; i < g->vsize; i++) {
            for (j = 0; j < g->vsize; j++) {
                if (A[i][k] + A[k][j] < A[i][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                }
            }
            printA(g);  // 진행 상황 출력
        }
    }
}

void main() {
    GraphType g;

    load_wgraph(&g, "wgraph_sp.txt");
    print_wgraph(&g, "최단거리(wgraph_sp.txt)\n");
    printf("Shortest Path By Floyd Algorithm\n");
    shortest_path_floyd(&g);
}