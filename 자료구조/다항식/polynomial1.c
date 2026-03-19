#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 10 ///최고 차항은 9차

typedef struct polynomial {
	int degree;
	int coef[N];
}Poly;

Poly add(Poly a, Poly b) {
	Poly c;
	c.degree = (a.degree > b.degree) ? a.degree : b.degree;

	for (int i = 0;i <= c.degree;i++) {
		c.coef[i] = ((i <= a.degree) ? a.coef[i] : 0) + 
			        ((i <= b.degree) ? b.coef[i] : 0);}
	
	return c;
}

int eval(Poly p, int x) {
	int result = p.coef[0];

	for (int i = 1; i <= p.degree;i++) {
		result += p.coef[i] * pow(x, i);
	}
	return result;
}

void print(Poly p, const char* str) {
	printf("%s", str);
	for (int i = p.degree;i > 0;i--) {
		printf("%2dx^%d +", p.coef[i], i);
	}
	printf("%2d\n", p.coef[0]);
}

int main() {
	Poly a, b ,c;
	printf("차수를 입력하세요(a b) : ");
	scanf_s("%d %d", &a.degree, &b.degree);

	for (int i = a.degree;i >= 0;i--)///뒤에서부터 대입
	{
		scanf_s("%d", &a.coef[i]);
	}
	for (int i = b.degree;i >= 0;i--)
	{
		scanf_s("%d", &b.coef[i]);
	}
	print(a, "A =");
	print(b, "B =");

	c = add(a, b);

	print(c, "result =");

	return 0;
}
