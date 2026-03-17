/*양의 정수를 입력 받아, 각 자리의 수를 높은 자릿수부터 차례로 출력하는 프로그램을 작성하시오.*/
#include <stdio.h>
#include <math.h>

void high(int n) {
	if (n < 10) {
		printf("%d ", n);
		return;
	}

	int a = 0;
	while ((int)pow(10, a + 1) <= n) {
		a++;
	};

	int div = (int)pow(10, a);
	printf("%d\n", n / div);
	return high(n % div);
}

int main() {
	int n;
	scanf_s("%d", &n);
	high(n);
	return 0;
}
