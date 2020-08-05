#include <stdio.h>
#include <stdlib.h>

// Numer of vertices in the graph
#define TRUE 1
#define FALSE 0
#define MAX_VTXS 100
#define INF 9999

void error(char str[]) {
	printf("%s\n", str);
	exit(1);
}

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

// ===========================================================

int mstSet[MAX_VTXS];

int minKey(int key[], int mstSet[], int V) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == FALSE && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

int printMST(int parent[], int n, GraphType *g) {
    printf("Edge  Weight\n");
    for (int i = 1; i < n; i++) {
        printf("%c - %c    %d\n", vdata[parent[i]], vdata[i], g->adj_mat[i][parent[i]]);
    }
}

void BouruvkaMST(GraphType *g, int V) {
    int parent[V];
    int key[V];
    int mstSet[V];  // to represent set of vertices not yet included in MST

    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = FALSE;
    }

    // Always include first vertex in MST
    key[0] = 0;   // Make key 0 so that this vertext is picked as first vertex
    parent[0] = -1;   // First node is always root of MST 

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = TRUE;
        for (int v = 0; v < V; v++) {
            if (g->adj_mat[u][v] && mstSet[v] == FALSE && g->adj_mat[u][v] < key[v]) {
                parent[v] = u;
                key[v] = g->adj_mat[u][v];
            }
        }
    }
    printMST(parent, V, g);
}

void main() {
    GraphType g;

    load_wgraph(&g, "wgraph.txt");
	print_wgraph(&g, "GRAPH\n");
    printf("MST By Bouruvka's Algorithm\n");
    BouruvkaMST(&g, g.vsize);
}