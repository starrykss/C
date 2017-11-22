// 백준 2839번
/*
#include <stdio.h>

int main()
{
	int n;

	while (1) {
		scanf("%d", &n);

		if ((n < 3) || (n > 5000)) {
			return 0;
		}
		else {
			if (n == 4 || n == 7) {
				printf("-1");
				return 0;
			}
			else if (n % 5 == 0) {
				printf("%d", n / 5);
				break;
			}
			else if (n % 5 % 2 == 1) {
				printf("%d", n / 5 + 1);
				break;
			}
			else {
				printf("%d", n / 5 + 2);
				break;
			}
		}
	}

	return 0;
}
*/
/*
#include <stdio.h>

int main()
{
	int pb1 = 3, pb2 = 5;   // pb1 : 3kg, pb2 : 5kg     3x+5y=18
	int n;
	int num1, num2, num3, num4;

	while (1) {
		scanf("%d", &n);

		if ((n < 3) || (n > 5000)) {
			return 0;
		}
		else { 
			if (n % 5 != 0) {	// n이 5로 나눠지지 않는 경우 -> n을 5로 먼저 나눔.
				num1 = n / pb2; // n을 5로 나눔. 3
				num2 = (n - (pb2 * num1));		//  n - (num1*5).  3

				if (num2 % pb1 != 0) {  // num2가 3으로 나눠지지 않을 경우
					if (n % pb1 == 0) {	// n이 3으로 나눠질 경우
						printf("%d", n / pb1);		// n / 3 출력
						break;
					}
					else {	// n이 3으로 나눠지지 않을 경우
						printf("-1\n");		// -1 출력
						return 0;
					}
				}
				else {	// num2가 3으로 나눠질 경우
					num3 = num2 / pb1;		// 3 / 3 = 1
					printf("%d\n", num1 + num3);		// 1 + 3 = 4
					break;
				}
			}

			else { // n이 5로 나눠지는 경우 -> n을 5로 나눔.
				num4 = n / pb2;
				printf("%d\n", num4);
				break;
			}
		}
	}

	return 0;
}
*/
/*
#include <stdio.h>

int main() 
{
    int pb1 = 3, pb2 = 5;   // pb1 : 3kg, pb2 : 5kg     3x+5y=18
    int n;
    int num1, num2, num3;

    while(1) {
        scanf("%d", &n);
        
        if((n < 3) || (n > 5000)) {
            return 0;
        }
        else {
            if ((n % pb1 != 0) && (n % pb2 != 0)) {    // 3또는 5로 모두 나누어지지 않는 경우
                printf("-1");   // -1 출력
                break;
            }
            else if ((n % pb1 == 0) && (n % pb2 != 0)) {  // n이 3으로만 나눠질 경우
				num1 = n / pb2;
				num2 = (n - (pb2 * num1));
				if (num2 % pb1 != 0) {
					return 0;
				}
				else {
					num3 = (n - (pb2 * num1)) / pb1;
					printf("%d", num1 + num3);
					break;
				}
            }
            else if ((n % pb1 != 0) && (n % pb2 == 0)) {  // n이 5로만 나눠질 경우
                printf("%d", n / pb2);
                break;
            }
            else {  // n이 3과 5로 모두 나눠질 경우
				num1 = n / pb2;
				num2 = (n - (pb2 * num1)) / pb1; 
                printf("%d", num1 + num2);
                break;
            }
         }
    }
    
    return 0;
}
*/