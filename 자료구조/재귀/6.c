/*유클리드 호제법*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* a >= b가 조건*/

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gdc(b, a % b);
}

int main() {
	int a;
	int b;
	scanf_s("%d %d", &a, &b);
	
	return 0;
}
