#include <stdio.h>
#include <stdlib.h>

#define N 6
#define Q_SIZE (N * N + 1)

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
    element queue[Q_SIZE];
    int front;
    int rear;
} QueueType;

void init(QueueType* Q) {
    Q->front = Q->rear = 0;
}

int isEmpty(QueueType* Q) {
    return Q->front == Q->rear;
}

int isFull(QueueType* Q) {
    return Q->front == (Q->rear + 1) % Q_SIZE;
}

void enqueue(QueueType* Q, element e) {
    if (isFull(Q)) {
        printf("Overflow\n");
    }
    else {
        Q->rear = (Q->rear + 1) % Q_SIZE;
        Q->queue[Q->rear] = e;
    }
}

element dequeue(QueueType* Q) {
    if (isEmpty(Q)) {
        printf("Empty!\n");
        element error = { -1, -1 };
        return error;
    }

    Q->front = (Q->front + 1) % Q_SIZE;
    return Q->queue[Q->front];
}

element peek(QueueType* Q) {
    if (isEmpty(Q)) {
        printf("Empty!\n");
        element error = { -1, -1 };
        return error;
    }

    return Q->queue[(Q->front + 1) % Q_SIZE];
}

void insertPos(QueueType* Q, int r, int c) {
    if (r < 0 || c < 0 || r >= N || c >= N)
        return;

    if (map[r][c] != '0' && map[r][c] != 'x')
        return;

    element pos = { r, c };
    enqueue(Q, pos);
}

void printQueue(QueueType* Q) {
    printf("[ ");

    int i = Q->front;
    while (i != Q->rear) {
        i = (i + 1) % Q_SIZE;
        printf("(%d %d) ", Q->queue[i].r, Q->queue[i].c);
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
    QueueType Q;
    init(&Q);

    int order = 1;

    insertPos(&Q, 1, 0);

    while (!isEmpty(&Q)) {
        element e = dequeue(&Q);
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

            insertPos(&Q, r - 1, c);
            insertPos(&Q, r + 1, c);
            insertPos(&Q, r, c - 1);
            insertPos(&Q, r, c + 1);
        }

        printQueue(&Q);
        printf("\n\n");

        getchar();
    }

    return 0;
}
