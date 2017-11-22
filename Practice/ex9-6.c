// 허용되지 않는 포인터의 대입
// 포인터는 가리키는 변수의 형태가 같을 때만 대입해야 함.
// 그러나 형변환을 사용한 포인터의 대입은 언제나 가능함.
/*
#include <stdio.h>

int main(void) {
	int a = 10;
	int *p = &a;
	double *pd;

	pd = p;		// 포인터 p값을 포인터 pd에 대입
	printf("%lf\n", *pd);

	return 0;
}
*/