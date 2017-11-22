// 배열명처럼 사용되는 포인터
/*
#include <stdio.h>

int main(void) {
	int ary[3];
	int *pa = ary;
	int i;

	*pa = 10;				// 첫 번째 배열 요소에 10 대입
	*(pa + 1) = 20;			// 두 번째 배열 요소에 20 대입
	pa[2] = pa[0] + pa[1];

	for (i = 0; i < 3; i++) {
		printf("%5d", pa[i]);
	}

	return 0;
}
*/