/*
#include <stdio.h>

int main()
{
	double a, b;
	double square;

	while (1) {
		scanf("%lf", &a);
		scanf("%lf", &b);
		if ((a <= 0) || (a >= 10) || (b <= 0) || (b >= 10)) {
			return 0;
		}
		else {
			square = (float)a / b;  // type conversion
			printf("%.9lf", square);
			break;
		} // end of else
	} // end of infinite loop

	return 0;
}

// double : ���� ���� : %lf, ũ�� : 8 Byte
// float : ���� ���� : %f, ũ�� : 4 Byte
*/