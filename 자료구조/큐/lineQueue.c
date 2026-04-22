#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

typedef char element;
typedef struct QueueType {
	element queue[N];
	int front, rear;

}QueueType;

void init(QueueType* Q) {
	Q->front = Q->rear = -1;
}

int isEmpty(QueueType* Q) {
	return Q->front == Q->rear;
}

int isFull(QueueType* Q) {
	return Q->rear == N - 1;
}

void enqueue(QueueType* Q, element e) {
	if (isFull(Q)) {
		printf("Full!\n");
		return;
	}
	Q->rear++;
	Q->queue[Q->rear] = e;
}

int dequeue(QueueType* Q) {
	if (isEmpty(Q)) {
		printf("Empty!\n");
		return 0;
	}

	Q->front++;
	return Q->queue[Q->front];
}

void print(QueueType* Q) {
	printf("Front : %d, Rear : %d", Q->front, Q->rear);
	if (!isEmpty(Q)) {
		for (int i = Q->front + 1; i <= Q->rear; i++) {
			printf("[%c]", Q->queue[i]);
		}
	}
}

int main(void) {
	QueueType Q;
	init(&Q);
	srand(time(NULL));

	for (int i = 0;i < 5;i++) {
		enqueue(&Q, rand() % 26 + 65);
	}
	print(&Q);getchar();

	for (int i = 0;i < 3;i++) {
		printf("[%c]", dequeue(&Q));
	}
	printf("\n\n");
	print(&Q);getchar();

	for (int i = 0;i < 5;i++) {
		enqueue(&Q, rand() % 26 + 65); //자리가 없어서 오버플로우 dequeue를 한다고 해도 앞에 6칸이 비어있는 오른쪽 네칸이 차있음
	}

	for (int i = 0;i < 5;i++) {
		enqueue(&Q, rand() % 26 + 65); //자리가 없어서 오버플로우 dequeue를 한다고 해도 앞에 6칸이 비어있는 오른쪽 네칸이 차있음
	}
}
