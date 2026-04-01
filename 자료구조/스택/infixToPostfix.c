#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 100	

typedef int element; //이렇게 해놓으면 나중에 스택 종류를 쉽게 바꿀 수 있다. *스택 안에서만 써야함

typedef struct {
	element stack[N];
	int top;
}StackType;

void init(StackType* S) {//주소는 포인터 변수로 받는다 (포인터 정의할때는 *S 넣는값은 주소)
	S->top = -1;
};

void print(StackType* S) {
	for (int i = S->top; i >= 0; i--) {//맨 위부터 한 칸씩 출력
		printf("|   %c   |\n", S->stack[i]);
		printf("---------\n");
	}
};

int isEmpty(StackType* S) {
	return S->top == -1; //스택이 비면 top = -1
};

int isFull(StackType* S) {
	return S->top == N - 1; //스택 크기의 -1
};

void push(StackType* S, element e) {
	if (isFull(S))
		printf("Overflow\n");
	else {
		S->top++; //top 한 칸 올리고
		S->stack[S->top] = e; //값 삽입
	}
};

element pop(StackType* S) {
	if (isEmpty(S)) {
		printf("Empty!\n");
		return -1;
	}
	element e = S->stack[S->top]; //값을 빼고 나서
	S->top--; //top 한 칸 아래로
	return e;
}

element peek(StackType* S) {
	if (isEmpty(S)) {
		printf("Empty!\n");
		return -1;
	}
	return S->stack[S->top]; //top값
}

int prec(char op) {//일단 연산 우선 순위 그대로 입력, 단항연산자 +와 -는 어떻게 해야할까?
	if (op == '|') return 1;
	if (op == '&') return 2;
	if (op == '<' || op == '>') return 3;
	if (op == '+' || op == '-') return 4;
	if (op == '*' || op == '/') return 5;
	if (op == '!' || op == '~' || op == '#') return 6;
	//단항 연산자 -는 ~로 +는 #로 대체 마지막까지 단항연산자 구분 방법이 생각안나면 이걸 사용
	return 0;//괄호는 우선 순위 0
}

void infixToPostfix(char expr[]) {//중위수식을 후위수식으로
	StackType S;
	init(&S); //스택 초기화

	char c, op;
	int n = strlen(expr);

	for (int i = 0; i < n; i++) {
		c = expr[i];

		if (isalnum(c)) //피연산자면 그냥 출력
			printf("%c", c);

		else if (c == '(') // '(' 면 스택에
			push(&S, c);

		else if (c == ')') {
			op = pop(&S);//스택에서 꺼내기
			while (op != '(') {// 중위수식을 정상적으로 넣었다면 '(' 만날때까지 반복
				printf("%c", op);
				// '(' 아닌 것은 바로 출력, 스택에 들어 올때 연산 우선순위를 맞춰 들어오기때문에 순서가 맞는다.
				op = pop(&S);
			}
		}

		else if (strchr("+-*/<>|&!~#", c)) {//strchr : 문자 검색 "+-*/" 에서 c 찾기 + 다른 연산자들 추가
			if (c == '&' || c == '|')
				i++; //&&와 ||는 두 글자니까 문자열 한 칸 더 진행
			while (!isEmpty(&S)) {//빈 스택 확인
				op = peek(&S);
				if (prec(c) <= prec(op)) {
					if (op == '&' || op == '|') {
						printf("%c", op);
					}//&&와 ||은 한글자씩 더 출력
					printf("%c", pop(&S));//연산 우선 순위가 높으면 먼저 계산 -> 먼저 출력
				}
				else
					break;
			}
			push(&S, c);
		}
	}
	while (!isEmpty(&S)) { //스택에 남은 것을 다 출력하면 연산 순서가 맞게됨
		char ch = pop(&S);
		if (ch == '&' || ch == '|') //&&나 ||는 두개 출력
			printf("%c", ch);
		printf("%c", ch);
	}
	printf("\n");
}

int main() {
	int cnt;
	printf("수식의 수 : ");
	scanf_s("%d", &cnt);
	getchar();//입력 버퍼 제거
	for (int i = 0; i < cnt; i++) {
		char str[N];
		printf("Input : ");
		/*입력조건: 단항 연산자는 중복해서 입력하지 않는다.
					중위수식 입력시 괄호와 연산자, 피연산자를 정확히 입력 해야한다.
					단항 연산자 '-'는 '~'로 '+'는 '#'으로 입력한다.*/
		fgets(str, N, stdin); //키보드(stdin)에서 N-1개를 읽어 저장 (마지막\0)
		infixToPostfix(str);
	};

	return 0;
}

///전역변수로 스텍을 만들면 한 개밖에 못씀 그리고 전역변수로 중요한 데이터를 다루는 건 좋지 않음
