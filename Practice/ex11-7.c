// getchar �Լ��� ����� ���ڿ� �Է�
// getchar �Լ��� �ݺ� ����ϸ� �� ���� ���ڿ��� char �迭�� �Է��� �� ����.
/*
#include <stdio.h>

void my_gets(char *str, int size);

int main(void) {
	char str[7];

	my_gets(str, sizeof(str));						// �� ���� ���ڿ��� �Է��ϴ� �Լ�
	printf("�Է��� ���ڿ� : %s\n", str);		// �Է��� ���ڿ� ���

	return 0;
}

void my_gets(char *str, int size) {
	char ch;
	int i = 0;

	ch = getchar();
	while ((ch != '\n') && (i < size - 1)) {
		str[i] = ch;
		i++;
		ch = getchar();
	}
	str[i] = '\0';
}
*/