// 표준 입출력 스트림을 사용한 문자열 입력
// 운영체제는 프로그램을 실행할 때 기본적으로 3개의 스트림 파일을 만듦.
// 스트림 파일의 이름 stdin(표준 입력 스트림), stdout(표준 출력 스트림), stderr(표준 에러 스트림)은 운영체제가 개방한 파일의 주소.
/*
#include <stdio.h>

int main(void) {
	int ch;

	while (1) {
		ch = getchar();
		if (ch == EOF) {
			break;
		}
		putchar(ch);
	}

	return 0;
}
*/