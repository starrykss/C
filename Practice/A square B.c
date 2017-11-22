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

// double : 포맷 형식 : %lf, 크기 : 8 Byte
// float : 포멧 형식 : %f, 크기 : 4 Byte
*/