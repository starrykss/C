// ũ�Ⱑ �ٸ� �迭�� ����ϴ� �Լ�
// print_ary �Լ� �ȿ��� sizeof �����ڷ� �迭�� ũ�⸦ �� �� ����..
// -> sizeof(pa) / sizeof(pa[0]) => �������� ũ�� / ù ��° �迭 ����� ũ�� => 4 / 4
/*
#include <stdio.h>

void print_ary(int *pa, int size);

int main(void) {
	int ary1[5] = { 10, 20, 30, 40, 50 };
	int ary2[7] = { 10, 20, 30, 40, 50, 60, 70 };

	print_ary(ary1, 5);			// print_ary(ary1, sizeof(ary1) / sizeof(ary[0])) ���� �ص� ��.
	printf("\n");
	print_ary(ary2, 7);

	return 0;
}

void print_ary(int *pa, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", pa[i]);
	}
}
*/