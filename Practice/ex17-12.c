// 열거형을 사용한 프로그램
// 열거형은 변수에 저장할 수 있는 정수값을 기호로 정의하여 나열함.
/*
#include <stdio.h>

enum season {SPRING, SUMMER, FALL, WINTER}; // 열거형 선언

int main(void) {
	enum season ss;			// 열거형 변수 선언
	char *pc;						// 문자열을 저장할 포인터

	ss = SPRING;					// 열거 멤버의 값 대입
	switch (ss) {					// 열거 멤버 판단
	case SPRING:				// 봄이면
		pc = "incline"; break;	// 인라인 문자열 선택
	case SUMMER:					// 여름이면
		pc = "swimming"; break;	// 수영 문자열 선택
	case FALL:					// 가을이면
		pc = "trip"; break;		// 여행 문자열 선택
	case WINTER:				// 겨울이면
		pc = "skiing"; break;	// 스키 문자열 선택
	}
	printf("나의 레저 활동 => %s\n", pc);		// 선택된 문자열 출력

	return 0;
}
*/