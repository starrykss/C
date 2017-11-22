// 파일을 열고 닫는 프로그램
// fopen 함수는 파일을 열고, fclose 함수는 파일을 닫음.
// fopen 함수가 개방할 파일을 찾는 기본 위치는 '현재 작업 디렉터리'
// fopen 함수가 파일을 찾아 개방하면 파일 포인터를 반환
// 개방한 파일을 더 이상 사용하지 않으면 fclose 함수로 닫음.
// 개방 모드 : r (읽기 위해 개방), w (파일의 내용을 지우고 쓰기 위해 개방), a (파일의 끝에 추가하기 위해 개방)
/*
#include <stdio.h>

int main(void) {
	FILE *fp;			// 파일 포인터

	fp = fopen("a.txt", "r");		// a.txt 파일을 읽기 전용으로 개방
	// fopen("c:\\source\\a.txt", "r");		// 백슬래시 두 번 사용! (주의)
	if (fp == NULL) {
		printf("파일이 열리지 않습니다.\n");
		return 1;
	}
	printf("파일이 열렸습니다.\n");
	fclose(fp);						// 파일 닫기

	return 0;
}
*/