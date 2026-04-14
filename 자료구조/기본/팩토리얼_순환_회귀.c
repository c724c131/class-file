#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
	if (n <= 1) return 1;
	else return(n * factorial(n - 1));
}

int factorial_iter(int n)
{
	int k, v = 1;
	for (k = n; k > 0; k--)
		v = v * k;
	return(v);
}

int main() {
	int num;
	printf("숫자를 입력하시오 : ");
	scanf_s("%d", &num);
	printf("%d", factorial(num));
	return 0;
}
