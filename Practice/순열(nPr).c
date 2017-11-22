// 내용 출처 : http://swlock.blogspot.kr/2016/03/permutation-algorithm.html
/*
#include <stdio.h>

int data[] = { 1,2,3,4 };
int R = 3;

int swap(int i, int j)
{
	int temp;
	if (i == j) return 0;
	temp = data[i];
	data[i] = data[j];
	data[j] = temp;
	return 0;
}

int Permutation(int n, int r, int depth)
{
	int i;

	if (r == depth) {
		for (i = 0; i<R; i++) {
			printf("%d ", data[i]);
		}
		printf("\n");
		return 0;
	}

	for (i = depth; i<n; i++) {
		swap(i, depth);
		Permutation(n, r, depth + 1);
		swap(i, depth);
	}
	return 0;
}

int main()
{
	int N = sizeof(data) / sizeof(int);
	Permutation(N, R, 0);
	return 0;
}
*/