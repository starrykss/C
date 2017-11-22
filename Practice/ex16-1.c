// 동적 할당한 저장 공간을 사용하는 프로그램
// malloc 함수는 (void *)형을 반환하므로 용도에 맞는 포인터형으로 형변환하여 사용함.
// malloc 함수의 반환값이 널포인터가 아닌지 반드시 확인하고 사용해야 함.
// 사용이 끝난 저장 공간은 재활용 할 수 있도록 반환해야 함.

/*
#include <stdio.h>
#include <stdlib.h>			// malloc, free 함수 사용을 위한 헤더 파일

int main(void) {
	int *pi;						// 동적 할당 영역을 연결할 포인터 선언
	double *pd;				

	pi = (int *)malloc(sizeof(int));						// 메모리 동적 할당 후 포인터 연결
	if (pi == NULL) {											// 동적 할당에 실패하면 NULL 포인터 반환
		printf("#으로 메모리가 부족합니다.\n");	// 예외 상황 메시지 출력
		exit(1);													// 프로그램 종료
	}
	pd = (double *)malloc(sizeof(double));

	*pi = 10;														// 포인터로 동적 할당 영역 사용
	*pd = 3.4;		

	printf("정수형으로 사용 : %d\n", *pi);			// 동적 할당 영역에 저장된 값 출력
	printf("실수형으로 사용 : %lf\n", *pd);		

	free(pi);														// 동적 할당 영역 반환
	free(pd);

	return 0;
}
*/