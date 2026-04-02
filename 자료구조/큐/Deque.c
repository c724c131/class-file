#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

typedef char element;
typedef struct DequeType {
	element deque[N];
	int front, rear;

}DequeType;

void init(DequeType* D) {
	D->front = D->rear = 0;
}

int isEmpty(DequeType* D) {
	return D->front == D->rear;
}

int isFull(DequeType* D) {
	return D->front == (D->rear + 1) % N;
}

void addFront(DequeType* D, element e) {
	if (isFull(D)) {
		printf("Overflow");
	}
	else {
		D->deque[D->front] = e;
		D->front = (D->front - 1 + N) % N;
	}
}

void addRear(DequeType* D, element e) {
	if (isFull(D)) {
		printf("Overflow.\n");
	}
	else {
		D->rear = (D->rear + 1) % N;
		D->deque[D->rear] = e;
	}
}

element deleteFront(DequeType* D) {//dequeue
	if (isEmpty(D)) {
		printf("Empty!\n");
		return 0;
	}

	D->front = (D->front + 1) % N;
	return D->deque[D->front];
}

element deleteRear(DequeType* D) {
	if (isEmpty(D)) {
		printf("Empty!\n");
		return 0;
	}

	int pos = D->rear;
	D->rear = (D->rear - 1 + N) % N;
	return D->deque[pos];
}

element getFront(DequeType* D) {//dequeue
	if (isEmpty(D)) {
		printf("Empty!\n");
		return 0;
	}
	return D->deque[(D->front + 1) % N];
}

element getRear(DequeType* D) {
	if (isEmpty(D)) {
		printf("Empty!\n");
		return 0;
	}

	return D->deque[D->rear];
}

int peek(DequeType* D) {
	if (isEmpty(D)) {
		printf("Empty!\n");
		return 0;
	}
	return D->deque[(D->front + 1) % N];
}

void print(DequeType* D) {
	printf("Front : %d, Rear : %d\n", D->front, D->rear);

	if (isEmpty(D)) {
		printf("Deque is Empty\n");
		return;
	}

	int i = D->front;
	while (i != D->rear) {
		i = (i + 1) % N;
		printf("[%c]", D->deque[i]);
	}
	printf("\n");
}

int main(void) {
	DequeType D;
	init(&D);
	//알아서 잘 써보기
	addFront(&D, 'A');
	addFront(&D, 'B');
	addRear(&D, '1');
	addRear(&D, '2');
	deleteFront(&D);
	deleteRear(&D);
	print(&D);

}
