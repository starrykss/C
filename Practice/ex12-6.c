// 개행문자로 인해 gets 함수가 입력을 못하는 경우

/*
#include <stdio.h>

int main(void) {
	int age;				// 나이를 저장할 변수
	char name[20];	// 이름을 저장할 배열

	printf("나이 입력 : ");
	scanf("%d", &age);		// 나이 입력
	printf("이름 입력 : ");
	gets(name);				// 이름 입력
	printf("나이 : %d, 이름 : %s\n", age, name);

	return 0;
}
*/

/* 문제 해결법 : 아래의 입력 함수를 호출함.
 * getchar();				// 버퍼에서 하나의 문자를 읽어서 반환, 반환 문자는 버림
 * scanf("%*c");			// 버퍼에서 하나의 문자를 읽어서 버림, 변수는 필요 없음
 * fgetc(stdin);			// 버퍼에서 하나의 문자를 읽어서 반환, 반환 문자는 버림
 *
 * fflush(stdin);			// 입력 버퍼에 있는 내용을 한 번에 지울 때 사용
 */



