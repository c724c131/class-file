#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct Node {
	element data;
	struct Node* next;//자기 참조 구조체 : Node 안에서 Node 참조
}Node; //자기 참조를 하려면 구조체 테그를 생략하면 안된다.

typedef struct {
	Node* head;
	int size;
}ListType;

void init(ListType* L) {
	L->head = NULL; //포인터 변수는 NULL로 초기화
	L->size = 0;
};

Node* makeNode(element e) {//메모리 할당시 받는 주소를 이용
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = e;
	node->next = NULL;

	return node;
}

//head 유치원 선생님같은것
void insertFirst(ListType* L, element e) {
	Node* node = makeNode(e);
	node->next = L->head; //선생님이 잡고있던 애를 잡기
	L->head = node; //선생님은 방금 들어온 애 잡기
	L->size++;
}

int main(void) {
	ListType L;
	init(&L);

	insertFirst(&L,'A');
	insertFirst(&L,'B');
	return 0;
}
