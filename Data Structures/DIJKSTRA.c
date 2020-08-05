#include<stdio.h>

#define MAX_VERTICES 5 //It was defined temporary.
#define DoCr 60000 //"DoCr" means "Don't Care". so it defined 60000 as largest integer.
#define TRUE 1
#define FALSE 0
#define INT_MAX 999999

short int found[MAX_VERTICES];
short int parent[MAX_VERTICES];
short int n = MAX_VERTICES;

//the Cost matrix.It is a temporary data.
//This matrix will be symetric.
/*
int cost[][MAX_VERTICES]=
	{{   0,  50,  45,  10,DoCr, DoCr},
	 {DoCr,   0, 10,   15,DoCr, DoCr},
	 {DoCr,DoCr,DoCr,DoCr,  30, DoCr},
	 {20  ,DoCr,DoCr,DoCr,   15,DoCr},
	 {DoCr,  20,  35,DoCr,DoCr, DoCr},
     {DoCr, DoCr, DoCr, DoCr, 3, DoCr}};
*/

int cost[][MAX_VERTICES]=
	{{   0,  30,  20,  15,DoCr},
	 {DoCr,   0,DoCr,DoCr,DoCr},
	 {DoCr,   5,   0,DoCr,  30},
	 {DoCr,  10,   5,   0,  15},
	 {DoCr,  50,DoCr,DoCr,   0}};

int distance[MAX_VERTICES];

int choose(int distance[], int n, short int found[]) {
	int i, min, minpos;
    min = INT_MAX;
    minpos = -1;
    for(i=0; i<n; i++)
    	if(distance[i] < min && !found[i]) {
        	min = distance[i];
            minpos=i;
		}
   	return minpos;
}

void shortestPath(int v, int cost[][MAX_VERTICES], int distance[], int n, short int found[]) {
	int i, u, w;
	printf("[[[[[[[[[[[[[BEFORE]]]]]]]]]]]]]]\n");          //*
	for(i=0; i<n; i++) { // 시작점 v에 대해 update
		found[i] = FALSE;
		distance[i] = cost[v][i]; // v로부터 연결되어 있으면 가중치값 아니면 굉장히 큰 어떤 값
		parent[i] = v;
		printf("distance[%d]: %d, found[%d]: %d, parent[%d] : %d\n", i, distance[i], i, found[i], i, parent[i]); //*
	}
	found[v] = TRUE;

	distance[v] = 0; // v 가 시작점

	for(i=0; i<n-2; i++) {
		u = choose(distance, n, found);
		found[u] = TRUE;

		printf("[%d번째]\n", i); //*
		for(int i = 0; i < n; i++) { printf("distance[%d]: %d, found[%d]: %d, parent[%d] : %d\n", i, distance[i], i, found[i], i, parent[i]); } //*
		
		for(w=0; w<n; w++) // u를 포함했을 때 각 정점까지의 거리 update
			if(!found[w])
				if(distance[u] + cost[u][w] < distance[w]) {
					distance[w] = distance[u] + cost[u][w];
					parent[w] = u;
				}	
				printf("[[[[[[[[[[[[[last]]]]]]]]]]]]]]\n"); //*
			for(int i = 0; i < n; i++) { printf("distance[%d]: %d, found[%d]: %d, parent[%d] : %d\n", i, distance[i], i, found[i], i, parent[i]); } //*
		}
		
}

int main()
{		
	int i;
	shortestPath(0,cost,distance,n,found);
	for(i=0; i<MAX_VERTICES; i++){
		printf("정점 0에서 정점 %d로의 최단경로 : %d \n", i, distance[i]);
	}
	return 0;
}	