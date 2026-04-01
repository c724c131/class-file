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

int prec(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return 0;
}

void infixToPostfix(char expr[], char result[]) {//중위수식을 후위수식으로
	StackType S; 
	init(&S); //스택 초기화
	StackType NS;
	init(&NS); //숫자용 스택

	char c, op = '0';
	int n = strlen(expr);
	int idx = 0;

	for (int i = 0; i < n; i++) {
		c = expr[i];

		if (isalnum(c)) //피연산자면 N스택에 넣기
			push(&NS, c);

		else if (c == '(') {//정상적인 입력에서 '(' 앞에 숫자가 그냥 있는 상황은 없으니 이것만
			push(&S, c);
		}

		else if (c == ')') {

			if (!isEmpty(&NS) && NS.top == 0) {//후위수식만드는 함수를 재호출 하기 위해 1자리 수식은 그냥 작동,Empty 검사 안했더니 오류
				result[idx++] = pop(&NS);
			}
			else if (!isEmpty(&NS)){
				char temp[N];
				int temp_idx = 0;
				int degree = 0; //N스택에서 하나씩 뺄 때 마다 차수 +

				while (!isEmpty(&NS)) {//스택에서 숫자 다 뽑기
					temp[temp_idx++] = pop(&NS);
					for (int i = 0; i < degree; i++) {//차수 만큼 10 곱하기 (10도 2자리니까 *2*5 로 변환)
						temp[temp_idx++] = '*';
						temp[temp_idx++] = '2';
						temp[temp_idx++] = '*';
						temp[temp_idx++] = '5';
					}
					temp[temp_idx++] = '+'; //숫자 바꿀 때 마다 + 붙이기
					degree++;
				}

				if (temp_idx > 0 && temp[temp_idx - 1] == '+')//숫자 다 나왔으면 마지막 + 때고 NULL 붙이기
					temp_idx--;
				temp[temp_idx] = '\0';

				char temp_result[N];
				infixToPostfix(temp, temp_result); //후위 수식으로 바꾸기, 한자리 연산밖에 없기때문에 가능

				for (int j = 0; temp_result[j] != '\0'; j++) {
					result[idx++] = temp_result[j];  // result 뒤에 붙이기 (숫자 하나를 식으로 바꿨으니 그냥 붙이면 맞는 연산)
				}
			}

			op = pop(&S);//스택에서 꺼내기
			while (op != '(') {// 중위수식을 정상적으로 넣었다면 '(' 만날때까지 반복
				result[idx++] = op;
				// '(' 아닌 것은 바로 출력, 스택에 들어 올때 연산 우선순위를 맞춰 들어오기때문에 순서가 맞는다.
				op = pop(&S);
			}
		}

		else if (strchr("+-*/", c)) {//strchr : 문자 검색 "+-*/" 에서 c 찾기

			//피연산자를 안 만나면 N스택 풀기 위와 동일한 연산
			if (!isEmpty(&NS) && NS.top == 0) {//후위수식만드는 함수를 재호출 하기 위해 1자리 수식은 그냥 작동,Empty 검사 안했더니 오류
				result[idx++] = pop(&NS);
			}
			else if (!isEmpty(&NS)) {
				char temp[N];
				int temp_idx = 0;
				int degree = 0; //N스택에서 하나씩 뺄 때 마다 차수 +

				while (!isEmpty(&NS)) {//스택에서 숫자 다 뽑기
					temp[temp_idx++] = pop(&NS);
					for (int i = 0; i < degree; i++) {//차수 만큼 10 곱하기 (10도 2자리니까 *2*5 로 변환)
						temp[temp_idx++] = '*';
						temp[temp_idx++] = '2';
						temp[temp_idx++] = '*';
						temp[temp_idx++] = '5';
					}
					temp[temp_idx++] = '+'; //숫자 바꿀 때 마다 + 붙이기
					degree++;
				}

				if (temp_idx > 0 && temp[temp_idx - 1] == '+')//숫자 다 나왔으면 마지막 + 때고 NULL 붙이기
					temp_idx--;
				temp[temp_idx] = '\0';

				char temp_result[N];
				infixToPostfix(temp, temp_result); //후위 수식으로 바꾸기, 한자리 연산밖에 없기때문에 가능

				for (int j = 0; temp_result[j] != '\0'; j++) {
					result[idx++] = temp_result[j];  // result 뒤에 붙이기 (숫자 하나를 식으로 바꿨으니 그냥 붙이면 맞는 연산)
				}
			}

			while (!isEmpty(&S)) {//빈 스택 확인
				op = peek(&S);
				if (prec(c) <= prec(op)) {
					result[idx++] = pop(&S);//연산 우선 순위가 높으면 먼저 계산 -> 먼저 출력
				}
				else
					break;
			}
			push(&S, c);
		}
	}

	if (!isEmpty(&NS) && NS.top == 0) {//후위수식만드는 함수를 재호출 하기 위해 1자리 수식은 그냥 작동,Empty 검사 안했더니 오류
		result[idx++] = pop(&NS);
	}
	else if (!isEmpty(&NS)) {
		char temp[N];
		int temp_idx = 0;
		int degree = 0; //N스택에서 하나씩 뺄 때 마다 차수 +

		while (!isEmpty(&NS)) {//스택에서 숫자 다 뽑기
			temp[temp_idx++] = pop(&NS);
			for (int i = 0; i < degree; i++) {//차수 만큼 10 곱하기 (10도 2자리니까 *2*5 로 변환)
				temp[temp_idx++] = '*';
				temp[temp_idx++] = '2';
				temp[temp_idx++] = '*';
				temp[temp_idx++] = '5';
			}
			temp[temp_idx++] = '+'; //숫자 바꿀 때 마다 + 붙이기
			degree++;
		}

		if (temp_idx > 0 && temp[temp_idx - 1] == '+')//숫자 다 나왔으면 마지막 + 때고 NULL 붙이기
			temp_idx--;
		temp[temp_idx] = '\0';

		char temp_result[N];
		infixToPostfix(temp, temp_result); //후위 수식으로 바꾸기, 한자리 연산밖에 없기때문에 가능

		for (int j = 0; temp_result[j] != '\0'; j++) {
			result[idx++] = temp_result[j];  // result 뒤에 붙이기 (숫자 하나를 식으로 바꿨으니 그냥 붙이면 맞는 연산)
		}
	}

	while (!isEmpty(&S)) { //스택에 남은 것을 다 출력하면 연산 순서가 맞게됨
		result[idx++] = pop(&S);;
	}
	result[idx] = '\0'; //마지막에 NULL 붙여야 문자열 끝으로 인식
}

