#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

typedef int element;
typedef struct QueueType {
	element queue[N];
	int front, rear;

}QueueType;

void init(QueueType* Q) {
	Q->front = Q->rear = 0;
}

int isEmpty(QueueType* Q) {
	return Q->front == Q->rear;
}

int isFull(QueueType* Q) {
	return Q->front == (Q->rear + 1)%N;
}

void enqueue(QueueType* Q, element e) {
	if (isFull(Q)) {
		printf("Overflow.\n");
	}
	else {
		Q->rear = (Q->rear + 1) % N;
		Q->queue[Q->rear] = e;
	}
}

int dequeue(QueueType* Q) {
	if (isEmpty(Q)) {
		printf("Empty!\n");
		return 0;
	}

	Q->front = (Q->front + 1)%N;
	return Q->queue[Q->front];
}

int peek(QueueType* Q) {
	if (isEmpty(Q)) {
		printf("Empty!\n");
		return 0;
	}
	return Q->queue[(Q->front + 1)%N];
}

void print(QueueType* Q) {
	printf("Front : %d, Rear : %d\n", Q->front, Q->rear);
	
	if (isEmpty(&Q)) {
		printf("Queue is Empty\n");
		return;
	}

	int i = Q->front;
	while (i != Q->rear) {
		i = (i + 1) % N;
		printf("[%c]", Q->queue[i]);
	}
	printf("\n");
}

void fibonacci(int n) {
	QueueType Q;
	init(&Q);

	enqueue(&Q, 0);
	enqueue(&Q, 1);

	printf("0 1 ");
	for (int i = 2; i <= n; i++) {
		element pp = dequeue(&Q);
		element p = peek(&Q);

		element now = pp + p;
		enqueue(&Q, now);

		printf("%d ", now);
	}
	printf("\n");
}

int main(void) {
	QueueType Q;
	init(&Q);
	
	int n;
	printf("input : ");
	scanf_s("%d", &n);
	fibonacci(n);

} 
