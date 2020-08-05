#include <stdio.h>

// 순환적 구현
int factorial(int n) {
  if (n == 1) return 1;                // n == 1인 경우 (종료 조건)
  else return (n * factorial(n - 1));  // n > 1인 경우 (순환 호출)
}

// 반복적 구현
int factorial_iter(int n) {
  int result = 1;
  for (int k = n; k > 0; k--) {
    result = result * k;
  }
  return result;
}

void main() {
    int num, rNum, iNum;
    
    printf("Input Number : ");
    scanf("%d", &num);

    rNum = factorial(num);
    iNum = factorial_iter(num);

    printf("Value of %d factorial with Recursion : %d\n", num, rNum);
    printf("Value of %d factorial with Iteration : %d\n", num, iNum);
}