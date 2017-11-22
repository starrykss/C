// 전위형과 후위형을 사용한 증감 연산
// 전위형은 증감하고 나서 연산에 사용하고 후위형은 연산에 사용하고 나서 증감함.
// 증감 연산자의 후위형은 다른 연산자와 함께 사용될 때 가장 나중에 연산됨.

/*
#include <stdio.h>

int main(void) {
	int a = 5, b = 5;
	int pre, post;

	pre = (++a) * 3;		// 전위형 증감 연산자
	post = (b++) * 3;		// 후위형 증감 연산자

	printf("초깃값 a = %d, b = %d\n", a, b);
	printf("전위형: (++a) * 3 = %d, 후위형 : (b++) * 3 = %d\n", pre, post);

	return 0;
}
*/