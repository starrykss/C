// 다른 함수의 변수를 이름으로 사용 (에러)
/*
#include <stdio.h>

void swap(void);

int main(void) {
	int a = 10, b = 20;

	swap();
	printf("a:%d, b:%d\n", a, b);

	return 0;
}

void swap(void) {
	int temp;

	temp = a;
	a = b;
	b = temp;
}
*/