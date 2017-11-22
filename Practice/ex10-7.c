// 크기가 다른 배열을 출력하는 함수
// print_ary 함수 안에서 sizeof 연산자로 배열의 크기를 알 수 없음..
// -> sizeof(pa) / sizeof(pa[0]) => 포인터의 크기 / 첫 번째 배열 요소의 크기 => 4 / 4
/*
#include <stdio.h>

void print_ary(int *pa, int size);

int main(void) {
	int ary1[5] = { 10, 20, 30, 40, 50 };
	int ary2[7] = { 10, 20, 30, 40, 50, 60, 70 };

	print_ary(ary1, 5);			// print_ary(ary1, sizeof(ary1) / sizeof(ary[0])) 으로 해도 됨.
	printf("\n");
	print_ary(ary2, 7);

	return 0;
}

void print_ary(int *pa, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", pa[i]);
	}
}
*/