#include <stdio.h>
#include <stdlib.h>

#define N 6

char map[N][N] = {
    {'1','1','1','1','1','1'},
    {'0','0','0','0','0','1'},
    {'1','0','1','0','0','1'},
    {'1','1','1','0','0','x'},
    {'1','1','1','0','0','1'},
    {'1','1','1','1','1','1'}
};

typedef struct {
    int r;
    int c;
} Coor;

typedef Coor element;

typedef struct {
    element stack[N * N];
    int top;
} StackType;

void init(StackType* S) {
    S->top = -1;
}

int isEmpty(StackType* S) {
    return S->top == -1;
}

int isFull(StackType* S) {
    return S->top == N * N - 1;
}

void push(StackType* S, element e) {
    if (isFull(S)) {
        printf("Overflow\n");
    }
    else {
        S->top++;
        S->stack[S->top] = e;
    }
}

element pop(StackType* S) {
    if (isEmpty(S)) {
        printf("Empty!\n");
        element error = { -1, -1 };
        return error;
    }

    element e = S->stack[S->top];
    S->top--;
    return e;
}

element peek(StackType* S) {
    if (isEmpty(S)) {
        printf("Empty!\n");
        element error = { -1, -1 };
        return error;
    }

    return S->stack[S->top];
}

void insertPos(StackType* S, int r, int c) {
    if (r < 0 || c < 0 || r >= N || c >= N)
        return;

    if (map[r][c] != '0' && map[r][c] != 'x')
        return;

    element pos = { r, c };
    push(S, pos);
}

void printStack(StackType* S) {
    printf("[ ");
    for (int i = S->top; i >= 0; i--) {
        printf("(%d %d) ", S->stack[i].r, S->stack[i].c);
    }
    printf("]");
}

void printMaze(element e) {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (e.r == r && e.c == c)
                printf(" @ ");
            else
                printf(" %c ", map[r][c]);
        }
        printf("\n");
    }
}

int main(void) {
    StackType S;
    init(&S);

    int order = 1;

    insertPos(&S, 1, 0);

    while (!isEmpty(&S)) {
        element e = pop(&S);
        int r = e.r;
        int c = e.c;

        printf("%2d. (%d %d)\n", order++, r, c);
        printMaze(e);
        printf("\n");

        if (map[r][c] == 'x') {
            printf("Success\n");
            break;
        }
        else {
            map[r][c] = '.';

            insertPos(&S, r - 1, c);
            insertPos(&S, r + 1, c);
            insertPos(&S, r, c - 1);
            insertPos(&S, r, c + 1);
        }

        printStack(&S);
        printf("\n\n");

        getchar();
    }

    return 0;
}
