// sizeof 연산자를 사용한 배열
/*
#include <stdio.h>

int main(void) {
	int score[5];
	int i;
	int tot = 0;
	double avg;
	int cnt;		// 배열 요소 수를 저장할 변수

	cnt = sizeof(score) / sizeof(score[0]);		// 배열 요소 수 계산

	for (i = 0; i < 5; i++) {
		scanf("%d", &score[i]);
	}

	for (i = 0; i < cnt; i++) {
		tot += score[i];
	}

	avg = tot / (double)cnt;		// 총합을 cnt로 나누어 평균 계산

	for (i = 0; i < cnt; i++) {
		printf("%5d", score[i]);
	}
	printf("\n");

	printf("평균 : %.1lf\n", avg);

	return 0;
}
*/