// fflush 함수가 필요한 경우
// 입력 버퍼의 내용을 지울 때는 fflush(stdin)함수를 사용.
/*
#include <stdio.h>

int main(void) {
	int num, grade;

	printf("학번 입력 : ");
	scanf("%d", &num);
	fflush(stdin);			// 버퍼에 남아 있는 개행문자 제거
	printf("학점 입력 : ");
	grade = getchar();		
	printf("학번 : %d, 학점 : %c", num, grade);

	return 0;
}
*/