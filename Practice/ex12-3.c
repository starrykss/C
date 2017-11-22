// scanf 함수를 사용한 문자열 입력
// %s를 사용하여 고백이 없는 연속된 문자들을 입력 받음.
// 나머지 문자열은 버퍼에 남아 있으며 다음에 호출되는 함수가 입력에 사용.
/*
#include <stdio.h>

int main(void) {
	char str[80];

	printf("문자열 입력 : ");
	scanf("%s", str);									// %s를 사용하고 배열명을 준다.
	printf("첫 번째 단어 : %s\n", str);		// 배열에 입력된 문자열 출력
	scanf("%s", str);								
	printf("버퍼에 남아 있는 두 번째 단어 : %s\n", str);

	return 0;

}
*/