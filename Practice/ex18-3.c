// 문자열을 한 문자씩 파일로 출력하기
// 한 문자를 파일로 출력할 때는 fputc 함수를 사용
// fputc 함수도 출력 과정에서 스트림 파일의 버퍼를 사용함.
/*
#include <stdio.h>

int main(void) {
	FILE *fp;
	
	char str[] = "banana";
	int i;

	fp = fopen("b.txt", "w");
	if (fp == NULL) {
		printf("파일을 만들지 못했습니다. \n");
		return 1;
	}

	i = 0;
	while (str[i] != '\0') {
		fputc(str[i], fp);
		i++;
	}
	fputc('\n', fp);
	fclose(fp);

	return 0;
}
*/