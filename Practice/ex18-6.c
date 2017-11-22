// 파일의 형태와 개방 모드가 다른 경우
// 개방 모드에 텍스트 파일은 't', 바이너리 파일은 'b'를 추가하여 개방함.
// fgetc 함수는 리턴문자(CR)를 읽으면 버리고 다음의 개행문자(LF) 하나만 입력
// fgetc 함수는 Ctrl+Z 키에 대한 아스키 문자를 읽으면 파일의 끝으로 인식함.
/*
#include <stdio.h>

int main(void) {
	FILE *fp;
	int ary[10] = { 13, 10, 13, 13, 10, 26, 13, 10, 13, 10 };
	int i, res;

	fp = fopen("a.txt", "wb");		// 바이너리 파일로 개방
	for (i = 0; i < 10; i++) {
		fputc(ary[i], fp);				// 배열 요소의 각 값에 해당하는 아스키문자 출력
	}
	fclose(fp);

	fp = fopen("a.txt", "rt");		// 같은 파일을 텍스트 파일로 개방
	while (1) {
		res = fgetc(fp);
		if (res == EOF) break;
		printf("%4d", res);
	}
	fclose(fp);
	
	return 0;
}
*/