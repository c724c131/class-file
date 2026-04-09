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

int isEmpty(ListType* L) {//isFull은 필요없지만 이건 필요
	return L->size == 0;
}

Node* makeNode(element e) {//메모리 할당시 받는 주소를 이용
	Node* node = (Node*)malloc(sizeof(Node));//엄밀히 하려면 여기서 NULL 체크
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

element deleteFirst(ListType* L) {
	if (isEmpty(L)) {
		printf("Empty\n");
		return '\0'; //또는 0 또는 exit
	}

	Node* p = L->head;
	element data = p->data;
	L->head = p->next; //이제 p는 없어도 된다
	free(p);
	L->size--;

	return data;
}

void insert(ListType* L, element e, int pos) {
	if (pos <= 0 || pos > L->size + 1) {
		printf("Invaild Position");
		return 0;
	}

		if (pos == 1)
			insertFirst(L, e);
		else {
			Node* node = makeNode(e);
			Node* p = L->head; //가야할 포지션 값의 -2 만큼만 움직여야한다.

			for (int i = 2;i < pos;i++) {
				p = p->next;
			}
			node->next = p->next;
			p->next = node;
			L->size++;
		}
}

void print(ListType* L) {
	Node* p = L->head;

	while (p != NULL) {
		printf("[%c]", p->data);
		if (p->next != NULL)
			printf("->"); //보기 좋은 화살표
		p = p->next; //포인터 이동
	}
	printf("\n");
};

element deletePosition(ListType* L, int pos) {
	if (isEmpty(L)) {
		printf("Empty\n");
		return '\0';
	}

	if (pos <= 0 || pos > L->size + 1) {
		printf("Invaild Position");
		return '\0';
	}
	if (pos == 1)
		deleteFirst(L);

	Node* p = L->head;
	for (int i = 2;i < pos;i++) {
		p = p->next;
	}

	Node* temp = p->next;
	element data = temp->data;
	p->next = temp->next;
	free(temp);
	L->size--;

	return data;
}

int main(void) {
	ListType L;
	init(&L);

	insertFirst(&L,'A');
	insertFirst(&L,'B');
	insertFirst(&L,'C');
	insertFirst(&L, 'D');

	insert(&L, 'I', 4);
	insert(&L, 'K', 3);

	print(&L);
	printf("Del : [%c]\n", deleteFirst(&L));
	print(&L);
	printf("Del : [%c]\n", deletePosition(&L, 2));
	print(&L);

	return 0;
}
