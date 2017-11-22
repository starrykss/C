// 공용체를 사용한 학번과 학점 데이터 처리
// 공용체는 모든 멤버가 하나의 저장 공간을 같이 사용함. (구조체와의 차이점)
// 공용체 변수의 크기는 멤버 중에서 크기가 가장 큰 멤버로 결정.
// 공용체 변수의 초기화는 중괄호를 사용하여 첫 번째 멤버만 초기화함.
/*
#include <stdio.h>

union student {		// 공용체 선언
	int num;				// 학번을 저장할 멤버
	double grade;	// 학점을 저장할 멤버	
};

int main(void) {
	union student s1 = { 315 };			// 공용체 변수의 선언과 초기화
	// 첫 번째 멤버가 아닌 멤버를 초기화할 때는 .연산자로 멤버를 직접 지정해야 함.
	// union student a = { .grade = 3.4 };		// grade 멤버를 3.4로 초기화

	printf("학번 : %d\n", s1.num);		// 학번 멤버 출력
	s1.grade = 4.4;							// 학점 멤버에 값 대입
	printf("학점 : %.1lf\n", s1.grade);
	printf("학번 : %d\n", s1.num);		// 학번 다시 출력

	return 0;
}
*/