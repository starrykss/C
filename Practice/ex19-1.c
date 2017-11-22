// 사용자 정의 헤더 파일을 사용하는 프로그램
// 꺽쇠괄호를 사용하면 복사할 파일을 컴파일러가 설정한 include 디렉터리에서 찾음.
// 큰 따옴표를 사용하면 소스 파일이 저장된 디렉토리에서 먼저 찾음.
// #include 지시자는 헤더 파일뿐만 아니라 모든 텍스트 파일에 사용할 수 있음.
/*
#include <stdio.h>
#include "student.h"

int main(void) {
	Student a = { 315, "홍길동" };
	printf("학번 : %d, 이름 : %s\n", a.num, a.name);

	return 0;
}
*/