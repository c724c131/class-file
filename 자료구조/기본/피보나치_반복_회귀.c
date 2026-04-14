#include <stdio.h>
#include <stdlib.h>

int cnt;

int fibo(int n)
{
	cnt++;
	if (n == 0) return 0;
	if (n == 1) return 1;
	return (fibo(n - 1) + fibo(n - 2));
}/*50정도만 되어도 멈춤*/

int fibo_iter(int n) {

	if (n == 0) return 0;
	if (n == 1) return 1;

	int pp = 0;
	int p = 1;
	int result = 0;

	for (int i = 2;i <= n; i++) {
		result = p + pp;
		pp = p;
		p = result;
	}
	return result;
}

int main() {
	printf("fibo : %d count : %d\n", fibo(20),cnt);/*1.628의 n제곱 대충 2^n*/
	printf("iter : %d\n", fibo_iter(10));
	return 0;
}
