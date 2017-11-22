// 파일의 내용을 화면에 출력하기
// fgetc 함수는 파일에서 하나의 문자를 입력함.
// fgetc 함수는 파일의 데이터를 모두 읽으면 EOF를 반환
// 하드디스크에서 버퍼의 크기만큼 데이터를 한꺼번에 가져와 저장함.
// 스트림 파일에는 문자를 입력할 버퍼의 위치를 알려주는 지시자가 있음.
/*
#include <stdio.h>

int main(void) {
	FILE *fp;
	int ch;

	fp = fopen("a.txt", "r");
	if (fp == NULL) {
		printf("파일이 열리지 않습니다.\n");
		return 1;
	}
	while (1) {
		ch = fgetc(fp);			// 개방한 파일에서 문자 입력
		if (ch == EOF) {		// 함수의 반환값이 EOF이면 입력 종료
			break;
		}
		putchar(ch);				// 입력한 문자를 화면에 출력
	}
	fclose(fp);

	return 0;
}
*/