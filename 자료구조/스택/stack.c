#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef char element; /*이렇게 해놓으면 나중에 스택 종류를 쉽게 바꿀 수 있다.*/ /*스택 안에서만 써야함*/

typedef struct {
	element stack[N];
	int top;
}StackType;

void init(StackType *S) {/*주소는 포인터 변수로 받는다 (정의할때는 *S 넣는값은 주소)*/
	S->top = -1;
};

void print(StackType* S) {
	for (int i = S->top; i >= 0;i--) {
		printf("|   %c   |\n",S->stack[i]);
		printf("---------\n");
	}
};

int isEmpty(StackType* S) {
	return S->top == -1;
};

int isFull(StackType* S) {
	return S->top == N - 1;
};

void push(StackType* S,element e) {
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

int main() {
	StackType S;
	init(&S); /*주소로 전달할 것*/
	push(&S, 'A');
	push(&S, 'B');
	push(&S, 'C');
	push(&S, 'D');
	print(&S);

	return 0;
}
