// 입력 문자의 아스키 코드값을 출력하는 프로그램
// scanf 함수는 키보드로 Ctrl+Z를 누르면 -1을 반환함. (유닉스나 리눅스 시스템에서는 Ctrl+D를 사용)
/*
#include <stdio.h>

int main(void) {
	int res;
	char ch;

	while (1) {
		res = scanf("%c", &ch);
		if (res == -1) break;
		printf("%d ", ch);
	}

	return 0;
}
*/