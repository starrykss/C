// fgets 함수의 문자열 입력 방법
// fgets 함수는 최대 배열의 크기까지만 문자열을 입력함.
// fgets 함수는 문자열을 저장할 배열명 외에 배열의 크기와 표준 입력버퍼를 뜻하는 stdin을 함께 사용함.
// 마지막에는 항상 널문자를 붙이므로 최대로 '배열의 크기 - 1개'의 문자만을 저장함.
// 버퍼에 있는 개행문자도 배열에 저장하고 널문자를 붙여 문자열을 완성함.
// 입력된 개행문자는 불필요한 경우 다음 공식에 따라 제거함.
// : str(strlen(str) - 1) = '\0' ( include <string.h> 필요 )

/*
#include <stdio.h>

int main(void) {
	char str[80];

	printf("공백이 포함된 문자열 입력 : ");
	fgets(str, sizeof(str), stdin);								// 문자열 입력
	printf("입력된 문자열은 %s입니다.\n", str);		// 문자열 출력

	return 0;
}
*/