// #if, #ifdef, #else, #endif를 사용한 조건부 컴파일
// 조건부 컴파일은 소스코드를 조건에 따라 선택적으로 컴파일함.
// if문의 조건식이 참이면 #if와 #endif 사이의 모든 문장을 컴파일
// 조건식에 매크로명이 정의되어 있는지 검사할 때는 전처리 연산자 defined를 사용함.
// 매크로명이 정의되지 않은 경우를 확인할 때는 !defined 연산자나 #ifndef를 쓺.
// #ifdef와 #if defined 그리고 #ifndef와 #if !defined의 용도는 같음.
// 조건을 만족하지 않는 경우 컴파일 자체를 중단할 때는 #error 지시자를 사용.
/*
#include <stdio.h>
#define VER 7		// 치호나될 부분이 있는 매크로명 정의
#define BIT16		// 치환될 부분이 없는 매크로명 정의

int main(void) {
	int max;

#if VER >= 6	{								// 매크로명 VER이 6 이상이면
	printf("버전 %d입니다. \n", VER);		// 이 문장 컴파일
#endif											// if의 끝

#ifdef BIT16					// 매크로명 BIT16이 정의되어 있으면 ( <=> #if defined BIT16)
	max = 32767;			// 이 문장 컴파일
#else							// 매크로명 BIT16이 정의되어 있지 않으면
	max = 2147483647;	// 이 문장 컴파일
#endif						// ifdef의 끝

	printf("int형 변수의 최댓값 : %d\n", max);		// max 출력

	return 0;
}
*/