// 매크로 함수를 사용한 프로그램
// 매크로 함수는 인수에 따라 서로 다른 결과값을 갖도록 치환됨
// 매크로 함수는 치환된 후의 부작요을 줄이기 위해 치환될 부분에 괄호를 써서 정의함.
/*
#include <stdio.h>

#define SUM(a, b) ((a) + (b))
#define MUL(a, b) ((a) * (b))

int main(void) {
	int a = 10, b = 20;
	int x = 30, y = 40;
	int res;

	printf("a + b = %d\n", SUM(a, b));
	printf("x + y = %d\n", SUM(x, y));
	res = 30 / MUL(2, 5);
	printf("res : %d\n", res);

	return 0;
}
*/