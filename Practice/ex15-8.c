// 함수 포인터로 원하는 함수를 호출하는 프로그램
// 함수 포인터는 형태가 같은 다양한 기능의 함수를 선택적으로 호출할 때 사용
// 프로그램 정상 작동 X
/*
#include <stdio.h>

void func(int(*fp)(int, int));
int sum(int a, int b);
int mul(int a, int b);
int max(int a, int b);

int main(void) {
	int sel;

	printf("1. 두 정수의 합\n");
	printf("2. 두 정수의 곱\n");
	printf("3. 두 정수 중에서 큰 값 계산\n");
	printf("원하는 작업을 선택하세요 : ");
	scanf("%d", &sel);

	switch (sel) {
	case1: 
		func(sum); 
		break;
	case2: 
		func(mul); 
		break;
	case3: 
		func(max); 
		break;
	}

	return 0;
}

void func(int (*fp)(int, int)) {
	int a, b;
	int res;

	printf("두 정수값을 입력하세요 : ");
	scanf("%d%d", &a, &b);
	res = fp(a, b);
	printf("결과값은 : %d\n", res);
}

int sum(int a, int b) {
	return (a + b);
}

int mul(int a, int b) {
	return (a * b);
}

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
*/