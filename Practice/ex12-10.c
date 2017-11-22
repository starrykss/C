// strncpy 함수를 사용한 문자열 복사
// 복사할 문자열에서 지정한 개수만큼 문자만 복사하고 널문자는 저장하지 않음.
/*
#include <stdio.h>
#include <string.h>		// strncpy 함수 사용을 위한 헤더 파일 포함

int main(void) {
	char str[20] = "mango tree";		// 배열 초기화

	strncpy(str, "apple-pie", 5);		// "apple-pie"에서 다섯 문자만 복사. 아랫줄에 str[5] = '\0';를 추가하면 apple만 출력.
	printf("%s\n", str);					// 복사받은 문자열 출력

	return 0;
}
*/