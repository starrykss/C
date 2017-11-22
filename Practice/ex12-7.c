// 문자열을 출력하는 puts와 fputs 함수
// puts 함수는 fputs 함수와 달리 문자열을 출력한 후에 자동으로 줄을 바꿔주므로 편리하지만 줄을 바꾸고 싶지 않을 때는 적당하지 않음.
/*
#include <stdio.h>

int main(void) {
	char str[80] = "apple juice";			// 배열에 문자열 초기화
	char *ps = "banana";					// 포인터에 문자열 연결

	puts(str);									// apple juice 출력하고 줄 바꿈
	fputs(ps, stdout);						// banana만 출력
	puts("milk");								// banana에 이어 milk 출력

	return 0;
}
*/