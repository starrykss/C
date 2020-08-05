// 다익스트라 알고리즘 구현

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

int path[MAX_VTXS];
int dist[MAX_VTXS];
int found[MAX_VTXS];

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

void print_shortest_path(int start, int end) {
    printf("[최단경로: %c---%c] %c", vdata[end], vdata[start], vdata[end]);
    while (path[end] != start) {
        printf("-%c", vdata[path[end]]);
        end = path[end];
    }
    printf("-%c\n", vdata[path[end]]);
}

void printDistance(GraphType *g) {
    for (int i = 0; i < g->vsize; i++) {
        if (dist[i] == 9999) {
            printf("%5s", "INF");
        }
        else {
            printf("%5d", dist[i]);
        }
    }
    printf("\n");
}

int choose_vertex(GraphType *g) {
    int i, min = INF, minpos = -1;
    for (i = 0; i < g->vsize; i++) {
        if (dist[i] < min && !found[i]) {
            min = dist[i];
            minpos = i;
        }
    }
    return minpos;
}

void shortest_path_dijkstra(GraphType *g, int start) {
    int i, u, w;

    for (i = 0; i < g->vsize; i++) {
        dist[i] = g->adj_mat[start][i];
        path[i] = start;
        found[i] = 0;
    }

    found[start] = 1;
    dist[start] = 0;

    for (i = 0; i < g->vsize; i++) {
        // dist 상태 출력
        printf(" Step %d:", i + 1);
        printDistance(g);
        
        u = choose_vertex(g);
        found[u] = 1;
        for (w = 0; w < g->vsize; w++) {
            if (found[w] == 0) {
                if (dist[u] + g->adj_mat[u][w] < dist[w]) {
                    dist[w] = dist[u] + g->adj_mat[u][w];
                    path[w] = u;
                }
            }
        }
    }
}

void main() {
    GraphType g;
    int i;

    load_wgraph(&g, "wgraph_exam.txt");
    print_wgraph(&g, "최단거리(wgraph_sp.txt)\n");
    printf("Shortest Path By Dijkstra Algorithm\n");
    shortest_path_dijkstra(&g, 0);

    // 진행 상황 출력 
    for (i = 1; i < g.vsize; i++) {
        print_shortest_path(0, i);
    }
}