// 함수 포인터를 사용한 함수 호출
// 함수명은 함수의 정의가 있는 메모리의 시작 위치
/*
#include <stdio.h>

int sum(int, int);

int main(void) {
	int(*fp)(int, int);		// 함수 포인터 선언
	int res;

	fp = sum;			// 함수명을 함수 포인터에 저장
	res = fp(10, 20);
	printf("result : %d\n", res);		// 반환값 출력

	return 0;
}

int sum(int a, int b) {
	return (a + b);
}
*/