#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct Node {//노드 하나
	element data;
	struct Node* prev;//이전 노드
	struct Node* next;//자기 참조 구조체 : Node 안에서 Node 참조
}Node; //자기 참조를 하려면 구조체 테그를 생략하면 안된다.

typedef struct {//이중 연결 리스트
	Node* head; //헤드 노드
	Node* tail; //테일 노드
	Node* cursor; //커서 추가
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
	DL->cursor = makeNode('|'); // | 문자가 들어간 커서 만들기

	//head 와 tail 사이에 cursosr
	DL->head->next = DL->cursor; 
	DL->tail->prev = DL->cursor;
	DL->cursor->next = DL->tail;
	DL->cursor->prev = DL->head;
	
	DL->size = 1; //커서가 있으니 크기는 1
};

int isEmpty(DListType* DL) {//isFull은 필요없지만 이건 필요
	return DL->size == 0;
}

void insertChar(DListType* DL, char c) {//커서 왼쪽에 문자 삽입
	Node* node = makeNode(c); //받은 문자 노드 생성
	node->prev = DL->cursor->prev; //커서의 왼쪽 노드 주소를 주고
	node->next = DL->cursor; //입력된 문자의 오른쪽은 커서 본인
	DL->cursor->prev->next = node; //커서의 왼쪽에 있던 노드와 입력된 문자열 연결
	DL->cursor->prev = node; //커서의 왼쪽은 입력된 문자열
}

void moveLeft(DListType* DL) {//커서 왼쪽 이동
	if (DL->cursor->prev == DL->head) {//커서 왼쪽이 head 라면
		printf("Cursor can't move left\n"); //이동 불가
		return;
	}
	//만약 헤드가 아니라면 왼쪽문자와 자리 바꾸기
	Node* node = DL->cursor->prev; //커서의 왼쪽문자

	node->prev->next = DL->cursor; //노드의 왼쪽에 있던 문자가 커서를 가르킴
	DL->cursor->next->prev = node; //커서의 오른쪽에 있던 문자가 노드를 가르킴

	node->next = DL->cursor->next; //노드의 다음문자는 커서 뒤에있는 문자로
	DL->cursor->prev = node->prev; //커서의 왼쪽문자는 이제 노드의 왼쪽문자
	node->prev = DL->cursor; //노드는 이제 커서 뒤에
	DL->cursor->next = node; //커서는 이제 노드 앞에
}

void moveRight(DListType* DL) {//커서 오른쪽 문자와 자리바꾸기
	if (DL->cursor->next == DL->tail) {//커서 오른쪽이 tail 이라면
		printf("Cursor can't move right\n"); //이동 불가
		return;
	}
	//moveright와 반대로 작성
	Node* node = DL->cursor->next; //커서의 오른쪽문자

	node->next->prev = DL->cursor; //노드의 오른쪽에 있던 문자가 커서를 가르킴
	DL->cursor->prev->next = node; //커서의 왼쪽에 있던 문자가 노드를 가르킴

	node->prev = DL->cursor->prev; //노드의 왼쪽 문자는 커서 왼쪽에 있는 문자로
	DL->cursor->next = node->next; //커서의 오른쪽문자는 이제 노드의 오른쪽문자
	node->next = DL->cursor; //노드는 이제 커서 앞에
	DL->cursor->prev = node; //커서는 이제 노드 뒤에
}

void deleteChar(DListType* DL) {//커서 왼쪽 문자 삭제
	if (DL->cursor->prev == DL->head) {//커서 왼쪽에 문자가 없다면
		printf("There is no Char to delete"); //삭제 불가
		return;
	}

	Node* node = DL->cursor->prev; //커서 왼쪽 문자;
	DL->cursor->prev = node->prev; //커서 앞에 노드의 왼쪽 문자
	node->prev->next = DL->cursor; //노드 왼쪽 문자 오른쪽에 커서
	free(node); //노드 삭제
}

void printText(DListType* DL) {//이중 연결 리스트의 print 이름만 바꿔서 그대로 사용
	for (Node* p = DL->head->next; p != DL->tail; p = p->next) {//head는 값이 없는 노드로 그 다음 노드부터 값 출력
		printf("%c", p->data);
	}
	printf("\n");
}

int main(void) {
	DListType DL;
	init(&DL);
	
	char input[100];
	printf("Input : ");
	fgets(input, sizeof(input), stdin); //문자열 받기
	printf("\n처리 과정\n");

	for (int i = 0; input[i] != '\n'; i++) {//fgets 엔터까지 반복
		if (input[i] == '<') {//커서 왼쪽으로
			moveLeft(&DL);
			printf("%c -> ", input[i]); //중간 과정 출력
			printText(&DL);
		}

		else if (input[i] == '>') {//커서 오른쪽으로
			moveRight(&DL);
			printf("%c -> ", input[i]);
			printText(&DL);
		}

		else if(input[i] == '-') {//문자 삭제
			deleteChar(&DL);
			printf("%c -> ", input[i]);
			printText(&DL);
		}

		else {//나머지는 문자삽입
			insertChar(&DL, input[i]);
			printf("%c -> ", input[i]);
			printText(&DL);
		}
	}

	printf("\n결과\n");
	printText(&DL);

	return 0;
}
