// 여러 개의 동물 이름을 입출력하는 프로그램
// 각 행은 하나의 1차원 char 배열이며 부분배열명이 각 행의 배열명의 기능을 함.
/*
#include <stdio.h>

int main(void) {
	char animal[5][20];
	int i;
	int count;

	count = sizeof(animal) / sizeof(animal[0]);		// 행의 수 계산
	for (i = 0; i < count; i++) {
		scanf("%s", animal[i]);
	}

	for (i = 0; i < count; i++) {
		printf("%s ", animal[i]);
	}
	
	return 0;
}
*/