/*
#include <stdio.h>

int main(void) {

	char ch;
	int num;
	int choice;

	printf("아스키 코드 변환 프로그램 \n \n");
	printf("<선택> \n");
	printf("0 : 문자 ->아스키 코드 \n");
	printf("1 : 아스키 코드 -> 문자 \n");
	printf("2 : 프로그램 종료 \n");
	printf("=> ");
	scanf("%d", &choice);

	switch (choice) {

	case 0:
		printf("\n [문자 -> 아스키 코드] \n");
			while (1) {
				printf("문자 입력 : ");
				scanf(" %c", &ch);

				printf("아스키 코드 값 : %d \n", ch);
			}
	case 1:
		printf("\n [아스키 코드 -> 문자] \n");
		while (1) {
			printf("아스키 코드 입력 : ");
			scanf(" %d", &num);

			printf("문자 : %c \n", num);
		}
	case 2:
		printf("\n 프로그램을 종료합니다. \n");
		break;

	}

	return 0;
}
*/