// 다양한 매크로명의 사용
// 만약 매크로명을 정의할 때 치환될 부분이 길어 여러 줄에 써야 한다면 백슬래시(\)로 연결
// #define INTRO "Perfect C Language \ 
// & Basic Data Strcutrue"
/*
#include <stdio.h>

#define PI 3.14159
#define LIMIT 100.0
#define MSG "passed!"
#define ERR_PRN printf("범위를 벗어났습니다!\n");

int main(void) {
	double radius, area;

	printf("반지름을 입력하세요 : ");
	scanf("%lf", &radius);
	area = PI * radius * radius;
	if (area > LIMIT) {
		ERR_PRN;
	}
	else {		
		printf("원의 면적 : %.2lf (%s)\n", area, MSG);
	}

	return 0;
}
*/