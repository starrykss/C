// 포인터에 const 사용
// 포인터에 const를 사용하면 가리키는 변수의 값을 바꿀 수 있음.
// 변수 a는 어디까지나 포인터를 통해서만 바꿀 수 없으며 변수 a 자체를 사용하면 얼마든지 바꿀 수 있음.
// 포인터에 const를 사용하는 대표적인 예는 문자열 상수를 인수로 받는 함수. 
// -> 문자열 상수는 값이 바뀌면 안되는 저장 공간이므로 함수의 매개변수를 통해서 바꿀 수 없도록 매개변수로 선언된 포인터에 const를 사용.
/*
#include <stdio.h>

int main(void) {
	int a = 10, b = 20;
	const int *pa = &a;

	printf("변수 a값 : %d\n", *pa);
	pa = &b;
	printf("변수 b값 : %d\n", *pa);
	pa = &a;
	a = 20;
	printf("변수 a값 : %d \n", *pa);

	return 0;
}
*/