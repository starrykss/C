// ���� 2839��
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
			if (n % 5 != 0) {	// n�� 5�� �������� �ʴ� ��� -> n�� 5�� ���� ����.
				num1 = n / pb2; // n�� 5�� ����. 3
				num2 = (n - (pb2 * num1));		//  n - (num1*5).  3

				if (num2 % pb1 != 0) {  // num2�� 3���� �������� ���� ���
					if (n % pb1 == 0) {	// n�� 3���� ������ ���
						printf("%d", n / pb1);		// n / 3 ���
						break;
					}
					else {	// n�� 3���� �������� ���� ���
						printf("-1\n");		// -1 ���
						return 0;
					}
				}
				else {	// num2�� 3���� ������ ���
					num3 = num2 / pb1;		// 3 / 3 = 1
					printf("%d\n", num1 + num3);		// 1 + 3 = 4
					break;
				}
			}

			else { // n�� 5�� �������� ��� -> n�� 5�� ����.
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
            if ((n % pb1 != 0) && (n % pb2 != 0)) {    // 3�Ǵ� 5�� ��� ���������� �ʴ� ���
                printf("-1");   // -1 ���
                break;
            }
            else if ((n % pb1 == 0) && (n % pb2 != 0)) {  // n�� 3���θ� ������ ���
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
            else if ((n % pb1 != 0) && (n % pb2 == 0)) {  // n�� 5�θ� ������ ���
                printf("%d", n / pb2);
                break;
            }
            else {  // n�� 3�� 5�� ��� ������ ���
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