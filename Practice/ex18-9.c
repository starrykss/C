// �پ��� �ڷ����� ���Ŀ� �°� �����
// ���Ͽ� ����� ���ڿ��� ���ڷ� ��ȯ�Ͽ� �Է��� ���� fscanf �Լ��� ���
// fscanf �Լ��� ������ �����͸� �Է��� �� ������ ���¿� �°� �ڵ� ��ȯ��.
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
		printf("�Է� ������ ���� ���߽��ϴ�.\n");
		return 1;
	}

	ofp = fopen("b.txt", "w");
	if (ofp == NULL) {
		printf("��� ������ ���� ���߽��ϴ�.\n");
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