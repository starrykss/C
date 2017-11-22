// 3명 학생의 네 과목 총점과 평균을 구하는 프로그램
/*
#include <stdio.h>

int main(void) {
	int score[3][4];
	int tot;
	double avg;
	int i, j;

	for (i = 0; i < 3; i++) {
		printf("네 과목 점수 입력 : ");
		for (j = 0; j < 3; j++) {
			scanf("%d", &score[i][j]);
		}
	}

	for (i = 0; i < 3; i++) {
		tot = 0;		// 학생이 바뀔 때마다 새로 0으로 초기화
		for (j = 0; j < 3; j++) {
			tot += score[i][j];
		}
		avg = tot / 4.0;
		printf("총점 : %d, 평균 : %.2lf\n", tot, avg);
	}

	return 0;
}
*/