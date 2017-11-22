// break를 사용한 반복문 종료
// break는 자신을 포함하는 반복문 하나만 벗어남.
// 또한 반복문 이외의 블록에서 사용하면 그 블록을 포함한 반복문을 벗어남.
// 단, switch~case문의 블록 안에서 사용하면 switch~case의 블록만 벗어남.

/*
#include <stdio.h>

int main(void) {
	int i;
	int sum = 0;

	for (i = 1; i <= 10; i++) {
		sum += i;
		if (sum > 30) break;
	}
	printf("누적한 값 : %d \n", sum);
	printf("마지막으로 더한 값 : %d \n", i);

	return 0;
}
*/