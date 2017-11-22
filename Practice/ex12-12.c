// strcat, strncat 함수를 사용한 문자열 붙이기
// strcat 함수는 문자열을 이어 붙임.
// strncat 함수는 지정한 문자의 개수만큼 붙임.
// 배열이 초기화되지 않으면 쓰레기값의 중간부터 붙여넣을 가능성이 큼.

// char str[80] = {'\0'}; // 명시적으로 널문자를 초기화
// char str[80] =  {0};		// 널문자의 아스키 코드값으로 초기화
// char str[80] = "";			// 큰 따옴표 안에 아무것도 없으므로 널문자만 초기화
// str[0] = '\0';		// 첫 번째 배열 요소만 별도로 초기화

/*
#include <stdio.h>
#include <string.h>		// strcat, strncat 함수 사용을 위한 헤더 파일 포함

int main(void) {
	char str[90] = "straw";				// 문자열 초기화

	strcat(str, "berry");					// str 배열에 문자열 붙이기
	printf("%s\n", str);
	strncat(str, "piece", 3);			// str 배열에 3개의 문자 붙이기
	printf("%s\n", str);

	return 0;
}
*/