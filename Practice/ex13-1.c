// 두 함수에서 같은 이름의 지역 변수를 사용한 경우
/*
#include <stdio.h>

void assign(void);	

int main(void) {
	auto int a = 0;		// 지역 변수 선언과 초기화, auto는 생략 가능

	assign();		// 함수 호출
	printf("main 함수 a : %d\n", a);

	return 0;
}

void assign(void) {
	auto int a;

	a = 10;
	printf("assign 함수 a : %d\n", a);
}
*/