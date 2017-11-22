// atuo 지역 변수와 static 지역 변수의 비교
// 정적 지역 변수는 선언된 함수가 반환되더라도 그 저장 공간을 계속 유지함.
// 정적 지역 변수는 저장 공간의 할당이나 초기화 방법, 메모리 존재 기간이 전역 변수와 같음.
// 정적 지역 변수는 선언된 블록 안에서만 사용하는 전역 변수와 같음.
/*
#include <stdio.h>

void auto_func(void);
void static_func(void);

int main(void) {
	int i;

	printf("auto 지역 변수를 사용한 함수...\n");
	for (i = 0; i < 3; i++) {
		auto_func();
	}

	printf("static 지역 변수를 사용한 함수...\n");
	for (i = 0; i < 3; i++) {
		static_func();
	}

	return 0;
}

void auto_func(void) {
	auto int a = 0;		// 지역 변수 선언과 초기화

	a++;
	printf("%d\n", a);
}

void static_func(void) {
	static int a;			// 정적 지역 변수 선언

	a++;
	printf("%d\n", a);
}
*/