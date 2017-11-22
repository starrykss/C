// 문자열을 저장하는 char형 배열
// 문자들을 하나씩 대입한다면 마지막에 반드시 널문자를 직접 채워야 함. (ex8-6.c 참고)
/*
#include <stdio.h>

int main(void) {
	char str[80] = "applejam";			// char str[80] = { 'a', 'p', 'p', 'l', 'e', 'j', 'a', 'm'}; 도 가능함. (문자상수로 하나씩 초기화)

	printf("최초 문자열 : %s \n", str);
	printf("문자열 입력 : ");
	scanf("%s", str);
	printf("입력 후 문자열 : %s \n", str);

	return 0;
}
*/