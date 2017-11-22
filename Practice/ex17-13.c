// typedef를 사용한 자료형 재정의
/*
#include <stdio.h>

struct student {
	int num;
	double grade;
};

typedef struct student Student;		// Student형으로 재정의

// 다음과 같이 형 선언과 동시에 재정의 가능
// typedef struct student {
//		int num;
//		double grade;
//	} Student;

void print_data(Student *ps);		// 매개변수는 Student형의 포인터

int main(void) {
	Student s1 = { 315, 4.2 };			// Student형의 변수 선언과 초기화
	print_data(&s1);						// Student형 변수의 주소 전달

	return 0;
}

void print_data(Student *ps) {
	printf("학번 : %d\n", ps->num);		// Student 포인터로 멤버 접근
	printf("학점 : %.1lf\n", ps->grade);
}
*/