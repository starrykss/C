// 3번 실행되는 재귀호출 함수
/*
#include <stdio.h>

void fruit(int n);

int main(void) {
	fruit(1);

	return 0;
}

void fruit(int n) {				// 호출 횟수를 매개변수에 저장
	printf("apple\n");
	if (n == 3) return;			// 호출 횟수가 3이면 반환하고 끝낸다.
	fruit(n + 1);					// 재호출할 때 호출 횟수를 1 증가
}
*/