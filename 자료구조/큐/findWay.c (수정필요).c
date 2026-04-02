#include <stdio.h>
#include <stdlib.h>
#define N 6

char map[N][N] = { /*0은 길 1은 벽 x는 출구*/
	{'1','1','1','1','1','1'},
	{'0','0','0','0','0','1'},
	{'1','0','1','0','0','1'},
	{'1','1','1','0','0','x'},
	{'1','1','1','0','0','1'},
	{'1','1','1','1','1','1'}
};

typedef struct {/*좌표 구조체*/
	int r, c;
}Coor;

typedef Coor element; /*이렇게 해놓으면 나중에 스택 종류를 쉽게 바꿀 수 있다.*/ /*스택 안에서만 써야함*/
typedef struct {
	element stack[N];
	int top;
}StackType;

void init(StackType* S) {/*주소는 포인터 변수로 받는다 (정의할때는 *S 넣는값은 주소)*/
	S->top = -1;
};

void print(StackType* S) {
	for (int i = S->top; i >= 0; i--) {
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

void insertPos(StackType* S, int r, int c) {//길 위에 놓기
	if (r < 0 || c < 0 || r >= N || c >= N) //미로 밖
		return;
	if (map[r][c] != '0' && map[r][c] != 'x') //길에 놓아야함
		return;

	element pos = { r, c };
	push(S, pos);
}

void print(StackType* S) {
	printf("[ ");
	for (int i = S->top; i >= 0; i--)
		printf("(%d %d)", S->stack[i].r, S->stack[i].c);
	printf(" ]");
}

void printMaze(element e) {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; r++) {
			if (e.r == r && e.c == c)
				printf(" @ ");
			else
				printf(" %c ", map[r][c]);
			printf("\n");
		}
	}
}

int main() {
	StackType S;
	init(&S); /*초기화*/
	int order = 1; /*출력할 때 보기좋게*/

	insertPos(&S, 1, 0);
	whlie(!isEmpty(&S))
	{
		element e = pop(&S);
		int r = e.r;
		int c = e.c;
		printf("%2d. (%d %d) : ", order++, r, c);

		if (map[r][c] == 'x') {
			printf("Success\n");
			break;
		}
		else {
			map[r][c] = '.';
			insertPos(&S, r - 1, c); //스택에 상하좌우 값 넣기
			insertPos(&S, r + 1, c);
			insertPos(&S, r, c-1);
			insertPos(&S, r, c+1);
		}
		printf()
	};
	return 0;
}
