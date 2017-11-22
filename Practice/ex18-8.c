// 여러 줄의 문장을 입력하여 한 줄로 출력
// 파일에서 데이터를 한 줄씩 입력할 때는 fgets 함수를 사용.
// fgets 함수는 줄의 끝에 있는 개행문자('\n')까지 입력함.
// fgets 함수는 파일에서 더 이상 읽을 데이터가 없으면 NULL을 반환함.
// gets와 puts 대신 fgets와 fputs 함수를 사용하는 것이 좋음..
// fgets(str, sizeof(str), stdin);
// fputs(str, stdout);
/*
#include <stdio.h>
#include <string.h>

int main(void) {
	FILE *ifp, *ofp;
	char str[80];
	char *res;

	ifp = fopen("a.txt", "r");
	if (ifp == NULL) {
		printf("입력 파일을 열지 못했습니다. \n");
		return 1;
	}

	ofp = fopen("b.txt", "w");
	if (ofp == NULL) {
		printf("출력 파일을 열지 못했습니다.\n");
		return 1;
	}

	while (1) {
		res = fgets(str, sizeof(str), ifp);
		if (res == NULL) {
			break;
		}
		str[strlen(str) - 1] = '\0';
		fputs(str, ofp);
		fputs(" ", ofp);
	}
	
	fclose(ifp);
	fclose(ofp);

	return 0;
}
*/