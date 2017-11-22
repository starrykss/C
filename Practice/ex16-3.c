// calloc, realloc 함수를 사용한 양수 입력
// calloc 함수는 할당한 저장 공간을 0으로 초기화하고, realloc 함수는 크기를 조절함.
// realloc 함수는 이미 할당한 저장 공간의 포인터와 조정할 저장 공간의 전체 크기를 줌.

/*
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *pi;				// 할당한 저장 공간을 연결할 포인터
	int size = 5;		// 한 번에 할당할 저장 공간의 크기, int형 변수 4개씩
	int cnt = 0;			// 현재 입력된 양수 개수
	int num;				// 양수를 입력할 변수
	int i;					// 반복 제어 변수

	pi = (int *)calloc(size, sizeof(int));	// 먼저 5개의 저장 공간 할당
	while (1) {
		printf("양수를 입력하세요 => ");
		scanf("%d", &num);		// 데이터 입력
		if (num <= 0) break;			// 0또는 음수이면 종료
		if (cnt == size) {				// 저장 공간을 모두 사용하면
			size += 5;					// 크기를 늘려서 재할당
			pi = (int *)realloc(pi, size * sizeof(int));
		}
		pi[cnt++] = num;
	}
	for (i = 0; i < cnt; i++) {
		printf("%5d", pi[i]);		// 입력한 데이터 출력
	}
	free(pi);							// 동적 할당 저장 공간 반납

	return 0;
}
*/