/*
#include <stdio.h>

int main(void)
{
	int n;
	
	while (1) {
		scanf("%d", &n);
		if ((n < 1) || (n > 100)) {
			return 0;
		}
		else {
			for (int i = n; i > 0; i--) {
				for (int k = i; k > 1; k--) {
					printf(" ");
				}
				for (int j = n; j > i - 1 ; j--) {
					printf("*");
				}
				printf("\n");
			}
			break;
		}	// end of else
	} // end of while
	return 0;
}
*/