int evaluate(char str[]) {//후위 수식 연산 함수
	StackType S;
	init(&S);

	int op1, op2, num;
	int n = strlen(str);
	char c;

	for (int i = 0; i < n; i++) {
		c = str[i];
		if (isdigit(c)) {
			num = c - '0'; //아스키값을 빼서 문자를 숫자로 만들기
			push(&S, num);
		}
		else if (strchr("+-*/", c)) {//연산자 만나면 피연산자 두개 가져오기
			op2 = pop(&S);
			op1 = pop(&S);

			switch (c) {//연산자를 찾아 그 계산 하기
			case '+':push(&S, op1 + op2); break;
			case '-':push(&S, op1 - op2); break;
			case '*':push(&S, op1 * op2); break;
			case '/':push(&S, op1 / op2); break;
			}
		}
	}
	return pop(&S);
};

int main() {
	char str[N];
	char result[10*N]; //혹시 몰라 메모리 할당 크게

	printf("중위 수식을 입력 : ");
	fgets(str, N, stdin); //키보드(stdin)에서 N-1개를 읽어 저장 (마지막\0)

	infixToPostfix(str,result);
	printf("후위 수식 : %s\n", result);
	printf("계산 결과 : %d\n", evaluate(result));

	return 0;
}

///전역변수로 스텍을 만들면 한 개밖에 못씀 그리고 전역변수로 중요한 데이터를 다루는 건 좋지 않음
