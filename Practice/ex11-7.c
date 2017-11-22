// getchar 함수를 사용한 문자열 입력
// getchar 함수를 반복 사용하면 한 줄의 문자열을 char 배열에 입력할 수 있음.
/*
#include <stdio.h>

void my_gets(char *str, int size);

int main(void) {
	char str[7];

	my_gets(str, sizeof(str));						// 한 줄의 문자열을 입력하는 함수
	printf("입력한 문자열 : %s\n", str);		// 입력한 문자열 출력

	return 0;
}

void my_gets(char *str, int size) {
	char ch;
	int i = 0;

	ch = getchar();
	while ((ch != '\n') && (i < size - 1)) {
		str[i] = ch;
		i++;
		ch = getchar();
	}
	str[i] = '\0';
}
*/