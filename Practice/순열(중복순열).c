// ���� ��ó : http://swlock.blogspot.kr/2016/11/permutation-combination-algorithm_13.html
/*
#include <stdio.h>

#define N 4
#define R 3

int selected[R];

void full(int depth)
{
	int i;
	if (R == depth) {
		// ��� ���� �Ǿ��� ����ϱ�
		for (i = 0; i<R; i++) {
			printf("%d ", selected[i]);
		}
		printf("\n");
		return;
	}
	for (i = 1; i <= N; i++) {
		selected[depth] = i;
		full(depth + 1);
	}
}

int main()
{
	full(0);
	return 0;
}
*/