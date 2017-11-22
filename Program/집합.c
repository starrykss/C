/*
* �̻���� ���α׷��� ���� #1 : ����ü�� Ȱ���� ���� ���� ����
* �й� : 201620207
* �а� : ��ǻ���������к�
* �̸� : ����
* Visual Studio ���� : 2017
*/
/*
#include <stdio.h>

typedef struct Set
{
	int num;	// ���տ� ���Ե� ������ ����
	int element[5];	// �ּ� 1�� �̻� �ִ� 5���� ���Ҹ� �Է¹��� �迭 ����
} Set;

int main()
{
	int uni[10];
	int a[5], b[5], c[10];
	int tmp = 0, cntp = 0, cnt = 0, cntA = 1, cntB = 1, cntU = 0, flag = 0;
	Set A, B;

	// �� �ʱ�ȭ
	A.num = 0;
	B.num = 0;

	printf("  201620207 ���� \n\n");		// �й�, �̸� ����

	// ���� A
	printf("  A ���տ� �Է��� ���� ���� : ");
	scanf("%d", &A.num);
	if ((A.num > 5) || (A.num < 1)) {	// ���� A�� ���Ե� ������ ������ 5�� �ʰ� 1�� �̸��� ���
		return 0;		// ���α׷� ����
	}

	// ���� B
	printf("  B ���տ� �Է��� ���� ���� : ");
	scanf("%d", &B.num);
	if ((B.num > 5) || (B.num < 1)) {	// ���� B�� ���Ե� ������ ������ 5�� �ʰ� 1�� �̸��� ���
		return 0;		// ���α׷� ����
	}

	printf("\n");
	printf("  ���� A ���� �Է� : ");
	for (int i = 0; i < A.num; i++) {
		scanf("%d", &A.element[i]);
	}
	printf("  ���� B ���� �Է� : ");
	for (int i = 0; i < B.num; i++) {
		scanf("%d", &B.element[i]);
	}

	printf("\n");
	printf("---------------------------------");
	printf("\n");


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
	printf("  ���� A : [");
	for (int i = 0; i < cntA; i++) {	// cntA ����
		printf("%d ", A.element[i]);
	}
	printf("\b] \n");

	// ���� B�� ���Ե� ���� ���
	printf("  ���� B : [");
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
		printf("] \n \n");	// ']' ���
	}
	else {							// ��ȣ ���� ������ ��� ���� ���� ���
		printf("\b] \n \n");		// '\b]' ��� (\b : �� ���� ����) => ���� ����
	}

	return 0;
}
*/