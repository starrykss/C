#include <stdio.h>
#include <stdlib.h> // malloc
#include <limits.h> // INT_MAX
#include <string.h> // strtok()
 
#define MAX_BRICK_SIZE 100
#define MAX_STACK_SIZE 100
#define MAX_VERTICES 100

typedef struct {
    int src;
    int dst;
    int weight; 
} EdgeType;
 
typedef struct {
    int V;
    int E;
    EdgeType* edge;
} GraphType;

typedef struct {
    int width;
    int height;
    int weight;
    int number;
} BrickType;

///////////////////////////////////////////////////////////////////////

typedef struct GraphNode
{
    int vertex;
    struct GraphNode *link;
} GraphNode;

typedef struct GraphType {
    int n;    // 정점의 개수
    GraphNode *adj_list[MAX_VERTICES];
} GraphNodeType;
 
typedef int element;
typedef struct {
    element stack[MAX_STACK_SIZE];
    int top;
} StackType;
 

// 스택 초기화 함수
void init(StackType *s) {
    s->top = -1;
}
 
// 공백 상태 검출 함수
int is_empty(StackType *s) {
    return (s->top == -1);
}
 
// 포화 상태 검출 함수
int is_full(StackType *s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}
 
// 삽입함수
void push(StackType *s, element item) {
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else s->stack[++(s->top)] = item;
}
 
// 삭제함수
element pop(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->stack[(s->top)--];
}
 
// 피크함수
element peek(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->stack[s->top];
}
 
// 위상정렬
int topo_sort(GraphNodeType *g) {
    int i;
    StackType s;
    GraphNode *node;
 
    // 모든 정점의 진입 차수를 계산
    int *in_degree = (int *)malloc(g->n * sizeof(int));
    for (i = 0; i < g->n; i++) {        // 초기화
        in_degree[i] = 0;
    }
    for (i = 0; i < g->n; i++) {
        GraphNode *node = g->adj_list[i];//정점 i에서 나오는 간선들
        while (node != NULL) {
            in_degree[node->vertex]++;
            node = node->link;
        }
    }
    // 진입 차수가 0인 정점을 스택에 삽입
    init(&s);
    for (i = 0; i < g->n; i++) {
        if (in_degree[i] == 0) push(&s, i);
    }
    // 위상 순서를 생성 
    while (!is_empty(&s)) {
        int w;
        w = pop(&s);
        printf("%d ", w);        //정점 출력
        node = g->adj_list[w];    //각 정점의 진입 차수를 변경
        while (node != NULL) {
            int u = node->vertex;
            in_degree[u]--;            //진입 차수를 감소
            if (in_degree[u] == 0) push(&s, u);
            node = node->link;   // 다음 정점
        }
    }
    free(in_degree);
    return (i == g->n);    // 반환값이 1이면 성공, 0이면 실패
}

void graph_init(GraphNodeType *g) {
    int v;
    g->n = 0;
    for (v = 0; v<MAX_VERTICES; v++) {
        g->adj_list[v] = NULL;
    }
}
 

// 정점 삽입 연산
void insert_vertex(GraphNodeType *g, int v) {
    if (((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}
 
// 간선 삽입 연산, v를 u의 인접 리스트에 삽입한다.
void insert_edge(GraphNodeType *g, int u, int v) {
    GraphNode *node;
    if (u >= g->n || v >= g->n) {
        fprintf(stderr, "그래프: 정점 번호 오류");
        return;
    }
    node = (GraphNode *)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}


/////////////////////////////////////////////////////////////



void printArr(int dist[], int n) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i) {
        dist[i] == INT_MAX ? printf("%d \t\tINF\n",i) : printf("%d \t\t %d\n", i, dist[i]);
    }
}

void BellmanFord(GraphType *graph, int src) {
    int V = graph->V;
    int E = graph->E;
    int *dist = (int *)malloc(sizeof(int) * V); // int dist[V+1]과 같다.
 
    // 모든 최단 거리를 무한대로 지정해주고, 시작점(src)만 0으로 초기화 한다.
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
 
    // 벨만 포드 알고리즘
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dst;
            int weight = graph->edge[j].weight;
            // printf("u:%2d, v:%2d, weight:%2d \n", u, v, weight);
            // 정점u가(시작점이) 무한대가 아니고, 
            // 시작점까지의 최단 거리 + 가중치가 도착점의 가중치 
            // 보다 작을 때 업데이트 해준다.
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                // printf("SRC: %d \tDST: %d \tweight: %d\n", graph->edge[j].src, graph->edge[j].dst, graph->edge[j].weight);
                // if(v == graph->V - 1) printf("%d\n", dist[v]);
                if(v == graph->V - 2) printf("dist[%d] = dist[%d] + weight : %2d + %2d => %2d\n", v, u, dist[u], weight, dist[v]);
            }
        }
    }
 
    // 음의 가중치 때문에 무한히 최단 경로가 작아지는 것이 있다면
    // 탐색하여 알려준다.
    for (int i = 0; i < E; i++)  {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dst;
        int weight = graph->edge[i].weight;
        // if문에서 현재위치 최단거리 + 가중치가 계속해서 더 작아질 경우
        // 음의 사이클이 있다고 판단한다.
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            printf("Graph contains negative weight cycle\n");
    }
 
    printArr(dist, V);
 
    return;
}

