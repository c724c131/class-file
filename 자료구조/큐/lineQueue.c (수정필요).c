#include <stdio.h>
#include <stdlib.h>

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

}

void dequeue(QueueType* Q) {
	if (isEmpty(Q)) {
		printf("Empty!\n");
		return 0;
	}

	Q->front++;
	return Q->queue[Q->front];
}

void print(QueueType* Q) {
	if (!isEmpty(Q)) {
		for (int i = Q->front + 1; i <= Q->rear; i++) {
			printf("[%c]", Q->queue[i]);
		}
	}
}
