// 전역 변수에 extern과 static을 사용한 프로그램
// 다른 파일에 선언된 전역 변수를 사용할 때는 extern 선언을 함.
// 컴파일러는 소스 파일 단위로 컴파일하므로 다른 파일에 선언된 전역 변수를 알지 못함.
// 전역 변수에 static을 붙이면 하나의 소스 파일에서만 사용할 수 있음.
// 함수에 static 예약어를 사용하면 함수를 정의한 소스 파일에서만 사용할 수 있음.
/*
#include <stdio.h>

int input_data(void);
double average(void);
void print_data(double);

int cnt = 0;
static int tot = 0;

int main(void) {
	double avg;

	tot = input_data();
	avg = average();
	print_data(avg);

	return 0;
}

void print_data(double avg) {
	printf("입력한 양수의 개수 : %d\n", cnt);
	printf("전체 합과 평균 : %d, %.1lf\n", tot, avg);
}
*/