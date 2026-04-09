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
	return L->size == 0;
}




int main(void) {
	


	return 0;
}
