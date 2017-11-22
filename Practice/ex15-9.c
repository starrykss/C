// void 포인터의 사용
// void 포인터는 가리키는 자료형이 정해지지 않은 포인터
// void 포인터를 사용할 때는 원하는 형태로 변환하여 사용.
/*
#include <stdio.h>

int main(void) {
	int a = 10;
	double b = 3.5;
	void *vp;

	vp = &a;
	printf("a : %d\n", *(int *)vp);

	vp = &b;
	printf("b : %.1lf\n", *(double *)vp);

	return 0;
}
*/