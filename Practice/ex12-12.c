// strcat, strncat �Լ��� ����� ���ڿ� ���̱�
// strcat �Լ��� ���ڿ��� �̾� ����.
// strncat �Լ��� ������ ������ ������ŭ ����.
// �迭�� �ʱ�ȭ���� ������ �����Ⱚ�� �߰����� �ٿ����� ���ɼ��� ŭ.

// char str[80] = {'\0'}; // ��������� �ι��ڸ� �ʱ�ȭ
// char str[80] =  {0};		// �ι����� �ƽ�Ű �ڵ尪���� �ʱ�ȭ
// char str[80] = "";			// ū ����ǥ �ȿ� �ƹ��͵� �����Ƿ� �ι��ڸ� �ʱ�ȭ
// str[0] = '\0';		// ù ��° �迭 ��Ҹ� ������ �ʱ�ȭ

/*
#include <stdio.h>
#include <string.h>		// strcat, strncat �Լ� ����� ���� ��� ���� ����

int main(void) {
	char str[90] = "straw";				// ���ڿ� �ʱ�ȭ

	strcat(str, "berry");					// str �迭�� ���ڿ� ���̱�
	printf("%s\n", str);
	strncat(str, "piece", 3);			// str �迭�� 3���� ���� ���̱�
	printf("%s\n", str);

	return 0;
}
*/