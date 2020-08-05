#include <stdio.h>
int N, E;//N=총 노드 개수, E=총 간선 개수
int arr[101][101];
int queue[1001];
int visit[101];
int target;
int front=-1, rear=0;
int cnt=0;

void BFS(){
if(front==rear) return; //1번조건
else if(queue[front]==target) return; //2번조건
else{
cnt++;//탐색 횟수 ++
int cur_front=queue[front];//현재 큐에 가장 앞에 있는 값
for(int i=0; i<=N; ++i){
if(visit[i]) continue;
if(arr[cur_front][i]==1){
visit[cur_front]=1;
queue[rear++]=i;
}
}
}
front++;//4번째 조건.
BFS();
return;
}

int main(){
scanf("%d %d", &N, &E);
for(int i=0; i<E; ++i){
int a, b;
scanf("%d %d", &a, &b);//무향그래프라고 하겠습니다.
arr[a][b]=1;
arr[b][a]=1;//인접행렬의 값을 채워줍니다. a에서 b까지 도달할 수 있고, 반대도 가능합니다.
}
printf("want to find : ");
scanf("%d", &target);
printf("start : ");//시작할 곳을 지정해줍니다.
int start;
scanf("%d", &start);
front++;
rear++;
queue[front]=start;
BFS();
printf("total search : %d\n", cnt);
}