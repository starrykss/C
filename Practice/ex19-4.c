// �̹� ���ǵ� ��ũ���� ���
// ��ũ�θ� __FILE__ �� __LINE__�� #define �����ڷ� �� ���Ǹ� �ٲ� �� ����.
/*
#include <stdio.h>

void func(void);

int main(void) {
	printf("������ ��¥�� �ð� : %s, %s \n\n", __DATE__, __TIME__);
	printf("���ϸ� : %s \n\n", __FILE__);
	printf("�Լ��� : %s \n\n", __FUNCTION__);
	printf("���ȣ : %d \n\n", __LINE__);

#line 100 "macro.c"		// �� ��ȣ�� 100���� ����, ���ϸ��� macro.c�� ǥ��
	func();						// ������� �� ��ȣ�� 100���� ����

	return 0;
}

void func(void) {
	printf("\n");
	printf("���ϸ� : %s\n", __FILE__);
	printf("�Լ��� : %s\n", __FUNCTION__);
	printf("���ȣ : %d\n", __LINE__);
}
*/