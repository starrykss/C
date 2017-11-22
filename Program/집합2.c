/*
#include <stdio.h>
#define NUM 10

typedef struct Set
{
	int num;	// ���տ� ���Ե� ������ ����
	int element[NUM];	// �ּ� 1�� �̻� �ִ� 5���� ���Ҹ� �Է¹��� �迭 ����
} Set;

int main()
{
	int uni[2* NUM];
	int a[NUM], b[NUM], c[2* NUM];
	int tmp = 0, cntp = 0, cnt = 0, cntA = 1, cntB = 1, cntU = 0, flag = 0, cardA = 0, cardB = 0;
	Set A, B;

	// �� �ʱ�ȭ
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
	printf("\n �� MAX Set Size : %d\n", NUM);
	printf(" �� Made By starrykss");
	printf("\n   (http://starrykss.tistory.com)\n");
	printf("\n\n");

	// ���� A
	printf("  Input the number of the elements in Set A : ");
	scanf("%d", &A.num);
	if ((A.num > NUM) || (A.num < 1)) {	// ���� A�� ���Ե� ������ ������ NUM�� �ʰ� 1�� �̸��� ���
		return 0;		// ���α׷� ����
	}

	// ���� B
	printf("  Input the number of the elements in Set B : ");
	scanf("%d", &B.num);
	if ((B.num > NUM) || (B.num < 1)) {	// ���� B�� ���Ե� ������ ������ NUM�� �ʰ� 1�� �̸��� ���
		return 0;		// ���α׷� ����
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


	// ���� ���� ���� ////////////////////////////////////////////////////////

	//<---------- ���� A ----------->//
	// 1. �迭 ���� //
	for (int s = 0; s < A.num - 1; s++) {
		for (int t = s + 1; t < A.num; t++) {
			if (A.element[t] < A.element[s]) {     // �������� ����
				tmp = A.element[t];
				A.element[t] = A.element[s];
				A.element[s] = tmp;
			}
		}
	}

	// 2. �ߺ��� �� ã�� //
	a[0] = A.element[0];

	for (int i = 1; i < A.num; i++) {
		if (A.element[i - 1] != A.element[i]) {
			a[cntA] = A.element[i];
			cntA++;
		}		
	}

	//  3. �ٽ� �����ؼ� ����ü�� �ֱ� //
	for (int i = 0; i < cntA; i++) {
		A.element[i] = a[i];
	}

	//<---------- ���� B ----------->//
	// 1. �迭 ���� //
	for (int s = 0; s < B.num - 1; s++) {
		for (int t = s + 1; t < B.num; t++) {
			if (B.element[t] < B.element[s]) {     // �������� ����
				tmp = B.element[t];
				B.element[t] = B.element[s];
				B.element[s] = tmp;
			}
		}
	}

	// 2. �ߺ��� �� ã�� //
	b[0] = B.element[0];

	for (int i = 1; i < B.num; i++) {
		if (B.element[i - 1] != B.element[i]) {
			b[cntB] = B.element[i];
			cntB++;
		}
	}

	// 3. �ٽ� �����ؼ� ����ü�� �ֱ� //
	for (int i = 0; i < cntB; i++) {
		B.element[i] = b[i];
	}
	///////////////////////////////////////////////////////////////////////////



	// ���� A�� ���Ե� ���� ���
	printf("  SET A : [");
	for (int i = 0; i < cntA; i++) {	// cntA ����
		printf("%d ", A.element[i]);
	}
	printf("\b] \n");

	// ���� B�� ���Ե� ���� ���
	printf("  SET B : [");
	for (int i = 0; i < cntB; i++) {	// cntB ����
		printf("%d ", B.element[i]);
	}
	printf("\b] \n");

	printf("\n \n");
	printf("  A �� B : [");
	// ������ ���� �߰�
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

	// ��ȣ ���� ������ ����� ��� ��ȣ�� ���������� ����ϱ� ����
	if (cntp == 0) {		// ��ȣ ���� ������ ����� ���
		printf("] \n");	// ']' ���
	}
	else {							// ��ȣ ���� ������ ��� ���� ���� ���
		printf("\b] \n");		// '\b]' ��� (\b : �� ���� ����) => ���� ����
	}

	printf("  A �� B : [");
	// ������ ���� �߰�
	flag = 0;

	for (int i = 0; i < cntA; i++) {
		uni[flag] = A.element[i];		// ���� A�� �ִ� ���ҵ��� uni �迭�� ����.
		flag++;
	}

	for (int i = 0; i < cntB; i++) {
		uni[flag] = B.element[i];
		flag++;
	}

	// 1. �迭 ���� //
	for (int s = 0; s < flag - 1; s++) {
		for (int t = s + 1; t < flag; t++) {
			if (uni[t] <uni[s]) {     // �������� ����
				tmp = uni[t];
				uni[t] = uni[s];
				uni[s] = tmp;
			}
		}
	}

	// 2. �ߺ��� �� ã�� //
	c[0] = uni[0];

	for (int i = 0; i < flag; i++) {
		if (uni[i - 1] != uni[i]) {
			c[cntU] = uni[i];
			cntU++;
		}
	}

	// 3. �ٽ� �����ؼ� ����ü�� �ֱ�
	for (int i = 0; i < cntU; i++) {
		uni[i] = c[i];
	}

	// 4. ����ϱ�
	for (int i = 0; i < cntU; i++) {
		printf("%d ", uni[i]);
	}

	//

	printf("\b] \n");

	printf("  A - B : [");
	// A-B ���� �߰�
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
	// ��ȣ ���� ������ ����� ��� ��ȣ�� ���������� ����ϱ� ����
	if (cntp == 0) {		// ��ȣ ���� ������ ����� ���
		printf("] \n");	// ']' ���
	}
	else {							// ��ȣ ���� ������ ��� ���� ���� ���
		printf("\b] \n");		// '\b]' ��� (\b : �� ���� ����) => ���� ����
	}

	printf("  B - A : [");
	// B-A ���� �߰�

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
	// ��ȣ ���� ������ ����� ��� ��ȣ�� ���������� ����ϱ� ����
	if (cntp == 0) {		// ��ȣ ���� ������ ����� ���
		printf("] \n");	// ']' ���
	}
	else {							// ��ȣ ���� ������ ��� ���� ���� ���
		printf("\b] \n");		// '\b]' ��� (\b : �� ���� ����) => ���� ����
	}

	// ī�𳯸�Ƽ
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