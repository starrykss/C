// a+ ���� ������ ������ Ȯ���ϸ� ���
// ������ �Է°� ����� ���� ��ȯ�� ������ fseek �Լ��� ȣ���ؾ� ��.
/*
#include <stdio.h>
#include <string.h>

int main(void) {
	FILE *fp;
	char str[20];

	fp = fopen("a.txt", "a+");		// �б� ������ �߰� ���� ����
	if (fp == NULL) {
		printf("������ ������ ���߽��ϴ�.\n");
		return 1;
	}

	while (1) {
		printf("���� �̸� : ");
		scanf("%s", str);
		if (strcmp(str, "end") == 0) {		// end �Է� �� ����
			break;
		}
		else if (strcmp(str, "list") == 0) {		// list�� �Է��ϸ� ������ ���� Ȯ��
			fseek(fp, 0, SEEK_SET);				// ������ ��ġ �����ڸ� �� ó������ �̵�
			while (1) {
				fgets(str, sizeof(str), fp);			// �׸� �̸��� �д´�.	
				if (feof(fp)) {							// ������ ������ ��� ������ ����
					break;
				}
				printf("%s", str);						// ���� �׸� �̸��� ȭ�鿡 ���
			}
		}
		else {
			fprintf(fp, "%s\n", str);				// �Է��� �׸� �̸��� ���Ͽ� ���
		}
	}
	fclose(fp);

	return 0;
}
*/