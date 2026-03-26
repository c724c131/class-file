#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 50

typedef int element; /*이렇게 해놓으면 나중에 스택 종류를 쉽게 바꿀 수 있다.*/ /*스택 안에서만 써야함*/

typedef struct {
	element stack[N];
	int top;
}StackType;

void init(StackType* S) {/*주소는 포인터 변수로 받는다 (정의할때는 *S 넣는값은 주소)*/
	S->top = -1;
};

void print(StackType* S) {
	for (int i = S->top; i >= 0;i--) {
		printf("|   %c   |\n", S->stack[i]);
		printf("---------\n");
	}
};

int isEmpty(StackType* S) {
	return S->top == -1;
};

int isFull(StackType* S) {
	return S->top == N - 1;
};

void push(StackType* S, element e) {
	if (isFull(S))
		printf("Overflow\n");
	else {
		S->top++;
		S->stack[S->top] = e;
	}
};

element pop(StackType* S) {
	if (isEmpty(S)) {
		printf("Empty!\n");
		return -1;
	}
	element e = S->stack[S->top];
	S->top--;
	return e;
}

element peek(StackType* S) {
	if (isEmpty(S)) {
		printf("Empty!\n");
		return -1;
	}
	return S->stack[S->top];
}

int evaluate(char str[]) {///일단은 한자리 연산 숙제 : 여러자리 연산 만들기
	StackType S;
	init(&S);

	int op1, op2, num;
	int n = strlen(str);
	char c;

	for (int i = 0;i < n;i++) {
		c = str[i];
		if (isdigit(c)) {
			num = c - '0';
			push(&S, num);
		}
		else if (strchr("+-*/", c)) {
			op2 = pop(&S);
			op1 = pop(&S);

			switch (c) {
				case '+':push(&S, op1 + op2);break;
				case '-':push(&S, op1 - op2);break;
				case '*':push(&S, op1 * op2);break;
				case '/':push(&S, op1 / op2);break;
			}
		}
	}
	return pop(&S);
};

int prec(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return 0;
}

void infixToPostfix(char expr[]) {
	StackType S;
	init(&S);

	char c, op;
	int n = strlen(expr);

	for (int i = 0;i < n;i++) {
		c = expr[i];

		if (isdigit(c))
			printf("%c ", c);
		else if (c == '(')
			push(&S, c);
		else if (c == ')') {
			while (op != '(') {
				printf("%c ", op);
				op = pop(&S);
			}
		}
		else if (strchr("+-*/", c)) {
			while (!isEmpty(&S)) {
				op = peek(&S);
				if (prec(c) <= prec(op))
					printf("%c ", pop(&S));
				else
					break;
			}
			push(&S, c);
		}
	}
	while (!isEmpty(&S)) {
		printf("%c", pop(&S));
	}
	printf("\n");
}

int main() {
	char str[N];
	printf("Input : ");
	fgets(str, N, stdin);

	infixToPostfix(str);
	//printf("%d", evaluate(str));


	return 0;
}

///전역변수로 스텍을 만들면 한 개밖에 못씀 그리고 전역변수로 중요한 데이터를 다루는 건 좋지 않음
