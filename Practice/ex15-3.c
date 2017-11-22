// 포인터 배열의 값을 출력하는 함수
// 2중 포인터는 포인터 배열을 매개변수로 받는 함수에도 사용함.
/*
#include <stdio.h>

void print_str(char **pps, int cnt);

int main(void) {
	char *ptr_ary[] = { "eagle", "tiger", "lion", "squirrel" };		// 초기화
	int count;			// 배열 요소를 저장할 변수

	count = sizeof(ptr_ary) / sizeof(ptr_ary[0]);		// 배열 요소의 수 계산
	print_str(ptr_ary, count);			// 배열명과 배열 요소 수를 주고 호출

	return 0;
}

void print_str(char **pps, int cnt) {
	int i;

	for (i = 0; i < cnt; i++) {
		printf("%s\n", pps[i]);
	}
}
*/