// 넓이 순으로 정렬(오름차순)
void SortByWeight(BrickType *brick, int size) {
    BrickType tmp;
    
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (brick[i].width > brick[j].width) {
                tmp = brick[j];
                brick[j] = brick[i];
                brick[i] = tmp;
            }
        }
    }
}

// 마지막 노드 추가
void addLastNode(BrickType *brick, int size) {
    brick[size + 1].number = size + 1;
    brick[size + 1].width = -INT_MAX;
    brick[size + 1].height = -INT_MAX;
    brick[size + 1].weight = -INT_MAX;
}

GraphType *createGraph(int V, int E) {
    GraphType* graph = (GraphType*) malloc(sizeof(GraphType));
 
    graph->V = V;
    graph->E = E;
 
    graph->edge = (EdgeType*) malloc(graph->E * sizeof(EdgeType));
 
    return graph;
}

 
int main() {
    FILE *input;
    int number, count = 0, V, E, flag;
    char lines[100];  // 배열의 최대 크기는 100
    BrickType brick[MAX_BRICK_SIZE];
    GraphType *graph;

    input = fopen("INPUT.txt", "r");  // INPUT.txt 파일 불러오기

    // 첫번째 줄 불러오기
    number = fgetc(input) - 48;  
    
    // 두전째 줄부터의 숫자 불러오기 (0번 벽돌의 값은 0)
    for (int i = 0; i <= number; i++) {
        fgets(lines, sizeof(lines), input);
        brick[i].width = atoi(strtok(lines, " "));
        brick[i].height = atoi(strtok(NULL, " "));
        brick[i].weight = atoi(strtok(NULL, " "));
        brick[i].number = i;
    }
    
    SortByWeight(brick, number+1);
    addLastNode(brick, number); // 마지막 노드 추가
    
    V = number + 2; // 처음 노드, 마지막 노드 포함
    E = (number + 1) * (number + 2) / 2;


    graph = createGraph(V, E);
    flag = 0;

    // printf("V:%d E:%d\n", graph->V, graph->E);


     // 마지막 노드 전까지만 계산
     for (int i = number; i >= 0; i--) {
         for (int j = number; j >= 0; j--) {
             if (i == j) {
                 continue;
             }
             else if (j > i) {
                continue;
             }
             else {
                graph->edge[flag].src = brick[i].number;
                graph->edge[flag].dst = brick[j].number;

                if (graph->edge[flag].dst == 0) {
                    graph->edge[flag].src = brick[j].number;
                    graph->edge[flag].dst = brick[i].number;
                }
                

                if (brick[i].width > brick[j].width) {
                    if (brick[i].weight > brick[j].weight) {
                        graph->edge[flag].weight = -brick[i].height;
                    }
                    else {
                        graph->edge[flag].weight = 0;
                    }
                }
                else {
                    if (brick[i].weight < brick[j].weight) {
                        graph->edge[flag].weight = -brick[j].height;
                    }
                    else {
                        graph->edge[flag].weight = 0;
                    }
                }

             }
            if (flag == E) {
                break;
            }
            else {
                flag++;
            }
         }
     }

     // 초기 노드와 마지막 노드 계산
     for (int i = 0; i < number + 1; i++) {
        graph->edge[flag].src = brick[i].number;
        graph->edge[flag].dst = brick[number + 1].number;
        graph->edge[flag].weight = 0;
        flag++;
     }

     printf("flag:%d, E:%d\n\n\n", flag, E);

    GraphNodeType g;
    graph_init(&g);

    for (int i = 0; i < number + 1; i++) {
        insert_vertex(&g, i);
    }



    printf("\t\t============================\n");
    for (int i = 0; i <= number + 1; i++) {
        printf("%d번 구조체 === brickNum[%d] ::: width[%d] : %10d, \theight[%d] : %10d, \tweight[%d] : %10d\n", i, brick[i].number, i, brick[i].width, i, brick[i].height, i, brick[i].weight);
    }
    
    
    printf("\n\n");


    for (int i = 0; i < flag; i++) {
        printf("edge[%2d].src : %d \tedge[%2d].dst : %d \tedge[%2d].weight : %d \n", i, graph->edge[i].src, i, graph->edge[i].dst, i, graph->edge[i].weight);
    }
   
    BellmanFord(graph, 0);

    // topo_sort(&graph);
    
    free(graph);

    return 0;
}

// https://strawberry-moon329.tistory.com/6