/*
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int main() {
	int arr[SIZE] = { 0 };
	int tmp = 0;

	printf("���� ��:");

	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 101;
		printf("%d ", arr[i]);
	}
	printf("\n ���� ��:");

	for (int i = 0; i < 10; i++) {
		for (int j = i; j < 10; j++) {
			if (arr[i] < arr[j]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
		printf("%d ", arr[i]);
	}

	return 0;
}
*/