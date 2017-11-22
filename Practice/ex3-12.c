// 문자와 문자열 입력
// 문자열을 입력할 때는 배열명에 &기호를 붙이지 않음.

/*
#include <stdio.h>

int main(void) {
	char grade;
	char name[20];

	printf("학점 입력 : ");
	scanf("%c", &grade);			// scanf_s 함수 : 배열의 크기까지만 문자열을 입력하도록 제한하므로 안전한 입력이 가능.
	printf("이름 입력 : ");
	scanf("%s", name);		// name 배열에 이름 문자열 입력, &를 사용하지 않음
	printf("%s의 학점은 %c입니다. \n", name, grade);

	return 0;
}
*/