#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct Node {
	element data;
	struct Node* prev;//이전 노드
	struct Node* next;//자기 참조 구조체 : Node 안에서 Node 참조
}Node; //자기 참조를 하려면 구조체 테그를 생략하면 안된다.

typedef struct {
	Node* head;
	Node* tail;
	int size;
}DListType;

Node* makeNode(element e) {//이중 연결 리스트는 init 이전에 노드가 있어야 한다.
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = e;
	node->prev = node->next = NULL;

	return node;
}

void init(DListType* DL) {
	DL->head = makeNode(0);//아무값이나
	DL->tail = makeNode(0);

	DL->head->next = DL->tail;
	DL->tail->prev = DL->head;
	DL->size = 0;
};

int isEmpty(DListType* DL) {//isFull은 필요없지만 이건 필요
	return DL->size == 0;
}

void insertFirst(DListType* DL, element e) {
	Node* p = DL->tail;
	Node* node = makeNode(e);

	node->prev = p->prev;
	node->next = p;
	p->prev->next = node;
	p->prev = node;
	
	DL->size++;
}

void insert(DListType* DL, element e, int pos) {
	if (pos <= 0 || pos > DL->size + 1) {
		printf("Invaild Position.\n");
		return;
	}

	Node* p = DL->head;
	for (int i = 1; i < pos; i++) {
		p = p->next;
	}

	Node* node = makeNode(e);
	//최대한 p를 사용 --- 수정필요
	node->prev = p;
	node->next = p;
	p->prev->next = node;
	p->prev = node;

	DL->size++;
}

element delete(DListType* DL, int pos) {
	if (isEmpty(DL)) {
		printf("Empty!.\n");
		return 0;
	}

	if (pos <= 0 || pos > DL->size + 1) {
		printf("Invaild Position.\n");
		return 0;
	}

	Node* p = DL->head;
	for (int i = 1; i < pos; i++) {
		p = p->next;
	}

	element data = p->data;

	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
	DL->size--;
	return data;
}

void print(DListType* DL) {
	for (Node* p = DL->head->next;p != DL->tail;p = p->next) {
		printf("[%c]", p->data);
		if (p->next != DL->tail)
			printf("<->");
	}
	printf("\n");
}

int main(void) {
	
	DListType* DL;
	init(&DL);

	insert(&DL, 'A', 1);print(&DL);
	insert(&DL, 'A', 2);print(&DL);
	insert(&DL, 'A', 3);print(&DL);
	insert(&DL, 'A', 4);print(&DL);
	insert(&DL, 'A', 5);print(&DL);
	insert(&DL, 'A', 6);print(&DL);
	return 0;
}

//자료구조 책에 있는거 구현 리버스나 다른거 등등
