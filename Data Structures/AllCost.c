#include<stdio.h>

#define MAX_VERTICES 3
#define IF 1000

void allCost(int n);

int cost[MAX_VERTICES][MAX_VERTICES]={
	0 , 4 , 11 ,
	6 , 0 , 2 ,
	3 , IF , 0
};

int distance[MAX_VERTICES][MAX_VERTICES];

int main(void){
	int i,j,n;
	printf("k= -1\n");
	for(i=0;i<MAX_VERTICES;i++){
		for(j=0;j<MAX_VERTICES;j++) {
            printf("%d ",cost[i][j]);
        }
		printf("\n");
	}
	printf("\n");
	allCost(MAX_VERTICES);
	return 0;
}

void allCost(int n) {
	int i,j,k;

	for(i=0 ; i <n ; i++) {
        for(j=0 ; j<n ; j++) {
            distance[i][j] = cost[i][j];
        }
    }

	for(k=0;k<n;k++) {
		printf("k = %d\n",k);
		for(i=0;i<n;i++) {
			for(j=0;j<n;j++){
				if(distance[i][k] + distance[k][j] < distance[i][j])
					distance[i][j] = distance[i][k] + distance[k][j];
				cost[i][j] = distance[i][j];
				printf("%d ",cost[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
}