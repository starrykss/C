// 주소로 쓰이는 배열과 배열의 주소 비교
// 배열에 주소 연산자를 사용하면 배열을 가리키는 주소가 됨.
// 배열은 전체가 하나의 논리적인 변수
// sizeof (ary) - 배열 전체의 크기 계싼
// &ary - 배열 전체의 시작 주소, 배열 전체를 가리키는 주소
/*
#include <stdio.h>

int main(void) {
	int ary[5];

	printf("ary의 값 : %u\n", ary);
	printf("ary의 주소 : %u\n", &ary);

	printf("ary + 1 : %u\n", ary + 1);
	printf("&ary + 1 : %u\n", &ary + 1);

	return 0;
}
*/