/*
#include <stdio.h>
#define NUM 10

typedef struct Set
{
	int num;	// 집합에 포함된 원소의 개수
	int element[NUM];	// 최소 1개 이상 최대 5개의 원소를 입력받을 배열 선언
} Set;

int main()
{
	int uni[2* NUM];
	int a[NUM], b[NUM], c[2* NUM];
	int tmp = 0, cntp = 0, cnt = 0, cntA = 1, cntB = 1, cntU = 0, flag = 0, cardA = 0, cardB = 0;
	Set A, B;

	// 값 초기화
	A.num = 0;
	B.num = 0;
	
	for (int i = 0; i < 60; i++) {
		printf("=");
	}
	printf("\n");
	for (int i = 0; i < 25; i++) {
		printf(" ");
	}
	printf("SET Program \n");
	for (int i = 0; i < 60; i++) {
		printf("=");
	}
	printf("\n ■ MAX Set Size : %d\n", NUM);
	printf(" ■ Made By starrykss");
	printf("\n   (http://starrykss.tistory.com)\n");
	printf("\n\n");

	// 집합 A
	printf("  Input the number of the elements in Set A : ");
	scanf("%d", &A.num);
	if ((A.num > NUM) || (A.num < 1)) {	// 집합 A에 포함된 원소의 개수가 NUM개 초과 1개 미만일 경우
		return 0;		// 프로그램 종료
	}

	// 집합 B
	printf("  Input the number of the elements in Set B : ");
	scanf("%d", &B.num);
	if ((B.num > NUM) || (B.num < 1)) {	// 집합 B에 포함된 원소의 개수가 NUM개 초과 1개 미만일 경우
		return 0;		// 프로그램 종료
	}

	printf("\n");
	printf("  Input %d element(s) in Set A : ", A.num);
	for (int i = 0; i < A.num; i++) {
		scanf("%d", &A.element[i]);
	}
	printf("  Input %d element(s) in Set B : ", B.num);
	for (int i = 0; i < B.num; i++) {
		scanf("%d", &B.element[i]);
	}

	printf("\n");
	for (int i = 0; i < 60; i++) {
		printf("-");
	}
	printf("\n\n");


	// 집합 원소 정리 ////////////////////////////////////////////////////////

	//<---------- 집합 A ----------->//
	// 1. 배열 정렬 //
	for (int s = 0; s < A.num - 1; s++) {
		for (int t = s + 1; t < A.num; t++) {
			if (A.element[t] < A.element[s]) {     // 오름차순 정렬
				tmp = A.element[t];
				A.element[t] = A.element[s];
				A.element[s] = tmp;
			}
		}
	}

	// 2. 중복된 수 찾기 //
	a[0] = A.element[0];

	for (int i = 1; i < A.num; i++) {
		if (A.element[i - 1] != A.element[i]) {
			a[cntA] = A.element[i];
			cntA++;
		}		
	}

	//  3. 다시 복사해서 구조체에 넣기 //
	for (int i = 0; i < cntA; i++) {
		A.element[i] = a[i];
	}

	//<---------- 집합 B ----------->//
	// 1. 배열 정렬 //
	for (int s = 0; s < B.num - 1; s++) {
		for (int t = s + 1; t < B.num; t++) {
			if (B.element[t] < B.element[s]) {     // 오름차순 정렬
				tmp = B.element[t];
				B.element[t] = B.element[s];
				B.element[s] = tmp;
			}
		}
	}

	// 2. 중복된 수 찾기 //
	b[0] = B.element[0];

	for (int i = 1; i < B.num; i++) {
		if (B.element[i - 1] != B.element[i]) {
			b[cntB] = B.element[i];
			cntB++;
		}
	}

	// 3. 다시 복사해서 구조체에 넣기 //
	for (int i = 0; i < cntB; i++) {
		B.element[i] = b[i];
	}
	///////////////////////////////////////////////////////////////////////////



	// 집합 A에 포함된 원소 출력
	printf("  SET A : [");
	for (int i = 0; i < cntA; i++) {	// cntA 까지
		printf("%d ", A.element[i]);
	}
	printf("\b] \n");

	// 집합 B에 포함된 원소 출력
	printf("  SET B : [");
	for (int i = 0; i < cntB; i++) {	// cntB 까지
		printf("%d ", B.element[i]);
	}
	printf("\b] \n");

	printf("\n \n");
	printf("  A ∩ B : [");
	// 교집합 내용 추가
	flag = 0;
	cntp = 0;

	for (int i = 0; i < cntA; i++) {
		for (int j = 0; j < cntB; j++) {
			if (A.element[i] == B.element[j]) {
				flag++;
			}
		}
		if (flag != 0) {
			printf("%d ", A.element[i]);
			flag = 0;
			cntp++;
		}
		else {
			flag = 0;
		}
	}
	//

	// 괄호 안의 내용이 비었을 경우 괄호를 정상적으로 출력하기 위함
	if (cntp == 0) {		// 괄호 안의 내용이 비었을 경우
		printf("] \n");	// ']' 출력
	}
	else {							// 괄호 안의 내용이 비어 있지 않을 경우
		printf("\b] \n");		// '\b]' 출력 (\b : 앞 글자 삭제) => 공백 삭제
	}

	printf("  A ∪ B : [");
	// 합집합 내용 추가
	flag = 0;

	for (int i = 0; i < cntA; i++) {
		uni[flag] = A.element[i];		// 집합 A에 있는 원소들을 uni 배열에 대입.
		flag++;
	}

	for (int i = 0; i < cntB; i++) {
		uni[flag] = B.element[i];
		flag++;
	}

	// 1. 배열 정렬 //
	for (int s = 0; s < flag - 1; s++) {
		for (int t = s + 1; t < flag; t++) {
			if (uni[t] <uni[s]) {     // 오름차순 정렬
				tmp = uni[t];
				uni[t] = uni[s];
				uni[s] = tmp;
			}
		}
	}

	// 2. 중복된 수 찾기 //
	c[0] = uni[0];

	for (int i = 0; i < flag; i++) {
		if (uni[i - 1] != uni[i]) {
			c[cntU] = uni[i];
			cntU++;
		}
	}

	// 3. 다시 복사해서 구조체에 넣기
	for (int i = 0; i < cntU; i++) {
		uni[i] = c[i];
	}

	// 4. 출력하기
	for (int i = 0; i < cntU; i++) {
		printf("%d ", uni[i]);
	}

	//

	printf("\b] \n");

	printf("  A - B : [");
	// A-B 내용 추가
	flag = 0;
	cntp = 0;

	for (int i = 0; i < cntA; i++) {
		for (int j = 0; j < cntB; j++) {
			if (A.element[i] == B.element[j]) {
				flag++;
			}
		}	// end of for
		if (flag == 0) {
			printf("%d ", A.element[i]);
			flag = 0;
			cntp++;
		}
		else {
			flag = 0;
		}
	}
	//
	// 괄호 안의 내용이 비었을 경우 괄호를 정상적으로 출력하기 위함
	if (cntp == 0) {		// 괄호 안의 내용이 비었을 경우
		printf("] \n");	// ']' 출력
	}
	else {							// 괄호 안의 내용이 비어 있지 않을 경우
		printf("\b] \n");		// '\b]' 출력 (\b : 앞 글자 삭제) => 공백 삭제
	}

	printf("  B - A : [");
	// B-A 내용 추가

	flag = 0;
	cntp = 0;

	for (int i = 0; i < cntB; i++) {
		for (int j = 0; j < cntA; j++) {
			if (B.element[i] == A.element[j]) {
				flag++;
			}
		}	// end of for
		if (flag == 0) {
			printf("%d ", B.element[i]);
			flag = 0;
			cntp++;
		}
		else {
			flag = 0;
		}
	}
	//
	// 괄호 안의 내용이 비었을 경우 괄호를 정상적으로 출력하기 위함
	if (cntp == 0) {		// 괄호 안의 내용이 비었을 경우
		printf("] \n");	// ']' 출력
	}
	else {							// 괄호 안의 내용이 비어 있지 않을 경우
		printf("\b] \n");		// '\b]' 출력 (\b : 앞 글자 삭제) => 공백 삭제
	}

	// 카디날리티
	for (int i = 0; i < cntA; i++) {
		cardA++;
	}
	
	for (int i = 0; i < cntB; i++) {
		cardB++;
	}

	printf("  |A| : %d \n", cardA);
	printf("  |B| : %d \n \n", cardB);

	system("pause");
	
	return 0;
}
*/