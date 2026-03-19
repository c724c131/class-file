#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 10

typedef struct Term {
	float coef;
	int expon;
}Term;

typedef struct polynomial {
	int nTerms;
	Term terms[N];
}Poly;

Poly makePoly() {
	Poly p;
	printf("다항식의 항의 수 입력 : ");
	scanf_s("%d", &p.nTerms);

	printf("고차항부터 항의 계수와 지수 입력\n");
	for (int i = 0;i < p.nTerms;i++) {
		printf("%d번 입력 : ", i + 1);
		scanf_s("%f %d", &p.terms[i].coef, &p.terms[i].expon);
	}

	return p;
}

Poly add(Poly a, Poly b) {
	Poly p;
	p.nTerms = 0;
	
	for (int i = 0, j = 0;i < a.nTerms || j < b.nTerms;) {

		if (i == a.nTerms || a.terms[i].expon < b.terms[j].expon)
			p.terms[p.nTerms++] = b.terms[j++];

		else if(i == b.nTerms || b.terms[i].expon < a.terms[j].expon)
			p.terms[p.nTerms++] = a.terms[i++];

		else {
			float coef = a.terms[i++].coef + b.terms[j++].coef;
			if (coef != 0) {
				p.terms[p.nTerms].coef = coef;
				p.terms[p.nTerms].expon = a.terms[i].expon;
				p.nTerms++;
			}
			i++;
			j++;
		};
	}
	return p;
}

void print(Poly p, const char* str) {
	printf("%s", str);
	for (int i = 0;i < p.nTerms;i++) {
		printf("%.1f x^%d +", p.terms[i].coef, p.terms[i].expon);
	}
	printf("\b\b         \n");
}

int main() {
	Poly a = makePoly();
	Poly b = makePoly();

	print(a, "A = ");
	print(b, "B = ");

	Poly c = add(a, b);
	printf("-----------------------------\n");
	print(c, "C = ");

	return 0;
}
