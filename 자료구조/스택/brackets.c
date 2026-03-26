#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50

typedef char element; /*이렇게 해놓으면 나중에 스택 종류를 쉽게 바꿀 수 있다.*/ /*스택 안에서만 써야함*/

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

int check_matching(char str[]) {
	StackType S;
	init(&S);

	char ch_str, ch_stack;
	int n = strlen(str);///이렇게 하면 for문으로 돌리기 NULL 만날때까지 while문도 가능

	for (int i = 0; i < n;i++) {
		ch_str = str[i];

		if (ch_str == '(' || ch_str == '{' || ch_str == '[')
			push(&S, ch_str);
		else if (ch_str == ')' || ch_str == '}' || ch_str == ']') {
			if (isEmpty(&S))
				return 2;

			else {
				ch_stack = pop(&S);
				if ((ch_stack == '(' && ch_str != ')')
					|| (ch_stack == '{' && ch_str != '}')
					|| (ch_stack == '[' && ch_str != ']'))
					return 3;
			};
		};
	};
	if (isEmpty(&S) != 1)
		return 1;

	return 0; ///성공
};

int main() {
	char str[N];

	printf("Input : ");
	fgets(str, N, stdin);

	int result = check_matching(str);

	if (result == 0)
		printf("Check Passed,\n");
	else
		printf("Check Failed. Condition %d\n", result);

	return 0;
}

///전역변수로 스텍을 만들면 한 개밖에 못씀 그리고 전역변수로 중요한 데이터를 다루는 건 좋지 않음
