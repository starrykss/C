// Kruskal의 최소 비용 신장 트리 프로그램

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


///////////// Union-Find 구현 /////////////////////////////////
 
int	parent[MAX_VTXS];		// 각 노드의 부모노드 인덱스	
int	set_size;				// 전체 집합의 개수	

void init_set(int nSets) {
	int i;
	set_size = nSets;
	for (i = 0; i<nSets; i++)
		parent[i] = -1;			// 맨 처음에는 모든 정점이 각각 고유의 집합	
}
int find_set(int id) {
	while (parent[id] >= 0) id = parent[id];
	return id;
}
void union_set(int s1, int s2) {
	parent[s1] = s2;
	set_size--;
}

////////////////////// 최소힙 구현 //////////////////////////

#define MAX_ELEMENT 100

typedef struct {
    int key;    // 간선의 가중치
    int u;        // 정점 1
    int v;        // 정점 2
} element;
 
typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

void init_heap(HeapType *h) { h->heap_size = 0; }
int is_empty_heap(HeapType *h) { return h->heap_size == 0; }
int is_full_heap(HeapType *h) { return (h->heap_size == MAX_ELEMENT - 1); }
element find_heap(HeapType *h) { return h->heap[1]; }

void insert_min_heap(HeapType *h, element item) {
    int i;

    if (is_full_heap(h)) return;
    i = ++(h->heap_size);
    while ((i != 1) && (item.key < h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
}

element delete_min_heap(HeapType *h) {
    int parent, child;
    element item, temp;
 
    if (is_empty_heap(h)) error("힙 트리 공백 에러");

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size) {
        if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key) {
            child++;
        }
        if (temp.key <= h->heap[child].key) break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}
 
// kruskal의 최소 비용 신장 트리 프로그램
void kruskal(GraphType *g, int n) {
    int i, j, edgeAccepted = 0, uset, vset;
	element e;
    HeapType h;

	init_heap(&h);
	init_set(g->vsize);

	for (i = 0; i < g->vsize - 1; i++) {
		for (j = i + 1; j < g->vsize; j++) {
			if (g->adj_mat[i][j] < INF) {
				e.key = g->adj_mat[i][j];		// 힙 노드를 만들어 힙에 삽입 
				e.u = i;
				e.v = j;
				insert_min_heap(&h, e);
			}
        }
    }
	while (edgeAccepted < g->vsize - 1) {
		e = delete_min_heap(&h);
		uset = find_set(e.u);
		vset = find_set(e.v);

		if (uset != vset) {
			printf("간선 추가 : %c - %c (비용:%d)\n", vdata[e.u], vdata[e.v], e.key);
			union_set(uset, vset);
			edgeAccepted++;
		}
	}
}
 
void main() {
    GraphType g;

    load_wgraph(&g, "wgraph.txt");
    printf("MST By Kruskal's Algorithm\n");
    kruskal(&g, 7);
}

/*
#include <stdio.h>
#define MAX_VERTICES 100
#define INF 1000
 
int parent[MAX_VERTICES];    // 부모 노드
int num[MAX_VERTICES];        // 각 집합의 크기
                            // 초기화
void set_init(int n) {
    int i;
    for (i = 0; i<n; i++) {
        parent[i] = -1;
        num[i] = 1;
    }
}
 
// vertex가 속하는 집합을 반환한다.
int set_find(int vertex) {
    int p, s, i = -1;
    for (i = vertex; (p = parent[i]) >= 0; i = p);    // 루트 노드까지 반복
    s = i;            // 집합의 대표 원소
    for (i = vertex; (p = parent[i]) >= 0; i = p) {
        parent[i] = s;    // 집합의 모든 원소들의 부모를 p로 설정
    }
    return s;
}
 
// 두개의 원소가 속한 집합을 합친다.
void set_union(int s1, int s2) {
    if (num[s1] < num[s2]) {
        parent[s1] = s2;
        num[s2] += num[s1];
    }
    else {
        parent[s2] = s1;
        num[s1] += num[s2];
    }
}
 
typedef struct {
    int key;    // 간선의 가중치
    int u;        // 정점 1
    int v;        // 정점 2
} element;
 
#define MAX_ELEMENT 100
typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;
 
// 초기화 함수
void init(HeapType *h) {
    h->heap_size = 0;
}
 
// 히프 내용 출력 함수
void print_heap(HeapType *h) {
    int i;
    int level = 1;
    printf("\n===================");
    for (i = 1; i <= h->heap_size; i++) {
        if (i == level) {
            printf("\n");
            level *= 2;
        }
        printf("\t%d", h->heap[i].key);
    }
    printf("\n===================");
}
 
// 삽입 함수
void insert_min_heap(HeapType *h, element item) {
    int i;
    i = ++(h->heap_size);
 
    //  트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
    while ((i != 1) && (item.key < h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;     // 새로운 노드를 삽입
}
 
// 삭제 함수
element delete_min_heap(HeapType *h) {
    int parent, child;
    element item, temp;
 
    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size) {
        // 현재 노드의 자식노드중 더 작은 자식노드를 찾는다.
        if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key) {
            child++;
        }
        if (temp.key <= h->heap[child].key) break;
        // 한단계 아래로 이동
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}
 
// 정점 u와 정점 v를 연결하는 가중치가 weight인 간선을 히프에 삽입
void insert_heap_edge(HeapType *h, int u, int v, int weight) {
    element e;
    e.u = u;
    e.v = v;
    e.key = weight;
    insert_min_heap(h, e);
}
 
// 인접 행렬이나 인접 리스트에서 간선들을 읽어서 최소 히프에 삽입 
// 현재는 예제 그래프의 간선들을 삽입한다.
void insert_all_edges(HeapType *h) {
    insert_heap_edge(h, 0, 1, 29);
    insert_heap_edge(h, 1, 2, 16);
    insert_heap_edge(h, 2, 3, 12);
    insert_heap_edge(h, 3, 4, 22);
    insert_heap_edge(h, 4, 5, 27);
    insert_heap_edge(h, 5, 0, 10);
    insert_heap_edge(h, 6, 1, 15);
    insert_heap_edge(h, 6, 3, 18);
    insert_heap_edge(h, 6, 4, 25);
}
 
// kruskal의 최소 비용 신장 트리 프로그램
void kruskal(int n) {
    int edge_accepted = 0;    // 현재까지 선택된 간선의 수    
    HeapType h;                // 최소 히프
    int uset, vset;            // 정점 u와 정점 v의 집합 번호
    element e;                // 히프 요소
 
    init(&h);                    // 히프 초기화
    insert_all_edges(&h);        // 히프에 간선들을 삽입
    set_init(n);                // 집합 초기화
    while (edge_accepted < (n - 1)) {    // 간선의 수 < (n-1)
        e = delete_min_heap(&h);    //    최소 히프에서 삭제
        uset = set_find(e.u);        // 정점 u의 집합 번호 
        vset = set_find(e.v);        // 정점 v의 집합 번호
        if (uset != vset) {            // 서로 속한 집합이 다르면
            printf("(%d,%d) %d \n", e.u, e.v, e.key);
            edge_accepted++;
            set_union(uset, vset);    // 두개의 집합을 합친다.
        }
    }
}
 
void main() {
    kruskal(7);
}
*/

/*
#include <stdio.h> 

#define MAX_VERTEX 100 
#define MAX_ELEMENT 100 

int parent[MAX_VERTEX]; 
int num[MAX_VERTEX]; 

typedef struct { 
    int v; // 정점1 
    int u; // 정점2 
    int key; // 간선의 가중치 
} Element; 

typedef struct { 
    Element heap[MAX_ELEMENT]; 
    int heap_size; 
}HeapType; 

void InitHeap(HeapType *h) { 
    h->heap_size=0; 
} 
void InsertHeap(HeapType *h,Element item) { 
    int i; 
    i=++(h->heap_size); 

    // 부모노드와 비교 
    while(i != 1 && item.key < h->heap[i/2].key) { 
        h->heap[i]=h->heap[i/2]; 
        i/=2; 
    } 

    h->heap[i]=item; 
} 

Element DeleteHeap(HeapType *h) { 
    int parent=1,child=2; 
    Element data,temp; 

    data = h->heap[parent]; 
    temp = h->heap[(h->heap_size)--]; // 삭제에 의한 size 감소 

    while(child <= h->heap_size) { 
         //자식 노드간 작은 수 비교  
        if((child < h->heap_size) && (h->heap[child].key) > h->heap[child+1].key)  
            child++; 
         
        if(temp.key <= h->heap[child].key) break; 

        h->heap[parent] = h->heap[child]; 
        parent = child; 
        child *= 2; // 다음 자식 노드와 비교 
    } 

    h->heap[parent]=temp; 
    return data; 
} 

// 전역 변수 초기화 
void InitUF(void) { 
    int i; 
    for(i=0;i<MAX_VERTEX;i++) { 
        parent[i]=-1; 
        num[i]=1; 
    } 
} 
// v가 속하는 집합을 반환한다 
int SetFind(int v) {

    int i,p,temp; 

    for(i=v;(p=parent[i])>=0;i=p); // 정점v의 루트를 찾는다 
     
    temp=i; // 정점 v를 포함하는 집합의 대표 원소  
      
    for(i=v;(p=parent[i])>=0;i=p)  
        parent[i]=temp; // 집합의 모든 원소들의 부모를 s로 설정 

    return temp; 
} 

// 두개의 원소가 속한 집합을 합친다 
void SetUnion(int v1,int v2) { 
    if(num[v1] < num[v2]) // 자식의 갯수로 비교 
    { 
        parent[v1]=v2; // 부모 변경 
        num[v1]+=num[v2]; 
    } 
    else 
    { 
        parent[v2]=v1; // 부모 변경 
        num[v2]+=num[v1]; 
    } 
} 

void InsertHeapEdge(HeapType *h,int v,int u,int weight) { 
    Element node; 
    node.v=v; 
    node.u=u; 
    node.key=weight; 

    InsertHeap(h,node); 
} 

int kruskal(int n) { 
    Element e; 
    HeapType h; 
    int uSet,vSet,edgeCount=0,sum=0; 

    InitHeap(&h); 
    InitUF(); 

    InsertHeapEdge(&h,0,1,29); 
    InsertHeapEdge(&h,1,2,15); 
    InsertHeapEdge(&h,2,3,12); 
    InsertHeapEdge(&h,3,4,22); 
    InsertHeapEdge(&h,4,5,27); 
    InsertHeapEdge(&h,5,0,10); 
    InsertHeapEdge(&h,6,1,16); 
    InsertHeapEdge(&h,6,3,18); 
    InsertHeapEdge(&h,6,4,25); 

     // 간선의 갯수가 n-1이 될 때 까지 
    while(edgeCount < n-1) {
    
        e=DeleteHeap(&h); // 최소 힙 
         
        // 가장 가중치가 가장 낮은 간선을 선택 
        uSet=SetFind(e.u);  
        vSet=SetFind(e.v); 

        if(uSet != vSet) // 서로의 대표 원소가 같지 않은 경우에만 
        { 
            printf("(%d,%d) %d\n",e.u,e.v,e.key); 
            sum+=e.key; 
            edgeCount++; // 간선을 하나 늘린다 
            SetUnion(uSet,vSet); // 두 집합을 합친다 
        } 
    } 

    printf("최소 비용의 간선 길이 %d \n\n",sum); 

for (int m=0;m<n;m++) 
        printf("자식 [%d] : 부모 %d\n",m,parent[m]); 

    return 0; 
} 

int main() { 
    kruskal(7); // 현재 간선의 갯수는 7개로 만들어놓았다. 
}
*/