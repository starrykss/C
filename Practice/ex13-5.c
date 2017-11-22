// 레지스터 변수를 반복문에 사용한 예
// 레즈스터 변수는 CPU의 자원을 잠깐 빌리는 것으로 변수의 저장 공간이 램 메모리에 있을 때보다 빨라 프로그램 실행 시간을 줄일 수 있음.
// 레지스터의 사용 여부는 컴파일러가 결정할 수 있음.
/*
#include <stdio.h>

int main(void) {
	register int i;			// 레지스터 변수
	auto int sum = 0;		// auto 지역 변수

	for (i = 0; i <= 10000; i++) {
		sum += i;
	}

	printf("%d\n", sum);

	return 0;
}
*/