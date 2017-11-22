// 다양한 자료형을 형식에 맞게 입출력
// 파일에 저장된 문자열을 숫자로 변환하여 입력할 때는 fscanf 함수를 사용
// fscanf 함수는 파일의 데이터를 입력할 각 변수의 형태에 맞게 자동 변환함.
/*
#include <stdio.h>

int main(void) {
	FILE *ifp, *ofp;
	char name[20];
	int kor, eng, mat;
	int tot;
	double avg;
	int res;

	ifp = fopen("a.txt", "r");
	if (ifp == NULL) {
		printf("입력 파일을 열지 못했습니다.\n");
		return 1;
	}

	ofp = fopen("b.txt", "w");
	if (ofp == NULL) {
		printf("출력 파일을 열지 못했습니다.\n");
		return 1;
	}

	while (1) {
		res = fscanf(ifp, "%s%d%d%d", name, &kor, &eng, &mat);	
		if (res == EOF) {
			break;
		}
		tot = kor + eng + mat;
		avg = tot / 3.0;
		fprintf(ofp, "%s%5d%7.1lf\n", name, tot, avg);
	}

	fclose(ifp);
	fclose(ofp);

	return 0;
}
*/