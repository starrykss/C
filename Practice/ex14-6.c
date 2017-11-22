// 포인터 배열로 여러 개의 문자열 출력
// 2차원 char 배열과 char 포인터 배열은 초기화 방법이 같음.
// char *pary[5] = { "dog", "elephant", "horse", "tiger", "lion" };
// char animal1[5][20] = { "dog", "elephant", "horse", "tiger", "lion" };
/*
#include <stdio.h>

int main(void) {
	char *pary[5];		// 포인터 배열 선언
	int i;

	pary[0] = "dog";	// 배열 요소에 문자열 대입
	pary[1] = "elephant";	
	pary[2] = "horse";	
	pary[3] = "tiger";	
	pary[4] = "lion";

	for (i = 0; i < 5; i++) {
		printf("%s\n", pary[i]);
	}

	return 0;
}
*/