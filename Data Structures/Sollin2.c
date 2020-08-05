/* 
 * Boruvka(Sollin) MST Program (With Union-Find Algorithm)
 * Author : starrykss
 * Language : C
 * Reference :https://www.geeksforgeeks.org/boruvkas-algorithm-greedy-algo-9
 */

#include <stdio.h>
#include <stdlib.h>

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
            if (g->adj_mat[i][j] != 0 && g->adj_mat[i][j] != INF) {
                edge[idx].src = i;
                edge[idx].dest = j;
                edge[idx].weight = g->adj_mat[i][j];
                g->esize++;
            }
            else {
                edge[idx].src = i;
                edge[idx].dest = j;
                edge[idx].weight = g->adj_mat[i][j];
            }
        idx++;
        }
    }
    g->esize /= 2;
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
            if (i == j) printf(" 0 ");
            else if (val >= INF) printf(" - ");
            else printf("%3d ", val);
        }
        printf("\n");
    }
}

typedef struct {
    int parent[MAX_VTXS]; // Parent node's index of each node
    int set_size;         // The number of total Subsets
} SubsetType;

void init_Set(SubsetType *subset, int nSets) {
    int i;
    subset->set_size = nSets;
    for (i = 0; i < nSets; i++) {
        subset->parent[i] = -1;
    }
}

int Find(SubsetType *subset, int id) {
    while (subset->parent[id] >= 0) id = subset->parent[id];
    return id;
}

void Union(SubsetType *subset, int x, int y) {
    subset->parent[x] = y;
    subset->set_size--;
}

void boruvkaMST(GraphType *g) {
    SubsetType subset;

    // Get data of given graph
    int V = g->vsize;
    int E = g->esize;

    // An Array to store index of the cheapest edge of subset
    int *cheapest = (int*)malloc(sizeof(int) * V);

    init_Set(&subset, g->vsize);

    // Initialize cheapest array with -1
    for (int v = 0; v < V; ++v) {
        cheapest[v] = -1;
    }
    
    // Initially there are V different trees. 
    // Finally there will be one tree that will be MST 
    int numTrees = V;
    int MSTweight = 0;

    // Keep combining components (or sets) until all 
    // compnentes are not combined into single MST
    while (numTrees > 1) {
        // Everytime initialize cheapest array
        for (int v = 0; v < V; ++v) {
            cheapest[v] = -1;
        }

        // Traverse through all edges and 
        // update cheapest of every component
        for (int i = 0; i < idx; i++) {
            // Find components (or sets) of two corners
            // of current edge
            int set1 = Find(&subset, edge[i].src);
            int set2 = Find(&subset, edge[i].dest);

            // If two corners of current edge belong to
            // same set, ignore current edge
            if (set1 == set2) {
                continue;
            }

            // Else check if current edge is closer to previous
            // cheapest edges of set1 and set2
            else {
                if (cheapest[set1] == -1 || 
                    edge[cheapest[set1]].weight > edge[i].weight) {
                    cheapest[set1] = i;
                }
                if (cheapest[set2] == -1 || 
                    edge[cheapest[set2]].weight > edge[i].weight) {
                    cheapest[set2] = i;
                }
            }
        }
        // Consider the above picked cheapest edges and add them to MST
        for (int i = 0; i < V; i++) {
            // Check if chepaest for current set exists
            if (cheapest[i] != -1) {
                int set1 = Find(&subset, edge[cheapest[i]].src);
                int set2 = Find(&subset, edge[cheapest[i]].dest);

                if (set1 == set2) {
                    continue;
                }
                MSTweight += edge[cheapest[i]].weight;
                printf("Edge %c - %c (Cost: %2d) included in MST\n", 
                        vdata[edge[cheapest[i]].src], vdata[edge[cheapest[i]].dest],
                        g->adj_mat[edge[cheapest[i]].src][edge[cheapest[i]].dest]);

                // Do a union of set1 and set2 and decrease number of trees
                Union(&subset, set1, set2);
                numTrees--;
            }
        }
    }    
    printf("Weight of MST is %d\n", MSTweight);
    return;
}

void main() {
    GraphType g;

    load_wgraph(&g, "wgraph.txt");
    print_wgraph(&g, "GRAPH\n");
    printf("MST By Bouruvka's Algorithm\n");
    boruvkaMST(&g);

}